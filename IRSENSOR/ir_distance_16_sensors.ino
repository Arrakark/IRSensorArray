//Line following and Ewok Grabbing with 16 IR sensors on Blue Pill Board

#include <Wire.h>
#include <ADS7828.h>
#include <Arduino.h>
#include <IRDIST.h>

#define S_LEN_UNIT 8

#define ROW 20
#define COL 9
#define DIST_COL 0

//---------------------------------------------

//thresholds
double std_w_avg = 8.5; //standard weighted average for 16 IR sensors
int cut_off_dist = 30;

//sensor arrays (for 1 sensor unit: left most, idx = 0; right most, idx = 7)

int s_val_1[S_LEN_UNIT];
int s_val_2[S_LEN_UNIT];

//array of distances

int dist_raw_1[S_LEN_UNIT];
int dist_calib_1[S_LEN_UNIT];

int dist_raw_2[S_LEN_UNIT];
int dist_calib_2[S_LEN_UNIT];

//data file arrays
const PROGMEM int data_1[ROW][COL] = { {1, 131, 125, 134, 132, 129, 133, 135, 140},
  {3, 140, 134, 145, 143, 140, 143, 149, 150},
  {5, 150, 145, 155, 151, 147, 152, 157, 159},
  {7, 160, 156, 163, 159, 156, 160, 165, 168},
  {10, 174, 169, 176, 170, 166, 171, 176, 179},
  {12, 182, 177, 183, 176, 172, 177, 184, 187},
  {15, 196, 188, 196, 188, 182, 188, 195, 198},
  {17, 207, 195, 205, 196, 189, 195, 204, 206},
  {20, 227, 207, 222, 210, 200, 206, 218, 219},
  {23, 373, 229, 277, 243, 220, 225, 255, 251},
  {25, 417, 237, 337, 268, 229, 235, 281, 267},
  {28, 629, 305, 613, 527, 291, 301, 551, 489},
  {30, 768, 429, 764, 703, 445, 459, 745, 685},
  {33, 856, 540, 900, 860, 601, 617, 883, 818},
  {36, 960, 659, 1038, 1014, 757, 779, 1038, 971},
  {39, 1029, 736, 1131, 1122, 866, 891, 1142, 1077},
  {42, 1081, 785, 1198, 1202, 947, 976, 1223, 1155},
  {44, 1097, 809, 1227, 1236, 981, 1015, 1255, 1188},
  {46, 1092, 810, 1233, 1247, 991, 1026, 1258, 1192},
  {50, 1156, 889, 1314, 1337, 1081, 1123, 1351, 1291}
};

int data_3[ROW][COL] = { {1, 139, 136, 144, 132, 133, 134, 138, 145},
  {3, 145, 144, 152, 140, 140, 141, 145, 151},
  {5, 156, 154, 161, 150, 149, 152, 155, 161},
  {7, 166, 163, 172, 158, 158, 161, 165, 172},
  {10, 185, 177, 189, 170, 170, 174, 180, 187},
  {12, 200, 188, 206, 179, 179, 184, 192, 199},
  {15, 238, 204, 253, 190, 191, 198, 211, 218},
  {17, 462, 225, 604, 203, 203, 213, 239, 248},
  {20, 842, 369, 11085, 231, 231, 255, 476, 481},
  {23, 1106, 662, 1416, 364, 358, 510, 804, 757},
  {25, 1217, 792, 1563, 537, 531, 679, 950, 880},
  {28, 1399, 992, 1767, 786, 784, 923, 1165, 1070},
  {30, 1487, 1095, 1871, 925, 927, 1062, 1289, 1179},
  {33, 1569, 1189, 1973, 1059, 1064, 1192, 1398, 1273},
  {36, 1720, 1344, 2102, 1224, 1229, 1351, 1549, 1414},
  {39, 1786, 1417, 2175, 1323, 1329, 1448, 1638, 1496},
  {42, 1870, 1504, 2253, 1424, 1429, 1548, 1730, 1584},
  {44, 1968, 1603, 2337, 1528, 1537, 1648, 1827, 1679},
  {46, 2080, 1715, 2434, 1651, 1661, 1770, 1947, 1795},
  {50, 2200, 1839, 2531, 1779, 1788, 1893, 2068, 1917}
};

const PROGMEM int data_4[ROW][COL] = { {1, 137, 126, 124, 120, 126, 124, 136, 136},
  {3, 152, 138, 137, 131, 140, 135, 151, 146},
  {5, 169, 148, 148, 142, 151, 146, 161, 161},
  {7, 184, 158, 155, 150, 159, 154, 171, 171},
  {10, 243, 177, 169, 161, 172, 167, 192, 188},
  {12, 702, 195, 180, 170, 182, 177, 217, 203},
  {15, 1259, 273, 200, 184, 199, 193, 595, 254},
  {17, 1612, 728, 241, 199, 223, 212, 1091, 605},
  {20, 1878, 1139, 627, 231, 424, 312, 1525, 1005},
  {23, 2099, 1447, 1017, 449, 800, 690, 1829, 1306},
  {25, 2182, 1587, 1214, 668, 1002, 909, 1992, 1466},
  {28, 2354, 1818, 1505, 985, 1287, 1213, 2225, 1711},
  {30, 2442, 1944, 1673, 1167, 1452, 1392, 2355, 1849},
  {33, 2504, 2039, 1803, 1312, 1586, 1538, 2461, 1967},
  {36, 2611, 2173, 1969, 1490, 1747, 1712, 2594, 2121},
  {39, 2694, 2283, 2107, 1638, 1880, 1856, 2704, 2254},
  {42, 2752, 2358, 2205, 1746, 1979, 1965, 2786, 2354},
  {44, 2792, 2379, 2234, 1778, 2007, 1996, 2801, 2373},
  {46, 2761, 2384, 2246, 1794, 2002, 2016, 2816, 2393},
  {50, 2805, 2440, 2320, 1874, 2096, 2098, 2877, 2469}
};

int data_5[ROW][COL] = { {1, 137, 127, 124, 128, 131, 131, 138, 145},
  {3, 144, 135, 133, 136, 140, 137, 147, 153},
  {5, 157, 145, 145, 144, 149, 147, 154, 164},
  {7, 169, 154, 153, 152, 156, 154, 161, 172},
  {10, 196, 171, 167, 165, 169, 167, 176, 187},
  {12, 244, 182, 176, 173, 178, 177, 186, 200},
  {15, 875, 204, 192, 189, 195, 194, 207, 238},
  {17, 1227, 236, 210, 204, 216, 212, 236, 455},
  {20, 1568, 495, 271, 243, 319, 280, 507, 864},
  {23, 1745, 746, 541, 473, 676, 629, 849, 1138},
  {25, 1866, 906, 732, 689, 895, 855, 1051, 1304},
  {28, 2013, 1102, 967, 953, 1162, 1132, 1310, 1525},
  {30, 2126, 1239, 1129, 1129, 1340, 1313, 1482, 1677},
  {33, 2248, 1392, 1307, 1325, 1536, 1512, 1678, 1850},
  {36, 2329, 1496, 1436, 1467, 1678, 1660, 1816, 1972},
  {39, 2126, 1607, 1558, 1598, 1806, 790, 1942, 2084},
  {42, 2473, 1670, 1637, 1685, 1894, 1882, 2036, 2172},
  {44, 2520, 1724, 1700, 1752, 1961, 1951, 2102, 2233},
  {46, 2559, 1771, 1752, 1809, 2019, 2011, 2162, 2291},
  {50, 2616, 1843, 1836, 1898, 2107, 2100, 2254, 2378}
};

//constructors
ADS7828 adc1(0x48); //chip id 1 and 5
ADS7828 adc2(0x4B);

//functions
void read_sensor_values(int arr[S_LEN_UNIT], ADS7828 adc);
void printArray (int arr[], int lengthsize);
int* arr_rel_dist(int arr[S_LEN_UNIT], int arr_new_dist[S_LEN_UNIT], int thres);
double w_avg(int arr[S_LEN_UNIT], int horz_shift);
double avg(int arr[S_LEN_UNIT]);
int min_value(int arr[S_LEN_UNIT]);
int max_value(int arr[S_LEN_UNIT]);
double mean_range(int arr[S_LEN_UNIT]);

//--------------------------------------------------------

void setup() {
  Wire.begin();

  Serial.begin(115200);
}

void loop() {

  //  IRDIST sensor_1(dist_raw_1, data_1, s_val_1);
  //  read_sensor_values(s_val_1, adc1);
  //  int *dist_1_pid = sensor_1.readDist(dist_raw_1, s_val_1, data_1);
  //  int *dist_1_ewok = arr_rel_dist(dist_1_pid, dist_calib_1, cut_off_dist);
  //
  //  printArray(dist_1_pid, S_LEN_UNIT);
  //  printArray(dist_1_ewok, S_LEN_UNIT);
  //  Serial.print("Ewok Centering 1: ");
  //  Serial.println(w_avg(dist_1_ewok, 0)); //for ewok and edge detection

  //  IRDIST sensor_2(dist_raw_2, data_5, s_val_2);
  //  read_sensor_values(s_val_2, adc2);
  //  int *dist_2_pid = sensor_2.readDist(dist_raw_2, s_val_2, data_4);
  //  int *dist_2_ewok = arr_rel_dist(dist_raw_2, dist_calib_2, cut_off_dist);
  //
  //  printArray(dist_2_pid, S_LEN_UNIT);
  //  printArray(dist_2_ewok, S_LEN_UNIT);
  //  Serial.print("Ewok Centering 2: ");
  //  Serial.println(w_avg(dist_2_ewok, 8)); //for ewok and edge detection
  //
  //  Serial.println((w_avg(dist_2_ewok, 8) + w_avg(dist_1_ewok, 0)) / 2);
  
//  int i, j;
//  for (i = 0; i < ROW; i++) {
//    for (j = 0; j < COL; j++) {
//      Serial.print(pgm_read_word_near(&(data_1[i][j])));
//      Serial.print(" ");
//    }
//    Serial.println();
//  }

  Serial.println();
}

//--------------------------------------------------------
void printArray (int arr[], int lengthsize) {

  int i;
  for (i = 0; i < lengthsize; i ++) {
    Serial.print(arr[i]);
    Serial.print(" ");
  }

  Serial.println();
}

void read_sensor_values(int arr[S_LEN_UNIT], ADS7828 adc) {

  int i;

  for (i = 0; i < S_LEN_UNIT; i ++)
    arr[i] = adc.read(i, SD);
}

//----------------

int* arr_rel_dist(int arr[S_LEN_UNIT], int arr_new_dist[S_LEN_UNIT], int thres) {

  int i;

  for (i = 0; i < S_LEN_UNIT; i ++)
    arr_new_dist[i] = thres - arr[i];

  return arr_new_dist;
}

//----------------

double w_avg(int arr[S_LEN_UNIT], int horz_shift) {

  int i;
  float weighted_sum = 0;
  float sum = 0;

  for (i = 0; i < S_LEN_UNIT; i++) {

    weighted_sum += (i + 1 + horz_shift) * arr[i]; //1st arr horz_shift = 0; 2nd arr horz_shift = 8
    sum += arr[i];
  }

  return weighted_sum / sum;
}

//----------------

double avg(int arr[S_LEN_UNIT]) {

  int i;
  double sum = 0;

  for (i = 0; i < S_LEN_UNIT; i++)
    sum += arr[i];

  return sum / S_LEN_UNIT;
}

//----------------

int min_value(int arr[S_LEN_UNIT]) {

  int i;
  int min_val = arr[0];

  for (i = 1; i < S_LEN_UNIT; i++) {

    if (arr[i] < min_val)
      min_val = arr[i];
  }

  return min_val;
}

//----------------

int max_value(int arr[S_LEN_UNIT]) {

  int i;
  int max_val = arr[0];

  for (i = 1; i < S_LEN_UNIT; i++) {

    if (arr[i] > max_val)
      max_val = arr[i];
  }

  return max_val;
}

//----------------

double mean_range(int arr[S_LEN_UNIT]) {

  return ((double)(max_value(arr)) - min_value(arr)) / 2;
}

//----------------



