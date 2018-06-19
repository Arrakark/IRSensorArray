EESchema Schematic File Version 4
LIBS:IRSensorArray-cache
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 9
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Analog_ADC:ADS7828 U1
U 1 1 5B22BD62
P 5550 2650
F 0 "U1" H 5250 3300 50  0000 C CNN
F 1 "ADS7828" H 5150 3400 50  0000 C CNN
F 2 "Housings_SSOP:TSSOP-16_4.4x5mm_Pitch0.65mm" H 6500 1950 50  0001 C CNN
F 3 "http://www.ti.com/lit/ds/symlink/ads7828.pdf" H 5550 2650 50  0001 C CNN
	1    5550 2650
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 5B22CCCA
P 2950 2000
F 0 "JP1" V 3000 2200 50  0000 C CNN
F 1 "SB_0" V 2900 2200 50  0000 C CNN
F 2 "footprints:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 2950 2000 50  0001 C CNN
F 3 "~" H 2950 2000 50  0001 C CNN
	1    2950 2000
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP3
U 1 1 5B22CD87
P 3800 2000
F 0 "JP3" V 3850 2200 50  0000 C CNN
F 1 "SB_1" V 3750 2200 50  0000 C CNN
F 2 "footprints:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 3800 2000 50  0001 C CNN
F 3 "~" H 3800 2000 50  0001 C CNN
	1    3800 2000
	0    1    1    0   
$EndComp
$Comp
L Jumper:SolderJumper_3_Open JP2
U 1 1 5B22CEA8
P 3450 3750
F 0 "JP2" V 3500 4000 50  0000 C CNN
F 1 "REF_5V" V 3400 4000 50  0000 C CNN
F 2 "footprints:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" H 3450 3750 50  0001 C CNN
F 3 "~" H 3450 3750 50  0001 C CNN
	1    3450 3750
	0    1    1    0   
$EndComp
$Comp
L Device:C C4
U 1 1 5B22D6A1
P 8700 3250
F 0 "C4" H 8815 3296 50  0000 L CNN
F 1 "100nF" H 8815 3205 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.1mm_W3.2mm_P5.00mm" H 8738 3100 50  0001 C CNN
F 3 "~" H 8700 3250 50  0001 C CNN
	1    8700 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5B22D7EA
P 8250 3250
F 0 "C3" H 8368 3296 50  0000 L CNN
F 1 "1uF" H 8368 3205 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D4.0mm_P2.00mm" H 8288 3100 50  0001 C CNN
F 3 "~" H 8250 3250 50  0001 C CNN
	1    8250 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5B22D97A
P 7800 3250
F 0 "C2" H 7918 3296 50  0000 L CNN
F 1 "10uF" H 7918 3205 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D5.0mm_P2.00mm" H 7838 3100 50  0001 C CNN
F 3 "~" H 7800 3250 50  0001 C CNN
	1    7800 3250
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5B22DA56
P 3000 4050
F 0 "C1" H 3118 4096 50  0000 L CNN
F 1 "0.1uF" H 3118 4005 50  0000 L CNN
F 2 "Capacitors_THT:C_Disc_D5.1mm_W3.2mm_P5.00mm" H 3038 3900 50  0001 C CNN
F 3 "~" H 3000 4050 50  0001 C CNN
	1    3000 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5B22DC0E
P 6050 1900
F 0 "R1" H 6120 1946 50  0000 L CNN
F 1 "10k0" H 6120 1855 50  0000 L CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 5980 1900 50  0001 C CNN
F 3 "~" H 6050 1900 50  0001 C CNN
	1    6050 1900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5B22DC9A
P 6450 1900
F 0 "R2" H 6520 1946 50  0000 L CNN
F 1 "10k0" H 6520 1855 50  0000 L CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical" V 6380 1900 50  0001 C CNN
F 3 "~" H 6450 1900 50  0001 C CNN
	1    6450 1900
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5B22DD28
P 8700 2450
F 0 "#PWR0101" H 8700 2200 50  0001 C CNN
F 1 "GND" H 8705 2277 50  0000 C CNN
F 2 "" H 8700 2450 50  0001 C CNN
F 3 "" H 8700 2450 50  0001 C CNN
	1    8700 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0102
U 1 1 5B22DDA3
P 8700 1850
F 0 "#PWR0102" H 8700 1700 50  0001 C CNN
F 1 "+5V" H 8715 2023 50  0000 C CNN
F 2 "" H 8700 1850 50  0001 C CNN
F 3 "" H 8700 1850 50  0001 C CNN
	1    8700 1850
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5B22E2FB
P 3450 3400
F 0 "#PWR0103" H 3450 3250 50  0001 C CNN
F 1 "+5V" H 3465 3573 50  0000 C CNN
F 2 "" H 3450 3400 50  0001 C CNN
F 3 "" H 3450 3400 50  0001 C CNN
	1    3450 3400
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5B22E33C
P 3800 1650
F 0 "#PWR0104" H 3800 1500 50  0001 C CNN
F 1 "+5V" H 3815 1823 50  0000 C CNN
F 2 "" H 3800 1650 50  0001 C CNN
F 3 "" H 3800 1650 50  0001 C CNN
	1    3800 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0105
U 1 1 5B22E37D
P 2950 1650
F 0 "#PWR0105" H 2950 1500 50  0001 C CNN
F 1 "+5V" H 2965 1823 50  0000 C CNN
F 2 "" H 2950 1650 50  0001 C CNN
F 3 "" H 2950 1650 50  0001 C CNN
	1    2950 1650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5B22E3BE
P 2950 2350
F 0 "#PWR0106" H 2950 2100 50  0001 C CNN
F 1 "GND" H 2955 2177 50  0000 C CNN
F 2 "" H 2950 2350 50  0001 C CNN
F 3 "" H 2950 2350 50  0001 C CNN
	1    2950 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0107
U 1 1 5B22E3FF
P 3800 2350
F 0 "#PWR0107" H 3800 2100 50  0001 C CNN
F 1 "GND" H 3805 2177 50  0000 C CNN
F 2 "" H 3800 2350 50  0001 C CNN
F 3 "" H 3800 2350 50  0001 C CNN
	1    3800 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 5B22E440
P 3000 4300
F 0 "#PWR0108" H 3000 4050 50  0001 C CNN
F 1 "GND" H 3005 4127 50  0000 C CNN
F 2 "" H 3000 4300 50  0001 C CNN
F 3 "" H 3000 4300 50  0001 C CNN
	1    3000 4300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 5B22F0D8
P 5550 3600
F 0 "#PWR0109" H 5550 3350 50  0001 C CNN
F 1 "GND" H 5555 3427 50  0000 C CNN
F 2 "" H 5550 3600 50  0001 C CNN
F 3 "" H 5550 3600 50  0001 C CNN
	1    5550 3600
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0110
U 1 1 5B22F119
P 5550 1850
F 0 "#PWR0110" H 5550 1700 50  0001 C CNN
F 1 "+5V" H 5565 2023 50  0000 C CNN
F 2 "" H 5550 1850 50  0001 C CNN
F 3 "" H 5550 1850 50  0001 C CNN
	1    5550 1850
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 5B22F15A
P 4950 3600
F 0 "#PWR0111" H 4950 3350 50  0001 C CNN
F 1 "GND" H 4955 3427 50  0000 C CNN
F 2 "" H 4950 3600 50  0001 C CNN
F 3 "" H 4950 3600 50  0001 C CNN
	1    4950 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5550 1950 5550 1850
Wire Wire Line
	5550 3600 5550 3450
Wire Wire Line
	5950 2650 6250 2650
Text Label 6250 2650 2    50   ~ 0
REF
Wire Wire Line
	5950 3150 6250 3150
Wire Wire Line
	5950 3050 6250 3050
Text Label 6250 3050 2    50   ~ 0
SB_0
Text Label 6250 3150 2    50   ~ 0
SB_1
Wire Wire Line
	5150 3150 4950 3150
Wire Wire Line
	4950 3150 4950 3600
Wire Wire Line
	3650 2000 3400 2000
Wire Wire Line
	2800 2000 2550 2000
Text Label 2550 2000 0    50   ~ 0
SB_0
Text Label 3400 2000 0    50   ~ 0
SB_1
Wire Wire Line
	3300 3750 3000 3750
Text Label 2700 3750 0    50   ~ 0
REF
Wire Wire Line
	3000 3900 3000 3750
Connection ~ 3000 3750
Wire Wire Line
	3000 3750 2700 3750
Wire Wire Line
	3000 4300 3000 4200
Wire Wire Line
	3450 3550 3450 3400
Wire Wire Line
	3800 1800 3800 1650
Wire Wire Line
	2950 1650 2950 1800
Wire Wire Line
	2950 2350 2950 2200
Wire Wire Line
	3800 2350 3800 2200
$Comp
L Connector:Conn_01x04_Female J3
U 1 1 5B28F600
P 9000 2100
F 0 "J3" H 9027 2076 50  0000 L CNN
F 1 "PASSTHRU" H 9027 1985 50  0000 L CNN
F 2 "Connectors_JST:JST_XH_B04B-XH-A_04x2.50mm_Straight" H 9000 2100 50  0001 C CNN
F 3 "~" H 9000 2100 50  0001 C CNN
	1    9000 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 2250 4850 2250
Text Label 4850 2250 0    50   ~ 0
CH0
Wire Wire Line
	5150 2350 4850 2350
Text Label 4850 2350 0    50   ~ 0
CH1
Wire Wire Line
	5150 2450 4850 2450
Text Label 4850 2450 0    50   ~ 0
CH2
Wire Wire Line
	5150 2550 4850 2550
Text Label 4850 2550 0    50   ~ 0
CH3
Wire Wire Line
	5150 2650 4850 2650
Text Label 4850 2650 0    50   ~ 0
CH4
Wire Wire Line
	5150 2750 4850 2750
Text Label 4850 2750 0    50   ~ 0
CH5
Wire Wire Line
	5150 2850 4850 2850
Text Label 4850 2850 0    50   ~ 0
CH6
Wire Wire Line
	5150 2950 4850 2950
Text Label 4850 2950 0    50   ~ 0
CH7
$Comp
L Connector:Conn_01x01_Female J1
U 1 1 5B29237E
P 3700 4150
F 0 "J1" H 3728 4176 50  0000 L CNN
F 1 "EXT_REF" H 3728 4085 50  0000 L CNN
F 2 "Measurement_Points:Measurement_Point_Round-TH_Small" H 3700 4150 50  0001 C CNN
F 3 "~" H 3700 4150 50  0001 C CNN
	1    3700 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4150 3450 4150
Wire Wire Line
	3450 4150 3450 3950
Wire Notes Line
	2400 2700 4300 2700
Wire Notes Line
	4300 1350 2400 1350
Text Notes 2450 1300 0    50   ~ 0
Slave Address Select
Wire Notes Line
	2400 1150 4300 1150
Wire Notes Line
	2400 1150 2400 2700
Wire Notes Line
	4300 1150 4300 2700
Wire Notes Line
	4300 3050 2400 3050
Text Notes 2450 3000 0    50   ~ 0
Reference Voltage Select
Wire Notes Line
	2400 2850 4300 2850
Wire Notes Line
	2400 2850 2400 4700
Wire Notes Line
	4300 2850 4300 4700
Wire Notes Line
	2400 4700 4300 4700
Text Notes 2350 5150 0    50   ~ 0
To use 5V bus as reference, connect center to pin 1\nTo use internal 2.5V reference, leave disconnected\nTo use external 5V reference, connect center to 3 \nand connect EXT_REF to 5V precision reference
$Comp
L power:+5V #PWR0112
U 1 1 5B2A17E0
P 6050 1650
F 0 "#PWR0112" H 6050 1500 50  0001 C CNN
F 1 "+5V" H 6065 1823 50  0000 C CNN
F 2 "" H 6050 1650 50  0001 C CNN
F 3 "" H 6050 1650 50  0001 C CNN
	1    6050 1650
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0113
U 1 1 5B2A1825
P 6450 1650
F 0 "#PWR0113" H 6450 1500 50  0001 C CNN
F 1 "+5V" H 6465 1823 50  0000 C CNN
F 2 "" H 6450 1650 50  0001 C CNN
F 3 "" H 6450 1650 50  0001 C CNN
	1    6450 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1750 6050 1650
Wire Wire Line
	6450 1750 6450 1650
Wire Wire Line
	5950 2250 6050 2250
Wire Wire Line
	6050 2250 6050 2050
Wire Wire Line
	5950 2350 6450 2350
Wire Wire Line
	6450 2350 6450 2050
Wire Notes Line
	4450 3950 6900 3950
Wire Notes Line
	6900 1350 4450 1350
Text Notes 4500 1300 0    50   ~ 0
ADC
Wire Notes Line
	4450 1150 6900 1150
Wire Notes Line
	4450 1150 4450 3950
Wire Notes Line
	6900 1150 6900 3950
Wire Wire Line
	8800 2000 8700 2000
Wire Wire Line
	8700 2000 8700 1850
Wire Wire Line
	8800 2200 8300 2200
Wire Wire Line
	8800 2100 8300 2100
Text Label 8300 2100 0    50   ~ 0
SDA
Text Label 8300 2200 0    50   ~ 0
SCL
$Comp
L power:GND #PWR0114
U 1 1 5B29A637
P 7700 2450
F 0 "#PWR0114" H 7700 2200 50  0001 C CNN
F 1 "GND" H 7705 2277 50  0000 C CNN
F 2 "" H 7700 2450 50  0001 C CNN
F 3 "" H 7700 2450 50  0001 C CNN
	1    7700 2450
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0115
U 1 1 5B29A63D
P 7700 1850
F 0 "#PWR0115" H 7700 1700 50  0001 C CNN
F 1 "+5V" H 7715 2023 50  0000 C CNN
F 2 "" H 7700 1850 50  0001 C CNN
F 3 "" H 7700 1850 50  0001 C CNN
	1    7700 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7800 2000 7700 2000
Wire Wire Line
	7700 2000 7700 1850
Wire Wire Line
	7800 2200 7300 2200
Wire Wire Line
	7800 2100 7300 2100
Text Label 7300 2100 0    50   ~ 0
SDA
Text Label 7300 2200 0    50   ~ 0
SCL
$Comp
L power:GND #PWR0116
U 1 1 5B29CE6A
P 8450 3550
F 0 "#PWR0116" H 8450 3300 50  0001 C CNN
F 1 "GND" H 8455 3377 50  0000 C CNN
F 2 "" H 8450 3550 50  0001 C CNN
F 3 "" H 8450 3550 50  0001 C CNN
	1    8450 3550
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0117
U 1 1 5B29CEAF
P 8450 2950
F 0 "#PWR0117" H 8450 2800 50  0001 C CNN
F 1 "+5V" H 8465 3123 50  0000 C CNN
F 2 "" H 8450 2950 50  0001 C CNN
F 3 "" H 8450 2950 50  0001 C CNN
	1    8450 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 3100 8700 3050
Wire Wire Line
	8700 3050 8450 3050
Wire Wire Line
	7800 3050 7800 3100
Wire Wire Line
	8250 3100 8250 3050
Connection ~ 8250 3050
Wire Wire Line
	8250 3050 7800 3050
Wire Wire Line
	8450 2950 8450 3050
Connection ~ 8450 3050
Wire Wire Line
	8450 3050 8250 3050
Wire Wire Line
	7800 3400 7800 3450
Wire Wire Line
	7800 3450 8250 3450
Wire Wire Line
	8700 3450 8700 3400
Wire Wire Line
	8250 3450 8250 3400
Connection ~ 8250 3450
Wire Wire Line
	8250 3450 8450 3450
Wire Wire Line
	8450 3550 8450 3450
Connection ~ 8450 3450
Wire Wire Line
	8450 3450 8700 3450
Wire Notes Line
	7050 3950 9550 3950
Wire Notes Line
	9550 1350 7050 1350
Text Notes 7100 1300 0    50   ~ 0
Power Input
Wire Notes Line
	7050 1150 9550 1150
Wire Notes Line
	7050 1150 7050 3950
Wire Notes Line
	9550 1150 9550 3950
Wire Wire Line
	6050 2250 6250 2250
Connection ~ 6050 2250
Text Label 6250 2250 2    50   ~ 0
SDA
Wire Wire Line
	6450 2350 6650 2350
Connection ~ 6450 2350
Text Label 6650 2350 2    50   ~ 0
SCL
$Comp
L Connector:Conn_01x04_Female J2
U 1 1 5B22BF38
P 8000 2100
F 0 "J2" H 8027 2076 50  0000 L CNN
F 1 "INPUT" H 8027 1985 50  0000 L CNN
F 2 "Connectors_JST:JST_XH_B04B-XH-A_04x2.50mm_Straight" H 8000 2100 50  0001 C CNN
F 3 "~" H 8000 2100 50  0001 C CNN
	1    8000 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8800 2300 8700 2300
Wire Wire Line
	8700 2300 8700 2450
Wire Wire Line
	7800 2300 7700 2300
Wire Wire Line
	7700 2300 7700 2450
Text Notes 7850 1750 0    50   ~ 0
Todo: make it so \nyou can't short this
Text Notes 5700 1750 0    50   ~ 0
Todo:\nCalculate pullups\nfor I2C speeds
$Sheet
S 4650 4550 650  300 
U 5B31F56C
F0 "Block 0" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 5300 4700 50 
$EndSheet
$Sheet
S 4650 5050 650  300 
U 5B32527D
F0 "Block 4" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 5300 5200 50 
$EndSheet
Wire Wire Line
	5300 4700 5550 4700
Wire Wire Line
	5300 5200 5550 5200
$Sheet
S 5950 4550 650  300 
U 5B3280EC
F0 "Block 1" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 6600 4700 50 
$EndSheet
$Sheet
S 5950 5050 650  300 
U 5B3280EF
F0 "Block 5" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 6600 5200 50 
$EndSheet
Wire Wire Line
	6600 4700 6850 4700
Wire Wire Line
	6600 5200 6850 5200
$Sheet
S 7200 4550 650  300 
U 5B32922D
F0 "Block 2" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 7850 4700 50 
$EndSheet
$Sheet
S 7200 5050 650  300 
U 5B329230
F0 "Block 6" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 7850 5200 50 
$EndSheet
Wire Wire Line
	7850 4700 8100 4700
Wire Wire Line
	7850 5200 8100 5200
$Sheet
S 8450 4550 650  300 
U 5B329235
F0 "Block 3" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 9100 4700 50 
$EndSheet
$Sheet
S 8450 5050 650  300 
U 5B329238
F0 "Block 7" 50
F1 "irblock.sch" 50
F2 "OUTPUT" O R 9100 5200 50 
$EndSheet
Wire Wire Line
	9100 4700 9350 4700
Wire Wire Line
	9100 5200 9350 5200
Text Label 5550 4700 2    50   ~ 0
CH0
Text Label 6850 4700 2    50   ~ 0
CH1
Text Label 8100 4700 2    50   ~ 0
CH2
Text Label 9350 4700 2    50   ~ 0
CH3
Text Label 5550 5200 2    50   ~ 0
CH4
Text Label 6850 5200 2    50   ~ 0
CH5
Text Label 8100 5200 2    50   ~ 0
CH6
Text Label 9350 5200 2    50   ~ 0
CH7
Wire Notes Line
	9550 4300 4450 4300
Text Notes 4500 4250 0    50   ~ 0
IR Array
Wire Notes Line
	4450 4100 9550 4100
Wire Notes Line
	4450 4100 4450 5650
Wire Notes Line
	9550 4100 9550 5650
Wire Notes Line
	4450 5650 9550 5650
$EndSCHEMATC
