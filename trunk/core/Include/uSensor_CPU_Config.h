/************************************************************************
**	Project: uSensor_API
**
**	uSensor_CPU_Config.h - Header File For PIC32MX2XX CPU Configuration
**
**	Written By: 	Sam Kristoff
**  Written On: 	April 2012
**  Last Updated: 	April 2012
**
**	Contains CPU Configuration Directives For PIC32MX2XX
**
************************************************************************/
#ifndef USENSOR_CPU_CONFIG_H
#define USENSOR_CPU_CONFIG_H
	
	//DEVCFG0
	#pragma config DEBUG = ON				//Background Debugger Enabled
	#pragma config JTAGEN = OFF				//JTAG Disabled
	#pragma config ICESEL = ICS_PGx3 		//ICE/ICD Comm Channel : Communicate on PGEC3/PGED3 
	#pragma config PWP = OFF				//Program Flash Write Protect : Disabled
	#pragma config BWP = OFF				//Boot Flash Write Protect Disabled
	#pragma config CP = OFF					//Code Protect : Protection Disabled 
	
	//DEVCFG1
	#pragma config FNOSC = PRIPLL			//Primary Oscillator With PLL
	#pragma config FSOSCEN = OFF			//Secondary Oscillator Disabled
	#pragma config IESO = OFF				//Internal/External Switch Over Disabled
	#pragma config POSCMOD = HS				//High Speed Oscillator Mode
	#pragma config OSCIOFNC = OFF			//CLKO Output Signal Active on the OSCO Pin Disabled
	#pragma config FPBDIV = DIV_1			//Pb_Clk is Sys_Clk/1
	#pragma config FCKSM = CSDCMD			//Clock Switching and Monitor Selection Disabled
	#pragma config WDTPS = PS1024			//Watchdog Timer Postscaler 1:1024
	#pragma config WINDIS = OFF				//Watchdog Timer is in Non-Window Mode
	#pragma config FWDTEN = OFF				//WDT Disabled (SWDTEN Bit Controls) 
	#pragma config FWDTWINSZ = WISZ_25		//Watchdog Timer Window Size is 25%
	
	//DEVCFG2	
	//FRC Osc = 8MHz	System Clock = [ (20MHz/2) * 16 ] / 4 = 40MHz
	#pragma config FPLLIDIV = DIV_2			//PLL Input Divider : 2x Divider 
	#pragma config FPLLMUL = MUL_16			//PLL Multiplier : 16x Multiplier
	#pragma config FPLLODIV = DIV_4			//System PLL Output Clock Divider : PLL Divide by 4	
	#pragma config UPLLEN = ON				//USB PLL Enabled
	#pragma config UPLLIDIV = DIV_5			//USB PLL Input Divider: 5x Divider 
	
	
	
	//DEVCFG3
	//#pragma config USERID = 0x534B				
	#pragma config PMDL1WAY = ON			//Peripheral Module Disable Configuration: Allow only one reconfiguration 
	#pragma config IOL1WAY = ON				//Peripheral Pin Select Configuration: Allow only one reconfiguration 
	#pragma config FUSBIDIO = OFF			//USB USID Controlled by Port Function 
	#pragma config FVBUSONIO = ON			//USB VBUS ON Selection : Controlled by USB Module 
	
#endif //USENSOR_CPU_CONFIG_H
	
	
	