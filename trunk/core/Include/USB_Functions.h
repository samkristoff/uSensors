#include "GenericTypeDefs.h"
#include "USB/usb.h"

#ifndef USB_FUNCTIONS_H
	#define USB_FUNCTIONS_H
	
	//Fucntion Prototypes
	void USBCBSuspend(void);
	void USBCBWakeFromSuspend(void);
	void USBCB_SOF_Handler(void);
	void USBCBErrorHandler(void);
	void USBCBCheckOtherReq(void);
	void USBCBStdSetDscHandler(void);
	void USBCBInitEP(void);
	void USBCBSendResume(void);
	void USBCBEP0DataReceived(void);
	BOOL USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, WORD size);
	
#endif	//USB_FUNCTIONS_H