/* 
 * File:   UART.h
 * Author: s.ammar
 *
 * Created on December 24, 2019, 11:37 AM
 */

#ifndef UART_H
#define	UART_H

#define UART_ASYNCH 0
#define UART_SYNC   1

/**********Configurations*****************************/
#define UART_MODE UART_ASYNCH


/**********Prototypes*********************************/
void UART_vdInit(unsigned short int baud);
void UART_vdSendByte(unsigned char data);
void UART_vdSendu8asASCI(unsigned char data);

#endif	/* UART_H */

