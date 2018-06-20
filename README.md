# IR Sensor Array

An infra-red sensor array for detecting lines and small objects up to 15cm away.

## PCB Description

![Schematic](https://raw.githubusercontent.com/Arrakark/IRSensorArray/master/IRSensorArray.png)

![IR Block](https://raw.githubusercontent.com/Arrakark/IRSensorArray/master/irblock-Block%200.png)

![PCB](https://raw.githubusercontent.com/Arrakark/IRSensorArray/master/sensorarray.png)

![3d view](https://raw.githubusercontent.com/Arrakark/IRSensorArray/master/array.png)

### Specs

* 3.3V - 6V input voltage
* Can be used with I2C fast mode using ~2k pullups (try 10k first)
* Can detect lines with high precision and speed
* Can detect objects and surfaces up to 15cm away
* Uses 4-pin JST-XH headers for power and data
* Power and data be daisychained

This project was created using KiCad 5 RC2. Use it to open and edit this design.

### BOM

|      |                                      |                                                               |            |                         |                    |  |  | 
|------|--------------------------------------|---------------------------------------------------------------|------------|-------------------------|--------------------|--|--| 
| "Id" | "Designator"                         | "Package"                                                     | "Quantity" | "Designation"           | "Supplier and ref" |  |  | 
| 1    | "MH2,MH1"                            | "MountingHole_3.2mm_M3"                                       | 2          | "MountingHole_3.2mm_M3" |                    |  |  | 
| 2    | "C1"                                 | "C_Disc_D5.1mm_W3.2mm_P5.00mm"                                | 1          | "0.1uF"                 |                    |  |  | 
| 3    | "C2"                                 | "CP_Radial_D5.0mm_P2.00mm"                                    | 1          | "10uF"                  |                    |  |  | 
| 4    | "C4"                                 | "C_Disc_D5.1mm_W3.2mm_P5.00mm"                                | 1          | "100nF"                 |                    |  |  | 
| 5    | "D1,D2,D3,D4,D5,D6,D7,D8"            | "LED_D5.0mm"                                                  | 8          | "EMITTER"               |                    |  |  | 
| 6    | "J1"                                 | "Measurement_Point_Round-TH_Small"                            | 1          | "EXT_REF"               |                    |  |  | 
| 7    | "Q1,Q2,Q3,Q5,Q6,Q7,Q8,Q4"            | "LED_D5.0mm"                                                  | 8          | "QSD124"                |                    |  |  | 
| 8    | "R1,R2,R4,R6,R8,R10,R12,R14,R16,R18" | "R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical"              | 10         | "10k0"                  |                    |  |  | 
| 9    | "R3,R5,R7,R9,R11,R13,R15,R17"        | "R_Axial_DIN0207_L6.3mm_D2.5mm_P2.54mm_Vertical"              | 8          | "330R"                  |                    |  |  | 
| 10   | "U1"                                 | "TSSOP-16_4.4x5mm_Pitch0.65mm"                                | 1          | "ADS7828"               |                    |  |  | 
| 11   | "J2"                                 | "JST_XH_B04B-XH-A_04x2.50mm_Straight"                         | 1          | "INPUT"                 |                    |  |  | 
| 12   | "J3"                                 | "JST_XH_B04B-XH-A_04x2.50mm_Straight"                         | 1          | "PASSTHRU"              |                    |  |  | 
| 13   | "JP1"                                | "SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" | 1          | "SB_0"                  |                    |  |  | 
| 14   | "JP2"                                | "SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" | 1          | "REF_5V"                |                    |  |  | 
| 15   | "JP3"                                | "SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm_NumberLabels" | 1          | "SB_1"                  |                    |  |  | 
| 16   | "G***"                               | "rover"                                                       | 1          | "LOGO"                  |                    |  |  | 


## Installing

Install the sensor array using two M3 screws and standoffs. **There is no reverse polarity protection. If you connect several arrays backwards, they will burn out!** Be careful. 

## Signal Control

Use the library included with this repo to read the values of the sensors. 

Use the following code to create a sensor array object:
```
SensorArray array1(I2C Bus);
```

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/Arrakark/IRSensorArray/blob/master/LICENSE) file for details

## Acknowledgments

* Special thanks to the V2FC robot team!
