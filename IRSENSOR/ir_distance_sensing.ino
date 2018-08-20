//Line follower with 8 IR sensors on Blue Pill Board

#include<stdio.h>
#include <Wire.h>
#include <ADS7828.h>
ADS7828 adc(0x48);


#define SENSE_NUM 8

#define ROW 20
#define COL 9
#define DIST_COL 0

//---------------------------------------------

//sensor values -> left most, idx = 0; right most, idx = 7
unsigned int s_value[SENSE_NUM] = {0,0,0,0,0,0,0,0};

//array of distances                                  
int dist_arr[SENSE_NUM];

//make new data file array for testing *******
int data_arr[ROW][COL] = { {1,122,118,123,120,116,122,120,127},
                           {3,137,128,138,137,136,139,143,145},
                           {5,147,140,151,147,144,150,155,157},
                           {7,158,151,159,156,152,158,163,167},
                           {10,177,168,175,169,165,171,177,182},
                           {12,196,181,188,179,174,180,189,193},
                           {15,331,204,215,198,189,197,513,219},
                           {17,686,230,262,217,201,211,240,250},
                           {20,1110,533,764,441,240,275,576,603},
                           {23,1377,859,1147,876,520,655,940,940},
                           {25,1524,1307,1355,1115,761,896,1143,1128},
                           {28,1688,1235,1591,1400,1057,1193,1406,1385},
                           {30,1811,1382,1752,1587,1251,1387,1580,1559},
                           {33,1841,1430,1827,1688,1363,1499,1673,1652},
                           {36,1967,1567,1970,1850,1531,1669,1833,1809},
                           {39,2062,1675,2085,1984,1670,1812,1966,1944},
                           {42,2151,1771,2183,2094,1783,1927,2077,2058},
                           {44,2195,1819,2233,2157,1847,1990,2140,2123},
                           {46,2244,1871,2283,2211,1908,2051,2202,2187},
                           {50,2342,1971,2382,2321,2020,2168,2318,2303} };

//functions
void read_sensor_values(void);
void printArray (int arr[], int lengthsize);
int* calculate_distance(int arr[SENSE_NUM],int sensor[SENSE_NUM],int data[ROW][COL]);
//some function that returns 2D array from file

//--------------------------------------------------------
void setup() {

  Serial.begin(9600);
  
  adc.init(INT);
}

void loop() {
  
  read_sensor_values();
  //printArray(s_value,SENSE_NUM);
  //Serial.println();
  int *dist_arr_pointer = calculate_distance(dist_arr,s_value,data_arr);
  //printArray(dist_arr_pointer,SENSE_NUM);
  
}

//--------------------------------------------------------

void read_sensor_values() {

  int i;
  
  for(i = 0; i < SENSE_NUM; i ++){
    s_value[i] = adc.read(i,SD);
  }
}

void printArray (int arr[], int lengthsize){

  int i;
  for(i = 0; i < lengthsize; i ++){
    Serial.print(arr[i]);
    Serial.print(" ");
  }

  Serial.println();
}

int* calculate_distance(int arr[SENSE_NUM],int sensor[SENSE_NUM],int data[ROW][COL]) {

  int ind = 0; //indices in data array
  int flag = 0; //boolean used for calculating distance
  int distance = 0;

  int i,j;

  //calculating distances measured in sensor array
  for(i = 0; i < SENSE_NUM; i ++) {

    //find corresponding indices in data array
    for(j = 0; j < ROW; j ++) {

      if(data[j][i+1] >= sensor[i]){
        
        ind = j;
        flag = 1;
        break;
      }
    }

    //calculate distance
    
    if(!flag) //if sensor measured distance is greater than values in data array, let sensor distance = 100
      arr[i] = 100;

    else {

      //calculating slope and y-intercpet : y = mx + b
      int x2 = data[ind][i+1];
      int y2 = data[ind][DIST_COL];

      Serial.print("x2: ");
      Serial.print(x2);
      Serial.print(" ");
      Serial.print("y2: ");
      Serial.print(y2);
      Serial.println();

      int x1 = data[ind-1][i+1];
      int y1 = data[ind-1][DIST_COL];

      Serial.print("x1: ");
      Serial.print(x1);
      Serial.print(" ");
      Serial.print("y1: ");
      Serial.print(y1);
      Serial.println();

      float m = ((float)(y2 - y1)) / (x2 - x1);
      float b = y2 - m * x2;

      float ans = m * sensor[i] + b;
      arr[i] = (int)(m * sensor[i] + b);

      Serial.print("sensor");
      Serial.print(i);
      Serial.print(": ");
      Serial.print(sensor[i]);
      Serial.print(" ");
      Serial.print("distance: ");
      Serial.print(arr[i]);
      Serial.print(" m: ");
      Serial.print(m);
      Serial.print(" b: ");
      Serial.print(b);
      Serial.print(" ans: ");
      Serial.print(ans);
      Serial.println();
      Serial.println();
    }
  }


  
//  arr[0] = 1;
//  arr[1] = 2;
//  arr[2] = 3;
//  arr[3] = 4;
//  arr[4] = 5;
//  arr[5] = 6;
//  arr[6] = 7;
//  arr[7] = 8;

  return arr;
}

