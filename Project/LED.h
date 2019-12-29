/* 
 * File:   LED.h
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 3:35 PM
 */

#ifndef LED_H
#define	LED_H

void LED_vdOn(DEVICE* led);
void LED_vdOff(DEVICE* led);
void LED_vdtoggle(DEVICE* led);
void LED_vdSetStatus(DEVICE* led,unsigned char status);

#endif	/* LED_H */

