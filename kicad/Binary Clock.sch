EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Binary Clock"
Date "2020-11-09"
Rev "v1.0"
Comp "Bartłomiej Przemysław Pluta"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R5
U 1 1 5FAD7C11
P 5250 2550
F 0 "R5" V 5043 2550 50  0000 C CNN
F 1 "56R" V 5134 2550 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 2550 50  0001 C CNN
F 3 "~" H 5250 2550 50  0001 C CNN
	1    5250 2550
	0    1    1    0   
$EndComp
$Comp
L Device:R R6
U 1 1 5FAD9C0A
P 5250 2850
F 0 "R6" V 5043 2850 50  0000 C CNN
F 1 "56R" V 5134 2850 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 2850 50  0001 C CNN
F 3 "~" H 5250 2850 50  0001 C CNN
	1    5250 2850
	0    1    1    0   
$EndComp
$Comp
L Device:R R7
U 1 1 5FADA088
P 5250 3150
F 0 "R7" V 5043 3150 50  0000 C CNN
F 1 "56R" V 5134 3150 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 3150 50  0001 C CNN
F 3 "~" H 5250 3150 50  0001 C CNN
	1    5250 3150
	0    1    1    0   
$EndComp
$Comp
L Device:R R8
U 1 1 5FADA3FE
P 5250 3450
F 0 "R8" V 5043 3450 50  0000 C CNN
F 1 "56R" V 5134 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 3450 50  0001 C CNN
F 3 "~" H 5250 3450 50  0001 C CNN
	1    5250 3450
	0    1    1    0   
$EndComp
$Comp
L Device:LED HD1
U 1 1 5FAE174B
P 5800 2200
F 0 "HD1" V 5839 2280 50  0000 L CNN
F 1 "LED" V 5748 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 5800 2200 50  0001 C CNN
F 3 "~" H 5800 2200 50  0001 C CNN
	1    5800 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED HD2
U 1 1 5FAE33BF
P 6100 2200
F 0 "HD2" V 6139 2280 50  0000 L CNN
F 1 "LED" V 6048 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 6100 2200 50  0001 C CNN
F 3 "~" H 6100 2200 50  0001 C CNN
	1    6100 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED HD3
U 1 1 5FAE3767
P 6400 2200
F 0 "HD3" V 6439 2280 50  0000 L CNN
F 1 "LED" V 6348 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 6400 2200 50  0001 C CNN
F 3 "~" H 6400 2200 50  0001 C CNN
	1    6400 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED HD4
U 1 1 5FAE3C28
P 6700 2200
F 0 "HD4" V 6739 2280 50  0000 L CNN
F 1 "LED" V 6648 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 6700 2200 50  0001 C CNN
F 3 "~" H 6700 2200 50  0001 C CNN
	1    6700 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED HD5
U 1 1 5FAE41DB
P 7000 2200
F 0 "HD5" V 7039 2280 50  0000 L CNN
F 1 "LED" V 6948 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 7000 2200 50  0001 C CNN
F 3 "~" H 7000 2200 50  0001 C CNN
	1    7000 2200
	0    1    -1   0   
$EndComp
Wire Wire Line
	5800 2550 5800 2350
Wire Wire Line
	5400 2550 5800 2550
Wire Wire Line
	5400 2850 6100 2850
Wire Wire Line
	6100 2850 6100 2350
Wire Wire Line
	6400 3150 6400 2350
Wire Wire Line
	5400 3150 6400 3150
Wire Wire Line
	5400 3450 6700 3450
Wire Wire Line
	6700 3450 6700 2350
Wire Wire Line
	5400 3750 7000 3750
Wire Wire Line
	7000 3750 7000 2350
$Comp
L Device:LED MD1
U 1 1 5FAF3317
P 7400 2200
F 0 "MD1" V 7439 2280 50  0000 L CNN
F 1 "LED" V 7348 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 7400 2200 50  0001 C CNN
F 3 "~" H 7400 2200 50  0001 C CNN
	1    7400 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED MD2
U 1 1 5FAF3335
P 7700 2200
F 0 "MD2" V 7739 2280 50  0000 L CNN
F 1 "LED" V 7648 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 7700 2200 50  0001 C CNN
F 3 "~" H 7700 2200 50  0001 C CNN
	1    7700 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED MD3
U 1 1 5FAF333F
P 8000 2200
F 0 "MD3" V 8039 2280 50  0000 L CNN
F 1 "LED" V 7948 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 8000 2200 50  0001 C CNN
F 3 "~" H 8000 2200 50  0001 C CNN
	1    8000 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED MD4
U 1 1 5FAF3349
P 8300 2200
F 0 "MD4" V 8339 2280 50  0000 L CNN
F 1 "LED" V 8248 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 8300 2200 50  0001 C CNN
F 3 "~" H 8300 2200 50  0001 C CNN
	1    8300 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED MD5
U 1 1 5FAF3353
P 8600 2200
F 0 "MD5" V 8639 2280 50  0000 L CNN
F 1 "LED" V 8548 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 8600 2200 50  0001 C CNN
F 3 "~" H 8600 2200 50  0001 C CNN
	1    8600 2200
	0    1    -1   0   
$EndComp
Wire Wire Line
	7400 2550 7400 2350
Wire Wire Line
	7700 2850 7700 2350
Wire Wire Line
	8000 3150 8000 2350
Wire Wire Line
	8300 3450 8300 2350
Wire Wire Line
	8600 3750 8600 2350
$Comp
L Device:LED MD6
U 1 1 5FAF658E
P 8900 2200
F 0 "MD6" V 8939 2280 50  0000 L CNN
F 1 "LED" V 8848 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 8900 2200 50  0001 C CNN
F 3 "~" H 8900 2200 50  0001 C CNN
	1    8900 2200
	0    1    -1   0   
$EndComp
Wire Wire Line
	5800 2550 7400 2550
Connection ~ 5800 2550
Wire Wire Line
	7700 2850 6100 2850
Connection ~ 6100 2850
Wire Wire Line
	8000 3150 6400 3150
Connection ~ 6400 3150
Wire Wire Line
	8300 3450 6700 3450
Connection ~ 6700 3450
Wire Wire Line
	8600 3750 7000 3750
Connection ~ 7000 3750
Wire Wire Line
	5400 4050 8900 4050
Wire Wire Line
	8900 4050 8900 2350
$Comp
L Device:LED SD1
U 1 1 5FB0032A
P 9300 2200
F 0 "SD1" V 9339 2280 50  0000 L CNN
F 1 "LED" V 9248 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 9300 2200 50  0001 C CNN
F 3 "~" H 9300 2200 50  0001 C CNN
	1    9300 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED SD2
U 1 1 5FB00348
P 9600 2200
F 0 "SD2" V 9639 2280 50  0000 L CNN
F 1 "LED" V 9548 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 9600 2200 50  0001 C CNN
F 3 "~" H 9600 2200 50  0001 C CNN
	1    9600 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED SD3
U 1 1 5FB00352
P 9900 2200
F 0 "SD3" V 9939 2280 50  0000 L CNN
F 1 "LED" V 9848 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 9900 2200 50  0001 C CNN
F 3 "~" H 9900 2200 50  0001 C CNN
	1    9900 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED SD4
U 1 1 5FB0035C
P 10200 2200
F 0 "SD4" V 10239 2280 50  0000 L CNN
F 1 "LED" V 10148 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 10200 2200 50  0001 C CNN
F 3 "~" H 10200 2200 50  0001 C CNN
	1    10200 2200
	0    1    -1   0   
$EndComp
$Comp
L Device:LED SD5
U 1 1 5FB00366
P 10500 2200
F 0 "SD5" V 10539 2280 50  0000 L CNN
F 1 "LED" V 10448 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 10500 2200 50  0001 C CNN
F 3 "~" H 10500 2200 50  0001 C CNN
	1    10500 2200
	0    1    -1   0   
$EndComp
Wire Wire Line
	9300 2550 9300 2350
Wire Wire Line
	9600 2850 9600 2350
Wire Wire Line
	9900 3150 9900 2350
Wire Wire Line
	10200 3450 10200 2350
Wire Wire Line
	10500 3750 10500 2350
$Comp
L Device:LED SD6
U 1 1 5FB00375
P 10800 2200
F 0 "SD6" V 10839 2280 50  0000 L CNN
F 1 "LED" V 10748 2280 50  0001 L CNN
F 2 "LED_THT:LED_D5.0mm" H 10800 2200 50  0001 C CNN
F 3 "~" H 10800 2200 50  0001 C CNN
	1    10800 2200
	0    1    -1   0   
$EndComp
Wire Wire Line
	10800 4050 10800 2350
Wire Wire Line
	7400 2550 9300 2550
Connection ~ 7400 2550
Wire Wire Line
	9600 2850 7700 2850
Connection ~ 7700 2850
Wire Wire Line
	9900 3150 8000 3150
Connection ~ 8000 3150
Wire Wire Line
	10200 3450 8300 3450
Connection ~ 8300 3450
Wire Wire Line
	10500 3750 8600 3750
Connection ~ 8600 3750
Wire Wire Line
	10800 4050 8900 4050
Connection ~ 8900 4050
Wire Wire Line
	5800 2050 5800 1900
Wire Wire Line
	5800 1900 6100 1900
Wire Wire Line
	7000 1900 7000 2050
Wire Wire Line
	6700 2050 6700 1900
Connection ~ 6700 1900
Wire Wire Line
	6700 1900 7000 1900
Wire Wire Line
	6400 2050 6400 1900
Connection ~ 6400 1900
Wire Wire Line
	6400 1900 6700 1900
Wire Wire Line
	6100 2050 6100 1900
Connection ~ 6100 1900
Wire Wire Line
	6100 1900 6400 1900
Wire Wire Line
	7400 2050 7400 1900
Wire Wire Line
	7400 1900 7700 1900
Wire Wire Line
	8900 1900 8900 2050
Wire Wire Line
	8600 2050 8600 1900
Connection ~ 8600 1900
Wire Wire Line
	8600 1900 8900 1900
Wire Wire Line
	8300 2050 8300 1900
Connection ~ 8300 1900
Wire Wire Line
	8300 1900 8600 1900
Wire Wire Line
	8000 2050 8000 1900
Connection ~ 8000 1900
Wire Wire Line
	8000 1900 8300 1900
Wire Wire Line
	7700 2050 7700 1900
Connection ~ 7700 1900
Wire Wire Line
	7700 1900 8000 1900
Wire Wire Line
	9300 2050 9300 1900
Wire Wire Line
	10800 1900 10800 2050
Wire Wire Line
	10500 2050 10500 1900
Connection ~ 10500 1900
Wire Wire Line
	10500 1900 10800 1900
Wire Wire Line
	10200 2050 10200 1900
Connection ~ 10200 1900
Wire Wire Line
	10200 1900 10500 1900
Wire Wire Line
	9900 2050 9900 1900
Wire Wire Line
	9300 1900 9600 1900
Connection ~ 9900 1900
Wire Wire Line
	9900 1900 10200 1900
Wire Wire Line
	9600 2050 9600 1900
Connection ~ 9600 1900
Wire Wire Line
	9600 1900 9900 1900
Wire Wire Line
	5100 2550 4950 2550
Text Label 4950 2550 0    39   ~ 0
LED0
Wire Wire Line
	5100 2850 4950 2850
Wire Wire Line
	5100 3150 4950 3150
Wire Wire Line
	5100 3450 4950 3450
Wire Wire Line
	5100 3750 4950 3750
Wire Wire Line
	5100 4050 4950 4050
Text Label 4950 2850 0    39   ~ 0
LED1
Text Label 4950 3150 0    39   ~ 0
LED2
Text Label 4950 3450 0    39   ~ 0
LED3
Text Label 4950 3750 0    39   ~ 0
LED4
Text Label 4950 4050 0    39   ~ 0
LED5
$Comp
L Switch:SW_Push SW1
U 1 1 5FCC0002
P 7600 4950
F 0 "SW1" V 7554 5098 50  0000 L CNN
F 1 "INC_HOUR" V 7645 5098 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7600 5150 50  0001 C CNN
F 3 "~" H 7600 5150 50  0001 C CNN
	1    7600 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 5150 7600 5200
$Comp
L power:GND #PWR?
U 1 1 5FCC8117
P 7600 5200
F 0 "#PWR?" H 7600 4950 50  0001 C CNN
F 1 "GND" H 7605 5027 50  0000 C CNN
F 2 "" H 7600 5200 50  0001 C CNN
F 3 "" H 7600 5200 50  0001 C CNN
	1    7600 5200
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW2
U 1 1 5FD056CB
P 7600 5850
F 0 "SW2" V 7554 5998 50  0000 L CNN
F 1 "INC_MINUTE" V 7645 5998 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 7600 6050 50  0001 C CNN
F 3 "~" H 7600 6050 50  0001 C CNN
	1    7600 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 6050 7600 6100
$Comp
L power:GND #PWR?
U 1 1 5FD056E8
P 7600 6100
F 0 "#PWR?" H 7600 5850 50  0001 C CNN
F 1 "GND" H 7605 5927 50  0000 C CNN
F 2 "" H 7600 6100 50  0001 C CNN
F 3 "" H 7600 6100 50  0001 C CNN
	1    7600 6100
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push SW3
U 1 1 5FD0D6D9
P 8450 4950
F 0 "SW3" V 8404 5098 50  0000 L CNN
F 1 "INC_SECOND" V 8495 5098 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8450 5150 50  0001 C CNN
F 3 "~" H 8450 5150 50  0001 C CNN
	1    8450 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 5150 8450 5200
$Comp
L power:GND #PWR?
U 1 1 5FD0D6F6
P 8450 5200
F 0 "#PWR?" H 8450 4950 50  0001 C CNN
F 1 "GND" H 8455 5027 50  0000 C CNN
F 2 "" H 8450 5200 50  0001 C CNN
F 3 "" H 8450 5200 50  0001 C CNN
	1    8450 5200
	1    0    0    -1  
$EndComp
Wire Notes Line
	6900 7700 6900 6150
Wire Notes Line
	6900 6150 4700 6150
Wire Notes Line
	4700 7700 6900 7700
Wire Notes Line
	4600 7700 550  7700
Wire Notes Line
	7000 4400 9200 4400
Wire Notes Line
	4600 5450 4600 7700
Wire Notes Line
	550  7700 550  5450
Wire Notes Line
	9200 6450 7000 6450
Wire Notes Line
	7000 6450 7000 4400
Wire Notes Line
	9200 4400 9200 6450
Wire Notes Line
	6900 6050 6900 4400
Wire Notes Line
	11150 4300 11150 550 
Text Label 650  1300 0    39   ~ 0
RST
Connection ~ 850  1300
Wire Wire Line
	850  1300 650  1300
Wire Wire Line
	850  1300 1000 1300
Wire Wire Line
	850  1200 850  1300
$Comp
L power:VCC #PWR?
U 1 1 5FAAAD75
P 1700 850
F 0 "#PWR?" H 1700 700 50  0001 C CNN
F 1 "VCC" H 1700 1000 50  0000 C CNN
F 2 "" H 1700 850 50  0001 C CNN
F 3 "" H 1700 850 50  0001 C CNN
	1    1700 850 
	1    0    0    -1  
$EndComp
Connection ~ 1700 950 
Wire Wire Line
	1700 950  1700 850 
Wire Wire Line
	1700 950  1700 1000
Wire Wire Line
	1600 950  1700 950 
Wire Wire Line
	1600 1000 1600 950 
$Comp
L Device:R R1
U 1 1 5FA99267
P 850 1050
F 0 "R1" H 780 1004 50  0000 R CNN
F 1 "10k" H 780 1095 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 780 1050 50  0001 C CNN
F 3 "~" H 850 1050 50  0001 C CNN
	1    850  1050
	-1   0    0    1   
$EndComp
Text Label 2600 2900 2    39   ~ 0
SCK
Text Label 2600 2800 2    39   ~ 0
MISO
Text Label 2600 2700 2    39   ~ 0
MOSI
Wire Wire Line
	2200 2900 2600 2900
Wire Wire Line
	2200 2800 2600 2800
Wire Wire Line
	2200 2700 2600 2700
Wire Wire Line
	2200 1800 2600 1800
Wire Wire Line
	2200 1700 2600 1700
Wire Wire Line
	2200 1600 2600 1600
Wire Wire Line
	2200 1500 2600 1500
Wire Wire Line
	2200 1400 2600 1400
Wire Wire Line
	2200 4200 2600 4200
Wire Wire Line
	2200 1300 2600 1300
Text Label 2600 4200 2    39   ~ 0
RTC_INT
Text Label 2600 1800 2    39   ~ 0
LED5
Text Label 2600 1700 2    39   ~ 0
LED4
Text Label 2600 1600 2    39   ~ 0
LED3
Text Label 2600 1500 2    39   ~ 0
LED2
Text Label 2600 1400 2    39   ~ 0
LED1
Text Label 2600 1300 2    39   ~ 0
LED0
Wire Notes Line
	550  5450 4600 5450
Wire Notes Line
	6900 4400 4700 4400
Wire Notes Line
	4700 6050 6900 6050
Wire Wire Line
	6200 5050 6400 5050
Text Label 6400 5050 2    39   ~ 0
MISO
Wire Wire Line
	6200 5150 6400 5150
Wire Wire Line
	6200 5250 6400 5250
Wire Wire Line
	6200 5350 6400 5350
Text Label 6400 5150 2    39   ~ 0
MOSI
Text Label 6400 5250 2    39   ~ 0
SCK
Text Label 6400 5350 2    39   ~ 0
RST
Wire Wire Line
	5700 4700 5700 4750
$Comp
L power:VCC #PWR?
U 1 1 5FF0D98E
P 5700 4700
F 0 "#PWR?" H 5700 4550 50  0001 C CNN
F 1 "VCC" H 5715 4873 50  0000 C CNN
F 2 "" H 5700 4700 50  0001 C CNN
F 3 "" H 5700 4700 50  0001 C CNN
	1    5700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5700 5650 5700 5700
$Comp
L power:GND #PWR?
U 1 1 5FF05076
P 5700 5700
F 0 "#PWR?" H 5700 5450 50  0001 C CNN
F 1 "GND" H 5705 5527 50  0000 C CNN
F 2 "" H 5700 5700 50  0001 C CNN
F 3 "" H 5700 5700 50  0001 C CNN
	1    5700 5700
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-10 J1
U 1 1 5FEFAC1B
P 5800 5250
F 0 "J1" H 5470 5346 50  0000 R CNN
F 1 "AVR-ISP-10" H 5470 5255 50  0000 R CNN
F 2 "Connector_IDC:IDC-Header_2x05_P2.54mm_Vertical" V 5550 5300 50  0001 C CNN
F 3 " ~" H 4525 4700 50  0001 C CNN
	1    5800 5250
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FBA20AA
P 1600 5050
F 0 "#PWR?" H 1600 4800 50  0001 C CNN
F 1 "GND" H 1600 4900 50  0000 C CNN
F 2 "" H 1600 5050 50  0001 C CNN
F 3 "" H 1600 5050 50  0001 C CNN
	1    1600 5050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 5050 1600 5000
Wire Wire Line
	850  850  850  900 
$Comp
L power:VCC #PWR?
U 1 1 5FAA8074
P 850 850
F 0 "#PWR?" H 850 700 50  0001 C CNN
F 1 "VCC" H 850 1000 50  0000 C CNN
F 2 "" H 850 850 50  0001 C CNN
F 3 "" H 850 850 50  0001 C CNN
	1    850  850 
	1    0    0    -1  
$EndComp
Wire Notes Line
	550  550  550  5350
$Comp
L MCU_Microchip_ATmega:ATmega32A-PU U1
U 1 1 5FCFC43A
P 1600 3000
F 0 "U1" H 2050 4950 50  0000 C CNN
F 1 "ATmega32A-PU" H 1950 1050 50  0000 C CNN
F 2 "Package_QFP:TQFP-44-1EP_10x10mm_P0.8mm_EP4.5x4.5mm" H 1600 3000 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-8155-8-bit-microcontroller-avr-atmega32a_datasheet.pdf" H 1600 3000 50  0001 C CNN
	1    1600 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 2200 2600 2200
Wire Wire Line
	2200 2300 2600 2300
Wire Wire Line
	2200 2400 2600 2400
Text Label 2600 2200 2    39   ~ 0
INC_HOUR
Text Label 2600 2300 2    39   ~ 0
INC_MINUTE
Text Label 2600 2400 2    39   ~ 0
INC_SECOND
Wire Wire Line
	2200 4700 2600 4700
Wire Wire Line
	2200 4600 2600 4600
Wire Wire Line
	2200 4500 2600 4500
Text Label 2600 4700 2    39   ~ 0
SECOND_LED
Text Label 2600 4600 2    39   ~ 0
MINUTE_LED
Text Label 2300 4500 0    39   ~ 0
HOUR_LED
$Comp
L Device:C C4
U 1 1 5FAAEFBE
P 3350 4150
F 0 "C4" H 3465 4196 50  0000 L CNN
F 1 "100n" H 3465 4105 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 3388 4000 50  0001 C CNN
F 3 "~" H 3350 4150 50  0001 C CNN
	1    3350 4150
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C6
U 1 1 5FAAF777
P 3850 4150
F 0 "C6" H 3968 4196 50  0000 L CNN
F 1 "22u" H 3968 4105 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x5.3" H 3888 4000 50  0001 C CNN
F 3 "~" H 3850 4150 50  0001 C CNN
	1    3850 4150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3850 3800 3850 4000
Wire Wire Line
	3350 3800 3600 3800
Wire Wire Line
	3600 3800 3600 3650
Connection ~ 3600 3800
Wire Wire Line
	3600 3800 3850 3800
Wire Wire Line
	3850 4550 3850 4300
Wire Wire Line
	3600 4550 3600 4650
Wire Wire Line
	3600 4550 3850 4550
$Comp
L power:VCC #PWR?
U 1 1 5FAB31CC
P 3600 3650
F 0 "#PWR?" H 3600 3500 50  0001 C CNN
F 1 "VCC" H 3615 3823 50  0000 C CNN
F 2 "" H 3600 3650 50  0001 C CNN
F 3 "" H 3600 3650 50  0001 C CNN
	1    3600 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FAB3B5F
P 3600 4650
F 0 "#PWR?" H 3600 4400 50  0001 C CNN
F 1 "GND" H 3605 4477 50  0000 C CNN
F 2 "" H 3600 4650 50  0001 C CNN
F 3 "" H 3600 4650 50  0001 C CNN
	1    3600 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3800 3350 4000
Wire Wire Line
	3350 4300 3350 4550
Wire Wire Line
	3350 4550 3600 4550
Connection ~ 3600 4550
$Comp
L power:VCC #PWR?
U 1 1 5FAC4BA3
P 3050 2450
F 0 "#PWR?" H 3050 2300 50  0001 C CNN
F 1 "VCC" H 3065 2623 50  0000 C CNN
F 2 "" H 3050 2450 50  0001 C CNN
F 3 "" H 3050 2450 50  0001 C CNN
	1    3050 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 2450 3050 2600
Wire Wire Line
	3050 2600 3200 2600
Connection ~ 3050 2600
Wire Wire Line
	3200 2600 3200 2700
Wire Wire Line
	2900 2600 3050 2600
Wire Wire Line
	2900 2700 2900 2600
Wire Wire Line
	3200 3100 3400 3100
Wire Wire Line
	3200 3000 3200 3100
Wire Wire Line
	2900 3200 3400 3200
Wire Wire Line
	2900 3000 2900 3200
$Comp
L Device:R R3
U 1 1 5FABFC16
P 3200 2850
F 0 "R3" H 3130 2804 50  0000 R CNN
F 1 "4k7" H 3130 2895 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 3130 2850 50  0001 C CNN
F 3 "~" H 3200 2850 50  0001 C CNN
	1    3200 2850
	-1   0    0    1   
$EndComp
$Comp
L Device:R R2
U 1 1 5FABF1AE
P 2900 2850
F 0 "R2" H 2830 2804 50  0000 R CNN
F 1 "4k7" H 2830 2895 50  0000 R CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 2830 2850 50  0001 C CNN
F 3 "~" H 2900 2850 50  0001 C CNN
	1    2900 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	2200 4400 2300 4400
Wire Wire Line
	2200 4300 2300 4300
Wire Wire Line
	2200 2600 2300 2600
Wire Wire Line
	2200 1900 2300 1900
Wire Wire Line
	2200 2000 2300 2000
Wire Wire Line
	1000 1500 900  1500
Wire Wire Line
	1000 1700 900  1700
Wire Wire Line
	1000 1900 900  1900
NoConn ~ 900  1900
NoConn ~ 900  1700
NoConn ~ 900  1500
NoConn ~ 2300 1900
NoConn ~ 2300 2000
NoConn ~ 2300 2600
NoConn ~ 2300 4300
NoConn ~ 2300 4400
$Comp
L power:PWR_FLAG #FLG?
U 1 1 600DBDE7
P 5150 7250
F 0 "#FLG?" H 5150 7325 50  0001 C CNN
F 1 "PWR_FLAG" H 5150 7423 50  0000 C CNN
F 2 "" H 5150 7250 50  0001 C CNN
F 3 "~" H 5150 7250 50  0001 C CNN
	1    5150 7250
	-1   0    0    1   
$EndComp
$Comp
L power:PWR_FLAG #FLG?
U 1 1 600DC567
P 5150 6550
F 0 "#FLG?" H 5150 6625 50  0001 C CNN
F 1 "PWR_FLAG" H 5150 6723 50  0000 C CNN
F 2 "" H 5150 6550 50  0001 C CNN
F 3 "~" H 5150 6550 50  0001 C CNN
	1    5150 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 6550 5150 6650
Wire Wire Line
	5150 7250 5150 7150
$Comp
L Device:R R9
U 1 1 5FADA731
P 5250 3750
F 0 "R9" V 5043 3750 50  0000 C CNN
F 1 "56R" V 5134 3750 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 3750 50  0001 C CNN
F 3 "~" H 5250 3750 50  0001 C CNN
	1    5250 3750
	0    1    1    0   
$EndComp
$Comp
L Device:R R10
U 1 1 5FADAA35
P 5250 4050
F 0 "R10" V 5043 4050 50  0000 C CNN
F 1 "56R" V 5134 4050 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 5180 4050 50  0001 C CNN
F 3 "~" H 5250 4050 50  0001 C CNN
	1    5250 4050
	0    1    1    0   
$EndComp
$Comp
L Device:Battery BT1
U 1 1 5FACBB8C
P 5150 6900
F 0 "BT1" H 5258 6946 50  0000 L CNN
F 1 "3x1.5V" H 5258 6855 50  0000 L CNN
F 2 "Battery:BatteryHolder_TruPower_BH-331P_3xAA" V 5150 6960 50  0001 C CNN
F 3 "~" V 5150 6960 50  0001 C CNN
	1    5150 6900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 6700 5150 6650
Connection ~ 5150 6650
Wire Wire Line
	5150 7100 5150 7150
Connection ~ 5150 7150
Wire Notes Line
	4250 6200 4250 6900
Connection ~ 7000 1900
Connection ~ 10800 1900
Wire Wire Line
	10800 1550 10800 1900
Connection ~ 8900 1900
Wire Wire Line
	8900 1550 8900 1900
Wire Wire Line
	7000 1550 7000 1900
Text Label 9250 1350 0    39   ~ 0
SECOND_LED
Wire Wire Line
	9600 1350 9250 1350
Text Label 7400 1350 0    39   ~ 0
MINUTE_LED
$Comp
L Device:R R11
U 1 1 5FB2FB2C
P 6450 1350
F 0 "R11" V 6243 1350 50  0000 C CNN
F 1 "2k2" V 6334 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 6380 1350 50  0001 C CNN
F 3 "~" H 6450 1350 50  0001 C CNN
	1    6450 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	6700 1350 6600 1350
Wire Wire Line
	10100 1350 10000 1350
Wire Wire Line
	10500 1350 10400 1350
$Comp
L Device:R R13
U 1 1 5FB3A3FB
P 10250 1350
F 0 "R13" V 10043 1350 50  0000 C CNN
F 1 "2k2" V 10134 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 10180 1350 50  0001 C CNN
F 3 "~" H 10250 1350 50  0001 C CNN
	1    10250 1350
	0    1    1    0   
$EndComp
$Comp
L Device:Q_PNP_BCE PNP3
U 1 1 5FB3A3CF
P 10700 1350
F 0 "PNP3" H 10891 1350 50  0000 L CNN
F 1 "Q_PNP_BCE" H 10890 1395 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 10900 1450 50  0001 C CNN
F 3 "~" H 10700 1350 50  0001 C CNN
	1    10700 1350
	1    0    0    1   
$EndComp
Wire Wire Line
	8600 1350 8450 1350
$Comp
L Device:R R12
U 1 1 5FB351D5
P 8300 1350
F 0 "R12" V 8093 1350 50  0000 C CNN
F 1 "2k2" V 8184 1350 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 8230 1350 50  0001 C CNN
F 3 "~" H 8300 1350 50  0001 C CNN
	1    8300 1350
	0    1    1    0   
$EndComp
$Comp
L Device:Q_PNP_BCE PNP2
U 1 1 5FB351A9
P 8800 1350
F 0 "PNP2" H 8991 1350 50  0000 L CNN
F 1 "Q_PNP_BCE" H 8990 1395 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 9000 1450 50  0001 C CNN
F 3 "~" H 8800 1350 50  0001 C CNN
	1    8800 1350
	1    0    0    1   
$EndComp
$Comp
L Device:Q_PNP_BCE PNP1
U 1 1 5FB29A35
P 6900 1350
F 0 "PNP1" H 7091 1350 50  0000 L CNN
F 1 "Q_PNP_BCE" H 7090 1395 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 7100 1450 50  0001 C CNN
F 3 "~" H 6900 1350 50  0001 C CNN
	1    6900 1350
	1    0    0    1   
$EndComp
Wire Wire Line
	5800 1350 6300 1350
Wire Wire Line
	7400 1350 8150 1350
Text Label 5800 1350 0    39   ~ 0
HOUR_LED
Text Label 7200 4650 0    39   ~ 0
INC_HOUR
Wire Wire Line
	7200 4650 7600 4650
Wire Wire Line
	7600 4750 7600 4650
Text Label 7200 5550 0    39   ~ 0
INC_MINUTE
Wire Wire Line
	7200 5550 7600 5550
Wire Wire Line
	7600 5650 7600 5550
Text Label 8050 4650 0    39   ~ 0
INC_SECOND
Wire Wire Line
	8050 4650 8450 4650
Wire Wire Line
	8450 4750 8450 4650
$Comp
L Switch:SW_Push SW4
U 1 1 5FD20DE5
P 8450 5850
F 0 "SW4" V 8404 5998 50  0000 L CNN
F 1 "INC_BTNESS" V 8495 5998 50  0000 L CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 8450 6050 50  0001 C CNN
F 3 "~" H 8450 6050 50  0001 C CNN
	1    8450 5850
	0    1    1    0   
$EndComp
Wire Wire Line
	8450 6050 8450 6100
$Comp
L power:GND #PWR?
U 1 1 5FD20E02
P 8450 6100
F 0 "#PWR?" H 8450 5850 50  0001 C CNN
F 1 "GND" H 8455 5927 50  0000 C CNN
F 2 "" H 8450 6100 50  0001 C CNN
F 3 "" H 8450 6100 50  0001 C CNN
	1    8450 6100
	1    0    0    -1  
$EndComp
Text Label 8050 5550 0    39   ~ 0
INC_BTNESS
Wire Wire Line
	8050 5550 8450 5550
Wire Wire Line
	8450 5650 8450 5550
Wire Wire Line
	2200 2500 2600 2500
Text Label 2600 2500 2    39   ~ 0
INC_BTNESS
Wire Wire Line
	2200 4000 2600 4000
Wire Wire Line
	2200 4100 2600 4100
Text Label 2600 4000 2    39   ~ 0
RX
Text Label 2600 4100 2    39   ~ 0
TX
$Comp
L Connector_Generic:Conn_01x04 J2
U 1 1 5FBF376B
P 9850 5350
F 0 "J2" H 9930 5342 50  0000 L CNN
F 1 "UART" H 9930 5251 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9850 5350 50  0001 C CNN
F 3 "~" H 9850 5350 50  0001 C CNN
	1    9850 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3300 2600 3300
Wire Wire Line
	2200 3400 2600 3400
Wire Wire Line
	2200 3500 2600 3500
Wire Wire Line
	2200 3600 2600 3600
Wire Wire Line
	2200 3700 2600 3700
Text Label 2600 3300 2    39   ~ 0
COM0
Text Label 2600 3400 2    39   ~ 0
COM1
Text Label 2600 3500 2    39   ~ 0
COM2
Text Label 2600 3600 2    39   ~ 0
COM3
Text Label 2600 3700 2    39   ~ 0
COM4
Wire Wire Line
	9650 5350 9550 5350
Wire Wire Line
	9650 5450 9550 5450
Wire Wire Line
	9650 5550 9600 5550
Wire Wire Line
	9600 5550 9600 5600
Wire Wire Line
	9650 5250 9600 5250
Wire Wire Line
	9600 5250 9600 5200
Text Label 9550 5350 0    39   ~ 0
TX
Text Label 9550 5450 0    39   ~ 0
RX
$Comp
L power:GND #PWR?
U 1 1 5FCADB86
P 9600 5600
F 0 "#PWR?" H 9600 5350 50  0001 C CNN
F 1 "GND" H 9605 5427 50  0000 C CNN
F 2 "" H 9600 5600 50  0001 C CNN
F 3 "" H 9600 5600 50  0001 C CNN
	1    9600 5600
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FCADEB9
P 9600 5200
F 0 "#PWR?" H 9600 5050 50  0001 C CNN
F 1 "VCC" H 9615 5373 50  0000 C CNN
F 2 "" H 9600 5200 50  0001 C CNN
F 3 "" H 9600 5200 50  0001 C CNN
	1    9600 5200
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FD558EF
P 10350 4950
F 0 "#PWR?" H 10350 4800 50  0001 C CNN
F 1 "VCC" H 10365 5123 50  0000 C CNN
F 2 "" H 10350 4950 50  0001 C CNN
F 3 "" H 10350 4950 50  0001 C CNN
	1    10350 4950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FD555EF
P 10350 5850
F 0 "#PWR?" H 10350 5600 50  0001 C CNN
F 1 "GND" H 10355 5677 50  0000 C CNN
F 2 "" H 10350 5850 50  0001 C CNN
F 3 "" H 10350 5850 50  0001 C CNN
	1    10350 5850
	1    0    0    -1  
$EndComp
Text Label 10250 5700 0    39   ~ 0
COM4
Text Label 10250 5600 0    39   ~ 0
COM3
Text Label 10250 5500 0    39   ~ 0
COM2
Text Label 10250 5400 0    39   ~ 0
COM1
Wire Wire Line
	10350 5000 10350 4950
Wire Wire Line
	10400 5000 10350 5000
Wire Wire Line
	10350 5800 10350 5850
Wire Wire Line
	10400 5800 10350 5800
Wire Wire Line
	10400 5700 10250 5700
Wire Wire Line
	10400 5600 10250 5600
Wire Wire Line
	10400 5500 10250 5500
Wire Wire Line
	10400 5400 10250 5400
Text Label 10250 5300 0    39   ~ 0
COM0
Wire Wire Line
	10250 5300 10400 5300
Wire Notes Line
	11150 4400 11150 6450
Wire Notes Line
	11150 6450 9300 6450
Wire Notes Line
	9300 6450 9300 4400
Wire Notes Line
	9300 4400 11150 4400
Wire Wire Line
	10400 5100 10250 5100
Wire Wire Line
	10400 5200 10250 5200
Text Label 10250 5200 0    39   ~ 0
SCL
Text Label 10250 5100 0    39   ~ 0
SDA
$Comp
L power:VCC #PWR?
U 1 1 5FBF53FA
P 2900 7100
F 0 "#PWR?" H 2900 6950 50  0001 C CNN
F 1 "VCC" H 2915 7273 50  0000 C CNN
F 2 "" H 2900 7100 50  0001 C CNN
F 3 "" H 2900 7100 50  0001 C CNN
	1    2900 7100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2900 7200 2900 7100
Wire Wire Line
	2800 7200 2900 7200
Wire Wire Line
	1900 7200 1900 7300
Connection ~ 1900 7200
Wire Wire Line
	2300 7200 1900 7200
Wire Wire Line
	1900 6900 1900 7200
Wire Wire Line
	2400 6700 2550 6700
Wire Wire Line
	2550 6700 2550 7050
Connection ~ 2800 6300
Wire Wire Line
	2800 6300 2400 6300
Connection ~ 1200 6300
Wire Wire Line
	1200 6300 1200 6150
Wire Wire Line
	1200 6700 1200 6650
Wire Wire Line
	1400 6700 1200 6700
Wire Wire Line
	1200 6300 1200 6350
Wire Wire Line
	1400 6300 1200 6300
$Comp
L PCF8583:PCF8583P U2
U 1 1 6001FC75
P 1900 6100
F 0 "U2" H 2250 6050 39  0000 C CNN
F 1 "PCF8583P" H 2250 5350 39  0000 C CNN
F 2 "Package_SO:Diodes_SO-8EP" H 1900 6100 39  0001 C CNN
F 3 "" H 1900 6100 39  0001 C CNN
	1    1900 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	1200 5800 1200 5850
$Comp
L power:VCC #PWR?
U 1 1 603B14F7
P 1200 5800
F 0 "#PWR?" H 1200 5650 50  0001 C CNN
F 1 "VCC" H 1215 5973 50  0000 C CNN
F 2 "" H 1200 5800 50  0001 C CNN
F 3 "" H 1200 5800 50  0001 C CNN
	1    1200 5800
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 601FAEDF
P 3750 5850
F 0 "#PWR?" H 3750 5700 50  0001 C CNN
F 1 "VCC" H 3765 6023 50  0000 C CNN
F 2 "" H 3750 5850 50  0001 C CNN
F 3 "" H 3750 5850 50  0001 C CNN
	1    3750 5850
	1    0    0    -1  
$EndComp
Text Notes 4050 6850 0    39   ~ 0
VCAP
Wire Notes Line
	3550 6900 3550 6200
Wire Notes Line
	4250 6900 3550 6900
Wire Notes Line
	3550 6200 4250 6200
Connection ~ 3750 6800
Connection ~ 3750 6300
Wire Wire Line
	3200 6300 3750 6300
$Comp
L Device:D_Schottky D1
U 1 1 5FB89BAD
P 3750 6000
F 0 "D1" V 3750 5920 50  0000 R CNN
F 1 "D_Schottky" V 3705 5920 50  0001 R CNN
F 2 "Diode_SMD:D_2114_3652Metric" H 3750 6000 50  0001 C CNN
F 3 "~" H 3750 6000 50  0001 C CNN
	1    3750 6000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3750 6150 3750 6300
$Comp
L power:GND #PWR?
U 1 1 5FFA1A7E
P 1900 7300
F 0 "#PWR?" H 1900 7050 50  0001 C CNN
F 1 "GND" H 1905 7127 50  0000 C CNN
F 2 "" H 1900 7300 50  0001 C CNN
F 3 "" H 1900 7300 50  0001 C CNN
	1    1900 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 6400 2650 6400
Text Label 2650 6400 2    39   ~ 0
RTC_INT
Wire Wire Line
	2400 6500 2650 6500
Wire Wire Line
	2400 6600 2650 6600
Text Label 2650 6500 2    39   ~ 0
SCL
Text Label 2650 6600 2    39   ~ 0
SDA
$Comp
L Device:C C2
U 1 1 60130C3F
P 2800 6550
F 0 "C2" H 2915 6596 50  0000 L CNN
F 1 "22p" H 2915 6505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 2838 6400 50  0001 C CNN
F 3 "~" H 2800 6550 50  0001 C CNN
	1    2800 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 601318D6
P 3200 6550
F 0 "C3" H 3318 6596 50  0000 L CNN
F 1 "47u" H 3318 6505 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x5.3" H 3238 6400 50  0001 C CNN
F 3 "~" H 3200 6550 50  0001 C CNN
	1    3200 6550
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C5
U 1 1 60131D75
P 3750 6550
F 0 "C5" H 3868 6596 50  0000 L CNN
F 1 "0.1-1F" H 3868 6505 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D12.5mm_W5.0mm_P10.00mm" H 3788 6400 50  0001 C CNN
F 3 "~" H 3750 6550 50  0001 C CNN
	1    3750 6550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2800 6800 3200 6800
Wire Wire Line
	2800 6300 3200 6300
Connection ~ 3200 6300
Wire Wire Line
	3750 6800 3200 6800
Connection ~ 3200 6800
$Comp
L power:GND #PWR?
U 1 1 60206F8B
P 3750 7300
F 0 "#PWR?" H 3750 7050 50  0001 C CNN
F 1 "GND" H 3755 7127 50  0000 C CNN
F 2 "" H 3750 7300 50  0001 C CNN
F 3 "" H 3750 7300 50  0001 C CNN
	1    3750 7300
	1    0    0    -1  
$EndComp
Wire Wire Line
	3750 7300 3750 6800
Wire Wire Line
	3750 6300 3750 6400
Wire Wire Line
	3750 6700 3750 6800
Wire Wire Line
	2800 6700 2800 6800
Wire Wire Line
	2800 6400 2800 6300
Wire Wire Line
	3200 6400 3200 6300
Wire Wire Line
	3200 6700 3200 6800
$Comp
L Device:Crystal Y1
U 1 1 600500D5
P 1200 6500
F 0 "Y1" V 1250 6750 50  0000 R CNN
F 1 "32768hZ" V 1150 6950 50  0000 R CNN
F 2 "Crystal:Crystal_DS26_D2.0mm_L6.0mm_Horizontal" H 1200 6500 50  0001 C CNN
F 3 "~" H 1200 6500 50  0001 C CNN
	1    1200 6500
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 603A494A
P 1200 6000
F 0 "C1" H 1315 6046 50  0000 L CNN
F 1 "22p" H 1315 5955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 1238 5850 50  0001 C CNN
F 3 "~" H 1200 6000 50  0001 C CNN
	1    1200 6000
	1    0    0    -1  
$EndComp
$Comp
L Jumper:Jumper_3_Open JP1
U 1 1 5FC76645
P 2550 7200
F 0 "JP1" H 2550 7331 50  0000 C CNN
F 1 "TWI_ADDR" H 2550 7422 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 2550 7200 50  0001 C CNN
F 3 "~" H 2550 7200 50  0001 C CNN
	1    2550 7200
	-1   0    0    1   
$EndComp
$Comp
L Jumper:Jumper_2_Open JP2
U 1 1 5FC97851
P 9800 1350
F 0 "JP2" H 9800 1585 50  0000 C CNN
F 1 "S_EN" H 9800 1494 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 9800 1350 50  0001 C CNN
F 3 "~" H 9800 1350 50  0001 C CNN
	1    9800 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 7150 5900 7150
Connection ~ 5900 7150
Connection ~ 5900 6650
Wire Wire Line
	5150 6650 5900 6650
Wire Wire Line
	5900 6650 6400 6650
$Comp
L power:GND #PWR?
U 1 1 5FCB23B4
P 6400 7250
F 0 "#PWR?" H 6400 7000 50  0001 C CNN
F 1 "GND" H 6405 7077 50  0000 C CNN
F 2 "" H 6400 7250 50  0001 C CNN
F 3 "" H 6400 7250 50  0001 C CNN
	1    6400 7250
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FCB1A00
P 6400 6550
F 0 "#PWR?" H 6400 6400 50  0001 C CNN
F 1 "VCC" H 6415 6723 50  0000 C CNN
F 2 "" H 6400 6550 50  0001 C CNN
F 3 "" H 6400 6550 50  0001 C CNN
	1    6400 6550
	1    0    0    -1  
$EndComp
Connection ~ 6400 7150
Wire Wire Line
	6400 7150 6400 7250
Wire Wire Line
	6400 7150 6400 7050
Connection ~ 6400 6650
Wire Wire Line
	6400 6650 6400 6550
Wire Wire Line
	6400 6650 6400 6750
Wire Wire Line
	5900 7150 6400 7150
Wire Wire Line
	5900 7050 5900 7150
Wire Wire Line
	5900 6650 5900 6750
$Comp
L Device:CP C7
U 1 1 5FC4FFC8
P 5900 6900
F 0 "C7" H 6018 6946 50  0000 L CNN
F 1 "470u" H 6018 6855 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_8x10" H 5938 6750 50  0001 C CNN
F 3 "~" H 5900 6900 50  0001 C CNN
	1    5900 6900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5FC2582D
P 6400 6900
F 0 "C8" H 6515 6946 50  0000 L CNN
F 1 "100n" H 6515 6855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.18x1.45mm_HandSolder" H 6438 6750 50  0001 C CNN
F 3 "~" H 6400 6900 50  0001 C CNN
	1    6400 6900
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FE4376E
P 7000 900
F 0 "#PWR?" H 7000 750 50  0001 C CNN
F 1 "VCC" H 7015 1073 50  0000 C CNN
F 2 "" H 7000 900 50  0001 C CNN
F 3 "" H 7000 900 50  0001 C CNN
	1    7000 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FE43BFB
P 8900 900
F 0 "#PWR?" H 8900 750 50  0001 C CNN
F 1 "VCC" H 8915 1073 50  0000 C CNN
F 2 "" H 8900 900 50  0001 C CNN
F 3 "" H 8900 900 50  0001 C CNN
	1    8900 900 
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR?
U 1 1 5FE44341
P 10800 900
F 0 "#PWR?" H 10800 750 50  0001 C CNN
F 1 "VCC" H 10815 1073 50  0000 C CNN
F 2 "" H 10800 900 50  0001 C CNN
F 3 "" H 10800 900 50  0001 C CNN
	1    10800 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 1150 7000 900 
Wire Wire Line
	8900 1150 8900 900 
Wire Wire Line
	10800 1150 10800 900 
Wire Wire Line
	2200 3100 3200 3100
Connection ~ 3200 3100
Wire Wire Line
	2200 3200 2900 3200
Connection ~ 2900 3200
Wire Notes Line
	550  550  3550 550 
Wire Notes Line
	5650 550  11150 550 
Text Label 3850 1500 0    39   ~ 0
BUZZER
Wire Wire Line
	3850 1500 4100 1500
Wire Notes Line
	3650 550  5550 550 
Wire Notes Line
	3650 2150 3650 550 
Wire Notes Line
	5550 2150 3650 2150
Wire Notes Line
	5550 550  5550 2150
$Comp
L power:VCC #PWR?
U 1 1 5FD56A27
P 4750 900
F 0 "#PWR?" H 4750 750 50  0001 C CNN
F 1 "VCC" H 4765 1073 50  0000 C CNN
F 2 "" H 4750 900 50  0001 C CNN
F 3 "" H 4750 900 50  0001 C CNN
	1    4750 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 1500 4400 1500
$Comp
L Device:R R4
U 1 1 5FC56B64
P 4250 1500
F 0 "R4" V 4043 1500 50  0000 C CNN
F 1 "2k2" V 4134 1500 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.30x1.75mm_HandSolder" V 4180 1500 50  0001 C CNN
F 3 "~" H 4250 1500 50  0001 C CNN
	1    4250 1500
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5FC566CA
P 4750 1800
F 0 "#PWR?" H 4750 1550 50  0001 C CNN
F 1 "GND" H 4750 1650 50  0000 C CNN
F 2 "" H 4750 1800 50  0001 C CNN
F 3 "" H 4750 1800 50  0001 C CNN
	1    4750 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1700 4750 1800
Wire Wire Line
	4750 1000 4750 900 
Wire Wire Line
	4800 1000 4750 1000
Wire Wire Line
	4750 1200 4750 1300
Wire Wire Line
	4800 1200 4750 1200
$Comp
L Device:Q_NPN_BCE NPN1
U 1 1 5FC2434D
P 4650 1500
F 0 "NPN1" H 4840 1500 50  0000 L CNN
F 1 "Q_NPN_BCE" H 4841 1455 50  0001 L CNN
F 2 "Package_TO_SOT_SMD:SOT-223" H 4850 1600 50  0001 C CNN
F 3 "~" H 4650 1500 50  0001 C CNN
	1    4650 1500
	1    0    0    -1  
$EndComp
$Comp
L Device:Buzzer BZ1
U 1 1 5FC22312
P 4900 1100
F 0 "BZ1" H 5052 1129 50  0000 L CNN
F 1 "Buzzer" H 5052 1038 50  0000 L CNN
F 2 "Buzzer_Beeper:Buzzer_12x9.5RM7.6" V 4875 1200 50  0001 C CNN
F 3 "~" V 4875 1200 50  0001 C CNN
	1    4900 1100
	1    0    0    -1  
$EndComp
Wire Notes Line
	3550 550  3550 2250
Wire Notes Line
	550  5350 4600 5350
Wire Notes Line
	5650 2250 5650 550 
Wire Notes Line
	4700 4300 11150 4300
Wire Notes Line
	4700 2250 5650 2250
Wire Notes Line
	3550 2250 4600 2250
Wire Notes Line
	4700 4300 4700 2250
Wire Notes Line
	4600 2250 4600 5350
Wire Notes Line
	4700 4400 4700 7700
Text Label 3400 3200 2    39   ~ 0
SDA
Text Label 3400 3100 2    39   ~ 0
SCL
$Comp
L Connector_Generic:Conn_01x09 J3
U 1 1 60111879
P 10600 5400
F 0 "J3" H 10680 5442 50  0000 L CNN
F 1 "COM/TW" H 10680 5351 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x09_P2.54mm_Vertical" H 10600 5400 50  0001 C CNN
F 3 "~" H 10600 5400 50  0001 C CNN
	1    10600 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 3800 2600 3800
Text Label 2600 3800 2    39   ~ 0
BUZZER
$EndSCHEMATC
