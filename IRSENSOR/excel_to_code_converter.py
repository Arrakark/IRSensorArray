import sys
# Code for taking the calibration inputs from excel or Google sheets and turning it into a 2D array for C++
# takes something like:
# 1 131 125 134 120 ...
# 3 140 134 145 137 ...
# 5 150 145 155 147 ...
#
# and turns it into this:
# int lookup_table[20][9] = {{1, 131, 125, 134, 120, 116, 122, 120, 148},
#                            {3, 140, 134, 145, 137, 136, 139, 143, 157},
#                            {5, 150, 145, 155, 147, 144, 150, 155, 171},
#                            {7, 160, 156, 163, 156, 152, 158, 163, 185},
#                            {10, 174, 169, 176, 169, 165, 171, 177, 231},
#                            {12, 182, 177, 183, 179, 174, 180, 189, 1272},
#                            {15, 196, 188, 196, 198, 189, 197, 513, 1615},
#                            {17, 207, 195, 205, 217, 201, 211, 240, 1966},
#                            {20, 227, 207, 222, 441, 240, 275, 576, 2171},
#                            {23, 373, 229, 277, 876, 520, 655, 940, 2284},
#                            {25, 417, 237, 337, 1115, 761, 896, 1143, 2406},
#                            {28, 629, 305, 613, 1400, 1057, 1193, 1406, 2515},
#                            {30, 768, 429, 764, 1587, 1251, 1387, 1580, 2545},
#                            {33, 856, 540, 900, 1688, 1363, 1499, 1673, 2622},
#                            {36, 960, 659, 1970, 1850, 1531, 1669, 1833, 1809},
#                            {39, 1029, 736, 2085, 1984, 1670, 1812, 1966, 1944},
#                            {42, 1081, 785, 2183, 2094, 1783, 1927, 2077, 2058},
#                            {44, 1097, 809, 2233, 2157, 1847, 1990, 2140, 2123},
#                            {46, 1098, 810, 2283, 2211, 1908, 2051, 2202, 2187},
#                            {50, 1159, 889, 2382, 2321, 2020, 2168, 2318, 2303}};

number_of_rows = 20
string = []
values = []

#take the input in (simply copy and paste the data without headers and press enter)
for x in range(0,number_of_rows,1):
    string.append(input())

#split values and move to int array
for x in range(0,number_of_rows,1):
    #string[x].strip()
    row = string[x].split('\t')
    values.append(row)

number_of_cols = values[0].__len__()

sys.stdout.write("int lookup_table[" + str(number_of_rows) + "][" + str(number_of_cols) + "] = ")
sys.stdout.write("{")
for x in range(0,number_of_rows,1):
    sys.stdout.write("{")
    for y in range(0, number_of_cols, 1):
        sys.stdout.write(values[x][y])
        if y != number_of_cols - 1:
            sys.stdout.write(",")
    print("}")
    if x != number_of_rows- 1:
            sys.stdout.write(",")
print("}")

string = string
