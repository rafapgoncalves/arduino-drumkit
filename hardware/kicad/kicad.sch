EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino-drumkit
LIBS:kicad-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L GND #PWR02
U 1 1 5D6915E5
P 5650 3150
F 0 "#PWR02" H 5650 2900 50  0001 C CNN
F 1 "GND" H 5650 3000 50  0000 C CNN
F 2 "" H 5650 3150 50  0001 C CNN
F 3 "" H 5650 3150 50  0001 C CNN
	1    5650 3150
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG03
U 1 1 5D6915FC
P 2450 3050
F 0 "#FLG03" H 2450 3125 50  0001 C CNN
F 1 "PWR_FLAG" H 2450 3200 50  0000 C CNN
F 2 "" H 2450 3050 50  0001 C CNN
F 3 "" H 2450 3050 50  0001 C CNN
	1    2450 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 3350 5400 3350
Wire Wire Line
	5400 3350 5400 3100
Wire Wire Line
	5400 3100 5650 3100
Wire Wire Line
	5650 3100 5650 3150
$Comp
L Piezo Piezo8
U 1 1 5D691739
P 6150 2900
F 0 "Piezo8" H 6150 3050 50  0000 C CNN
F 1 "Piezo" H 6150 2750 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 6150 2900 50  0001 C CNN
F 3 "" H 6150 2900 50  0001 C CNN
	1    6150 2900
	0    1    1    0   
$EndComp
$Comp
L R R8
U 1 1 5D691770
P 6400 2900
F 0 "R8" V 6480 2900 50  0000 C CNN
F 1 "1M" V 6400 2900 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 6330 2900 50  0001 C CNN
F 3 "" H 6400 2900 50  0001 C CNN
	1    6400 2900
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo7
U 1 1 5D691AB2
P 6700 2800
F 0 "Piezo7" H 6700 2950 50  0000 C CNN
F 1 "Piezo" H 6700 2650 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 6700 2800 50  0001 C CNN
F 3 "" H 6700 2800 50  0001 C CNN
	1    6700 2800
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 5D691AB8
P 6950 2800
F 0 "R7" V 7030 2800 50  0000 C CNN
F 1 "1M" V 6950 2800 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 6880 2800 50  0001 C CNN
F 3 "" H 6950 2800 50  0001 C CNN
	1    6950 2800
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo6
U 1 1 5D691B1E
P 7250 2700
F 0 "Piezo6" H 7250 2850 50  0000 C CNN
F 1 "Piezo" H 7250 2550 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 7250 2700 50  0001 C CNN
F 3 "" H 7250 2700 50  0001 C CNN
	1    7250 2700
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 5D691B24
P 7500 2700
F 0 "R6" V 7580 2700 50  0000 C CNN
F 1 "1M" V 7500 2700 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 7430 2700 50  0001 C CNN
F 3 "" H 7500 2700 50  0001 C CNN
	1    7500 2700
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo5
U 1 1 5D691B76
P 7800 2600
F 0 "Piezo5" H 7800 2750 50  0000 C CNN
F 1 "Piezo" H 7800 2450 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 7800 2600 50  0001 C CNN
F 3 "" H 7800 2600 50  0001 C CNN
	1    7800 2600
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 5D691B7C
P 8050 2600
F 0 "R5" V 8130 2600 50  0000 C CNN
F 1 "1M" V 8050 2600 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 7980 2600 50  0001 C CNN
F 3 "" H 8050 2600 50  0001 C CNN
	1    8050 2600
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo4
U 1 1 5D691BC8
P 8350 2500
F 0 "Piezo4" H 8350 2650 50  0000 C CNN
F 1 "Piezo" H 8350 2350 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 8350 2500 50  0001 C CNN
F 3 "" H 8350 2500 50  0001 C CNN
	1    8350 2500
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 5D691BCE
P 8600 2500
F 0 "R4" V 8680 2500 50  0000 C CNN
F 1 "1M" V 8600 2500 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 8530 2500 50  0001 C CNN
F 3 "" H 8600 2500 50  0001 C CNN
	1    8600 2500
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo3
U 1 1 5D691CF6
P 8900 2400
F 0 "Piezo3" H 8900 2550 50  0000 C CNN
F 1 "Piezo" H 8900 2250 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 8900 2400 50  0001 C CNN
F 3 "" H 8900 2400 50  0001 C CNN
	1    8900 2400
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5D691CFC
P 9150 2400
F 0 "R3" V 9230 2400 50  0000 C CNN
F 1 "1M" V 9150 2400 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 9080 2400 50  0001 C CNN
F 3 "" H 9150 2400 50  0001 C CNN
	1    9150 2400
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo2
U 1 1 5D691E1C
P 9450 2300
F 0 "Piezo2" H 9450 2450 50  0000 C CNN
F 1 "Piezo" H 9450 2150 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 9450 2300 50  0001 C CNN
F 3 "" H 9450 2300 50  0001 C CNN
	1    9450 2300
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 5D691E22
P 9700 2300
F 0 "R2" V 9780 2300 50  0000 C CNN
F 1 "1M" V 9700 2300 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 9630 2300 50  0001 C CNN
F 3 "" H 9700 2300 50  0001 C CNN
	1    9700 2300
	1    0    0    -1  
$EndComp
$Comp
L Piezo Piezo1
U 1 1 5D691E80
P 10000 2200
F 0 "Piezo1" H 10000 2350 50  0000 C CNN
F 1 "Piezo" H 10000 2050 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 10000 2200 50  0001 C CNN
F 3 "" H 10000 2200 50  0001 C CNN
	1    10000 2200
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 5D691E86
P 10250 2200
F 0 "R1" V 10330 2200 50  0000 C CNN
F 1 "1M" V 10250 2200 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 10180 2200 50  0001 C CNN
F 3 "" H 10250 2200 50  0001 C CNN
	1    10250 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5300 2700 6400 2700
Wire Wire Line
	6150 2700 6150 2750
Wire Wire Line
	6400 2700 6400 2750
Connection ~ 6150 2700
Wire Wire Line
	5300 2600 6950 2600
Wire Wire Line
	6700 2600 6700 2650
Wire Wire Line
	6950 2600 6950 2650
Connection ~ 6700 2600
Wire Wire Line
	5300 2500 7500 2500
Wire Wire Line
	7250 2500 7250 2550
Wire Wire Line
	7500 2500 7500 2550
Connection ~ 7250 2500
Wire Wire Line
	5300 2400 8050 2400
Wire Wire Line
	7800 2400 7800 2450
Wire Wire Line
	8050 2400 8050 2450
Connection ~ 7800 2400
Wire Wire Line
	5300 2300 8600 2300
Wire Wire Line
	8350 2300 8350 2350
Wire Wire Line
	8600 2300 8600 2350
Connection ~ 8350 2300
Wire Wire Line
	5300 2200 9150 2200
Wire Wire Line
	8900 2200 8900 2250
Wire Wire Line
	9150 2200 9150 2250
Connection ~ 8900 2200
Wire Wire Line
	5300 2100 9700 2100
Wire Wire Line
	9450 2100 9450 2150
Wire Wire Line
	9700 2100 9700 2150
Connection ~ 9450 2100
Wire Wire Line
	5300 2000 10250 2000
Wire Wire Line
	10000 2000 10000 2050
Wire Wire Line
	10250 2000 10250 2050
Connection ~ 10000 2000
Wire Wire Line
	6150 3050 6150 3100
Wire Wire Line
	6150 3100 10250 3100
Wire Wire Line
	10250 3100 10250 2350
Wire Wire Line
	6400 3050 6400 3100
Connection ~ 6400 3100
Wire Wire Line
	6700 2950 6700 3100
Connection ~ 6700 3100
Wire Wire Line
	6950 2950 6950 3100
Connection ~ 6950 3100
Wire Wire Line
	7250 2850 7250 3100
Connection ~ 7250 3100
Wire Wire Line
	7500 2850 7500 3100
Connection ~ 7500 3100
Wire Wire Line
	7800 2750 7800 3100
Connection ~ 7800 3100
Wire Wire Line
	8050 2750 8050 3100
Connection ~ 8050 3100
Wire Wire Line
	8350 2650 8350 3100
Connection ~ 8350 3100
Wire Wire Line
	8600 2650 8600 3100
Connection ~ 8600 3100
Wire Wire Line
	8900 2550 8900 3100
Connection ~ 8900 3100
Wire Wire Line
	9150 2550 9150 3100
Connection ~ 9150 3100
Wire Wire Line
	9450 2450 9450 3100
Connection ~ 9450 3100
Wire Wire Line
	9700 2450 9700 3100
Connection ~ 9700 3100
Wire Wire Line
	10000 2350 10000 3100
Connection ~ 10000 3100
$Comp
L GND #PWR04
U 1 1 5D69276E
P 8200 3200
F 0 "#PWR04" H 8200 2950 50  0001 C CNN
F 1 "GND" H 8200 3050 50  0000 C CNN
F 2 "" H 8200 3200 50  0001 C CNN
F 3 "" H 8200 3200 50  0001 C CNN
	1    8200 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 3200 8200 3100
Connection ~ 8200 3100
$Comp
L SW_Push SW2
U 1 1 5D692B34
P 1800 3900
F 0 "SW2" H 1850 4000 50  0000 L CNN
F 1 "SW_Push" H 1800 3840 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 1800 4100 50  0001 C CNN
F 3 "" H 1800 4100 50  0001 C CNN
	1    1800 3900
	0    -1   -1   0   
$EndComp
$Comp
L SW_Push SW3
U 1 1 5D692C33
P 2100 3900
F 0 "SW3" H 2150 4000 50  0000 L CNN
F 1 "SW_Push" H 2100 3840 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 2100 4100 50  0001 C CNN
F 3 "" H 2100 4100 50  0001 C CNN
	1    2100 3900
	0    -1   -1   0   
$EndComp
$Comp
L SW_Push SW1
U 1 1 5D692C5B
P 1500 3900
F 0 "SW1" H 1550 4000 50  0000 L CNN
F 1 "SW_Push" H 1500 3840 50  0000 C CNN
F 2 "arduino-drumkit:External_2_14.224mm" H 1500 4100 50  0001 C CNN
F 3 "" H 1500 4100 50  0001 C CNN
	1    1500 3900
	0    -1   -1   0   
$EndComp
$Comp
L R R9
U 1 1 5D692CD8
P 1500 3250
F 0 "R9" V 1580 3250 50  0000 C CNN
F 1 "10K" V 1500 3250 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 1430 3250 50  0001 C CNN
F 3 "" H 1500 3250 50  0001 C CNN
	1    1500 3250
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 5D692F27
P 1800 3250
F 0 "R10" V 1880 3250 50  0000 C CNN
F 1 "10K" V 1800 3250 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 1730 3250 50  0001 C CNN
F 3 "" H 1800 3250 50  0001 C CNN
	1    1800 3250
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 5D692F5C
P 2100 3250
F 0 "R11" V 2180 3250 50  0000 C CNN
F 1 "10K" V 2100 3250 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 2030 3250 50  0001 C CNN
F 3 "" H 2100 3250 50  0001 C CNN
	1    2100 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	2700 3050 2700 3350
Wire Wire Line
	1500 3050 1500 3100
Wire Wire Line
	1800 3100 1800 3050
Connection ~ 1800 3050
Wire Wire Line
	2100 3100 2100 3050
Connection ~ 2100 3050
Wire Wire Line
	1500 3400 1500 3700
Wire Wire Line
	1500 3450 2700 3450
Wire Wire Line
	1800 3400 1800 3700
Wire Wire Line
	1800 3550 2700 3550
Wire Wire Line
	2100 3400 2100 3700
Wire Wire Line
	2100 3650 2700 3650
Connection ~ 2100 3650
Connection ~ 1800 3550
Connection ~ 1500 3450
$Comp
L GND #PWR05
U 1 1 5D693398
P 1800 4200
F 0 "#PWR05" H 1800 3950 50  0001 C CNN
F 1 "GND" H 1800 4050 50  0000 C CNN
F 2 "" H 1800 4200 50  0001 C CNN
F 3 "" H 1800 4200 50  0001 C CNN
	1    1800 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 4100 1800 4200
Wire Wire Line
	1500 4150 2100 4150
Wire Wire Line
	2100 4150 2100 4100
Connection ~ 1800 4150
Wire Wire Line
	1500 4150 1500 4100
$Comp
L GND #PWR06
U 1 1 5D6940E7
P 5850 3650
F 0 "#PWR06" H 5850 3400 50  0001 C CNN
F 1 "GND" H 5850 3500 50  0000 C CNN
F 2 "" H 5850 3650 50  0001 C CNN
F 3 "" H 5850 3650 50  0001 C CNN
	1    5850 3650
	1    0    0    -1  
$EndComp
$Comp
L ArduinoNano XA1
U 1 1 5D695348
P 4000 2750
F 0 "XA1" V 4100 2750 60  0000 C CNN
F 1 "ArduinoNano" V 3900 2750 60  0000 C CNN
F 2 "arduino-drumkit:ArduinoNanoJacks" H 5800 6500 60  0001 C CNN
F 3 "" H 5800 6500 60  0001 C CNN
	1    4000 2750
	-1   0    0    1   
$EndComp
$Comp
L R R12
U 1 1 5DC34B60
P 4900 3950
F 0 "R12" V 4980 3950 50  0000 C CNN
F 1 "220K" V 4900 3950 50  0000 C CNN
F 2 "arduino-drumkit:R_L6.22mm_D2.3mm_P10.16mm_Horizontal" V 4830 3950 50  0001 C CNN
F 3 "" H 4900 3950 50  0001 C CNN
	1    4900 3950
	0    1    1    0   
$EndComp
$Comp
L DIN-5_180degree J1
U 1 1 5DC34D21
P 5550 4050
F 0 "J1" H 5675 4275 50  0000 C CNN
F 1 "DIN-5_180degree" H 5550 3800 50  0000 C CNN
F 2 "arduino-drumkit:Din5-180" H 5550 4050 50  0001 C CNN
F 3 "" H 5550 4050 50  0001 C CNN
	1    5550 4050
	1    0    0    -1  
$EndComp
NoConn ~ 5250 4050
NoConn ~ 5850 4050
Wire Wire Line
	1250 3050 2700 3050
Connection ~ 2450 3050
Wire Wire Line
	6050 3950 5850 3950
Wire Wire Line
	6050 3550 6050 3950
Wire Wire Line
	6050 3550 5300 3550
Wire Wire Line
	5050 3950 5250 3950
Wire Wire Line
	1250 3050 1250 4550
Wire Wire Line
	1250 4550 2350 4550
Wire Wire Line
	2350 4550 2350 3950
Wire Wire Line
	2350 3950 4750 3950
Connection ~ 1500 3050
Wire Wire Line
	5850 3650 5550 3650
Wire Wire Line
	5550 3650 5550 3750
NoConn ~ 5300 3450
NoConn ~ 5300 3650
$EndSCHEMATC
