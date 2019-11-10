/*
 * File:   LED.c
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 3:26 PM
 */

#include <xc.h>
#include "definitions.h"
#include "DIO.h" 
#include "LED.h"

void LED_vdOn(DEVICE led){
	DIO_vdWritePin(HIGH,led.PORT,led.pin);
}

void LED_vdOff(DEVICE led){
	DIO_vdWritePin(LOW,led.PORT,led.pin);
}

void LED_vdtoggle(DEVICE led){
	DIO_vdtogglePin(led.PORT,led.pin);
}
