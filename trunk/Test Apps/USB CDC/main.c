
/** INCLUDES *******************************************************/
#include "uSensor_CPU_Config.h"

//uSensor Peripheral API Includes
#include "uSensor_API_USB_UART.h"

/** V A R I A B L E S ********************************************************/
char USB_In_Buffer[64];			//USB UART Input Buffer (To Send To Host)
char USB_Out_Buffer[64];		//USB UART Output Buffer (Received From Host)

unsigned int bytesIn = 0;		//The Number Of Bytes Received On USB UART
unsigned int totalBytes = 0;
int i;

/** P R I V A T E  P R O T O T Y P E S ***************************************/
void YourHighPriorityISRCode();
void YourLowPriorityISRCode();

//Main
int main(void)
{ 
	//Initialization
	//Microcontroller_Init();		//Initialize Microcontroller
	USBDeviceInit();			//Initialize USB Peripheral As Device
	
	TRISBbits.TRISB1 = 0;
	PORTBbits.RB1 = 0;
	
	//Main Loop
	while(1==1)
	{
	
		PORTBbits.RB1 = 1;	
					
		//If USB Peripheral Is In Detached State, But Is Connected To The Bus, Attach.
		if(USB_BUS_SENSE && (USBGetDeviceState() == DETACHED_STATE))
		{
		    USBDeviceAttach();
		}
		
		if( !((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1)) )	
		{
			bytesIn = getsUSBUSART(USB_Out_Buffer,64);
			if( bytesIn > 0)
			{
				for(i=0; i<bytesIn; i++)
				{
					USB_In_Buffer[i] = USB_Out_Buffer[i]+1;
				}
					
				putUSBUSART(USB_In_Buffer,bytesIn);				
			}	
		}			
		
		CDCTxService();	
	}
}

/********************************************************************
 * Function:        void ProcessIO(void)
 *
 * PreCondition:    None
 *
 * Input:           None
 *
 * Output:          None
 *
 * Side Effects:    None
 *
 * Overview:        This function is a place holder for other user
 *                  routines. It is a mixture of both USB and
 *                  non-USB tasks.
 *
 * Note:            None
 *******************************************************************
void ProcessIO(void)
{   
	
    BYTE numBytesRead;

    // User Application USB tasks
    if((USBDeviceState < CONFIGURED_STATE)||(USBSuspendControl==1)) return;

	
    if(buttonPressed)
    {
        if(stringPrinted == FALSE)
        {
            if(mUSBUSARTIsTxTrfReady())
            {
                putrsUSBUSART("Button Pressed -- \r\n");
                stringPrinted = TRUE;
            }
        }
    }
    else
    {
        stringPrinted = FALSE;
    }
	
	
	
    if(USBUSARTIsTxTrfReady())
    {
		numBytesRead = getsUSBUSART(USB_Out_Buffer,64);
		if(numBytesRead != 0)
		{
			BYTE i;
	        
			for(i=0;i<numBytesRead;i++)
			{
				switch(USB_Out_Buffer[i])
				{
					case 0x0A:
					case 0x0D:
						USB_In_Buffer[i] = USB_Out_Buffer[i];
						break;
					default:
						USB_In_Buffer[i] = USB_Out_Buffer[i] + 1;
						break;
				}

			}

			putUSBUSART(USB_In_Buffer,numBytesRead);
		}
	}

    CDCTxService();
}		//end ProcessIO
*/
/** EOF main.c *************************************************/

