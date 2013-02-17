//uSensor_USB_UART.h

//USB Includes
#include "USB_Functions.h"
#include "GenericTypeDefs.h"
#include "Compiler.h"
#include "HardwareProfile.h"
#include "usb_config.h"
#include "USB/usb.h"
#include "USB/usb_function_cdc.h"
#include "USB/usb_device.h"
#include "USB/usb.h"



/************************************************************************
**	USB_UART_Init() - Initialize USB UART With The Default Settings And 
**				  	  User Specified Baud Rates.
**
**	Parameters - Baud_Rate - Desired Baud Rate For UART
**				 
**	Return - None			 
**************************************************************************/
void USB_UART_Init(unsigned int Baud_Rate);