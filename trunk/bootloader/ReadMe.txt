/************************************************************************
**  Project: uSensor
**
**  Written By: 	Sam Kristoff
**  Written On: 	April 2012
**
**  bootloader
**
************************************************************************/

This is the uSensor Bootloader.  This folder contains code to flash uSensor devices with the USB bootloader using a programmer such as the PICKIT3.  Once a uSensor is programmed with the bootloader the sensor firmware can be updated via USB.  This allows users to update their firmware without special hardware.

The bootloader will go into firmware update mode if the current user firmware is corrupted or if RA4 (PIN 12) is held high during device bootup.