/* 
 * File:   UART.c
 * Author: s.ammar
 *
 * Created on December 24, 2019, 11:37 AM
 */

#include <pic18f452.h>
#include "UART.h"
#include "definitions.h"


void UART_vdInit(unsigned short int baud){
	BRGH = 1;
    SPBRG = ((_XTAL_FREQ/16)/baud) - 1;
    TXSTAbits.SYNC = UART_MODE;         //MODE:Synch. or Asynch.
    RCSTAbits.SPEN = 1;
    TRISC6 = 0;
    TXSTAbits.TXEN = 1;                 //Enable transmission
}

void UART_vdSendByte(unsigned char data){
	while (!TXIF);		//wait for empty transmit buffer (NOTE:
											//it doesn't mean end of transmission because 
											//Transmission shift reg. may still transmitting the data
											//but i can write new data to transmit after the current 
											//in the UDR buffer reg.)
	TXREG = data;
}

void UART_vdSendu8asASCI(unsigned char data){
	unsigned char temp[3]; unsigned char i; unsigned char temp2 = data;
	for(i=0;i<3;i++){
		temp[i] = temp2%10;
		temp2 /= 10;
	} 
	if(temp[2]==0){
		if(temp[1]==0){
			UART_vdSendByte(temp[0]+48);
		}else{
			UART_vdSendByte(temp[1]+48);
			UART_vdSendByte(temp[0]+48);
		}		
	}else{
		UART_vdSendByte(temp[2]+48);
		UART_vdSendByte(temp[1]+48);
		UART_vdSendByte(temp[0]+48);
	}
	
}

void UART_vdSendu16asASCI(unsigned short int data){
	unsigned char temp[5]; unsigned char i; unsigned short int temp2 = data;
	for(i=0;i<5;i++){
		temp[i] = temp2%10;
		temp2 /= 10;
	} 
	if(temp[4]==0){
		if(temp[3]==0){
			if(temp[2]==0){
                if(temp[1]==0){
                    if(temp[0]==0){
                        UART_vdSendByte(temp[0]+48);
                    }else{
                        UART_vdSendByte(temp[0]+48);
                    }
                }else{
                    UART_vdSendByte(temp[1]+48);
                    UART_vdSendByte(temp[0]+48);
                }
            }else{
                UART_vdSendByte(temp[2]+48);
                UART_vdSendByte(temp[1]+48);
                UART_vdSendByte(temp[0]+48);
            }
		}else{
            UART_vdSendByte(temp[3]+48);
            UART_vdSendByte(temp[2]+48);
			UART_vdSendByte(temp[1]+48);
			UART_vdSendByte(temp[0]+48);
		}		
	}else{
        UART_vdSendByte(temp[4]+48);
        UART_vdSendByte(temp[3]+48);
		UART_vdSendByte(temp[2]+48);
		UART_vdSendByte(temp[1]+48);
		UART_vdSendByte(temp[0]+48);
	}
	
}