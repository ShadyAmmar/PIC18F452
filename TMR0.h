/* 
 * File:   TMR0.h
 * Author: s.ammar
 *
 * Created on December 16, 2019, 4:31 PM
 */

#ifndef TMR0_H
#define	TMR0_H

/*definitions*/
#define TIMER 0
#define COUNTER 1
#define BIT8 0
#define BIT16 1
#define LOW_TO_HIGH 0
#define HIGH_TO_LOW 1
#define PRE_SCALER_OFF 0
#define PRE_SCALER_ON 1
#define SCALE_2   0b000
#define SCALE_4   0b001
#define SCALE_8   0b010
#define SCALE_16  0b011
#define SCALE_32  0b100
#define SCALE_64  0b101
#define SCALE_128 0b110
#define SCALE_256 0b111

/*Prototypes*/
TMR0_vdInit(unsigned char mode,unsigned char bits,unsigned char edge,unsigned char prescaler,unsigned char prescaler_value);

#endif	/* TMR0_H */

