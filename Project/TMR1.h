/* 
 * File:   TMR1.h
 * Author: s.ammar
 *
 * Created on December 18, 2019, 11:23 AM
 */

#ifndef TMR1_H
#define	TMR1_H

#define R_W_16BIT       1
#define R_W_8BIT        0
#define TMR1_SCALE_8    0b11
#define TMR1_SCALE_4    0b10
#define TMR1_SCALE_2    0b01
#define TMR1_SCALE_1    0b00
#define EXT_SYNC_ON     0
#define EXT_SYNC_OFF    1
#define EXT_CLK         1
#define INT_CLK         0
#define TMR1_OSC_EN     1
#define TMR1_OSC_DES    0
#define PRE_SCALER_OFF  0
#define PRE_SCALER_ON   1
#define TIMER 0
#define COUNTER 1

void TMR1_vdInit(unsigned char mode,unsigned char bits,unsigned char prescaler,unsigned char prescaler_value,unsigned int init);
void TMR1_vdStop();
void TMR1_vdContinue();
void TMR1_vdReset();
void TMR1_vdSetTMR1Callback(void (*pf)());

#endif	/* TMR1_H */

