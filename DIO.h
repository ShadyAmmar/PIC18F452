/* 
 * File:   DIO.h
 * Author: Shady Ammar
 *
 * Created on November 9, 2019, 3:27 PM
 */

#ifndef DIO_H
#define	DIO_H

void DIO_vdInit(DEVICE* dev);
void DIO_vdWritePin(unsigned char data,unsigned char port,unsigned char pin);
void DIO_vdWriteDirPin(unsigned char data,unsigned char port,unsigned char pin);
void DIO_vdWritePort(unsigned char data,unsigned char port);
void DIO_vdtogglePin(unsigned char port,unsigned char pin);
unsigned char DIO_u8ReadPin(unsigned char port,unsigned char pin);
unsigned char DIO_u8ReadPort(unsigned char port);

#endif	/* DIO_H */

