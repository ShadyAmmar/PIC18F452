/* 
 * File:   TMR3.h
 * Author: s.ammar
 *
 * Created on December 30, 2019
 */

#ifndef TMR3_H
#define	TMR3_H

#define R_W_16BIT       1
#define R_W_8BIT        0
#define TMR3_SCALE_8    0b11
#define TMR3_SCALE_4    0b10
#define TMR3_SCALE_2    0b01
#define TMR3_SCALE_1    0b00
#define EXT_SYNC_ON     0
#define EXT_SYNC_OFF    1
#define EXT_CLK         1
#define INT_CLK         0
#define PRE_SCALER_OFF  0
#define PRE_SCALER_ON   1
#define TIMER 0
#define COUNTER 1

void TMR3_vdInit(unsigned char mode,unsigned char bits,unsigned char prescaler,unsigned char prescaler_value,unsigned int init);
void TMR3_vdStop();
void TMR3_vdContinue();
void TMR3_vdReset();
void TMR3_vdSetTMR3Callback(void (*pf)());

#endif	/* TMR3_H */

