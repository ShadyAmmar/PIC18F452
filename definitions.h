/* 
 * File: definitions  
 * Author: Shady Ammar
 * Comments: define registers addresses and accessing structures
 * Revision history: 9/11/2019
 */

#ifndef DEF_H
#define	DEF_H

/*General definitions*/
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

//External Devices
typedef struct{
    unsigned char PORT;
    unsigned char pin;
    unsigned char mode;
    unsigned char status;   //needed for buttons
    unsigned char temp1;    //needed for buttons    
    int i;                  //needed for buttons
} DEVICE;



/*Registers addresses*/
#define ADDR_PORTAdata (0xF80)
#define ADDR_PORTBdata (0xF81)
#define ADDR_PORTCdata (0xF82)
#define ADDR_PORTDdata (0xF83)
#define ADDR_PORTEdata (0xF84)

#define ADDR_LATA (0xF89)
#define ADDR_LATB (0xF8A)
#define ADDR_LATC (0xF8B)
#define ADDR_LATD (0xF8C)
#define ADDR_LATE (0xF8D)

#define ADDR_TRISA (0xF92)
#define ADDR_TRISB (0xF93)
#define ADDR_TRISC (0xF94)
#define ADDR_TRISD (0xF95)
#define ADDR_TRISE (0xF96)


/*Registers structures*/
//PORTA
typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RA0:1;
        volatile unsigned char RA1:1;
        volatile unsigned char RA2:1;
        volatile unsigned char RA3:1;
        volatile unsigned char RA4:1;
        volatile unsigned char RA5:1;
        volatile unsigned char RA6:1;
    };
}_PORTAdata;
volatile _PORTAdata* p_PORTAdata = (_PORTAdata*)ADDR_PORTAdata;
#define PORTAdata (*p_PORTAdata)

typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RA0:1;
        volatile unsigned char RA1:1;
        volatile unsigned char RA2:1;
        volatile unsigned char RA3:1;
        volatile unsigned char RA4:1;
        volatile unsigned char RA5:1;
        volatile unsigned char RA6:1;
        volatile unsigned char RA7:1;
    };
}_PORTAdirection;
volatile _PORTAdirection* p_PORTAdirection = (_PORTAdirection*)ADDR_TRISA;
#define PORTAdirection (*p_PORTAdirection)

//PORTB
typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RB0:1;
        volatile unsigned char RB1:1;
        volatile unsigned char RB2:1;
        volatile unsigned char RB3:1;
        volatile unsigned char RB4:1;
        volatile unsigned char RB5:1;
        volatile unsigned char RB6:1;
        volatile unsigned char RB7:1;
    };
}_PORTBdata;
volatile _PORTBdata* p_PORTBdata = (_PORTBdata*)ADDR_PORTBdata;
#define PORTBdata (*p_PORTBdata)

typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RB0:1;
        volatile unsigned char RB1:1;
        volatile unsigned char RB2:1;
        volatile unsigned char RB3:1;
        volatile unsigned char RB4:1;
        volatile unsigned char RB5:1;
        volatile unsigned char RB6:1;
        volatile unsigned char RB7:1;
    };
}_PORTBdirection;
volatile _PORTBdirection* p_PORTBdirection = (_PORTBdirection*)ADDR_TRISB;
#define PORTBdirection (*p_PORTBdirection)

//PORTD
typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RD0:1;
        volatile unsigned char RD1:1;
        volatile unsigned char RD2:1;
        volatile unsigned char RD3:1;
        volatile unsigned char RD4:1;
        volatile unsigned char RD5:1;
        volatile unsigned char RD6:1;
        volatile unsigned char RD7:1;
    };
}_PORTDdata;
volatile _PORTDdata* p_PORTDdata = (_PORTDdata*)ADDR_PORTDdata;
#define PORTDdata (*p_PORTDdata)

typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RD0:1;
        volatile unsigned char RD1:1;
        volatile unsigned char RD2:1;
        volatile unsigned char RD3:1;
        volatile unsigned char RD4:1;
        volatile unsigned char RD5:1;
        volatile unsigned char RD6:1;
        volatile unsigned char RD7:1;
    };
}_PORTDdirection;
volatile _PORTDdirection* p_PORTDdirection = (_PORTDdirection*)ADDR_TRISD;
#define PORTDdirection (*p_PORTDdirection)

#endif	

