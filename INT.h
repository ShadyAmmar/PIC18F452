/* 
 * File:   INT.h
 * Author: s.ammar
 *
 * Created on December 16, 2019, 2:22 PM
 */

#ifndef INT_H
#define	INT_H

#define ENABLED  1
#define DISABLED 0
#define RISING   1
#define FALLING  0


//Global interrupt
//#define GIE_BIT ENABLED

/**********Edge Triggered interrupt on PORTB pins:0,1,2**********************/
//Configuration
#define INT0_ENABLE DISABLED
#define INT1_ENABLE ENABLED
#define INT2_ENABLE DISABLED

#define INT0_EDGE RISING
#define INT1_EDGE RISING
#define INT2_EDGE RISING

/*************************Prototypes*****************************************/
void INT_vdinit(void);
void INT_vdSetINT0Callback(void (*pf)());
void INT_vdSetINT1Callback(void (*pf)());
void INT_vdSetINT2Callback(void (*pf)());

#endif	/* INT_H */

