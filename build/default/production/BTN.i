# 1 "BTN.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files (x86)\\Microchip\\xc8\\v2.05\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "BTN.c" 2







# 1 "./BTN.h" 1
# 11 "./BTN.h"
# 1 "./definitions.h" 1
# 19 "./definitions.h"
typedef struct{
    unsigned char PORT;
    unsigned char pin;
    unsigned char mode;
    unsigned char status;
    unsigned char temp1;
    int i;
} DEVICE;
# 52 "./definitions.h"
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
volatile _PORTAdata* p_PORTAdata = (_PORTAdata*)(0xF80);


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
volatile _PORTAdirection* p_PORTAdirection = (_PORTAdirection*)(0xF92);



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
volatile _PORTBdata* p_PORTBdata = (_PORTBdata*)(0xF81);


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
volatile _PORTBdirection* p_PORTBdirection = (_PORTBdirection*)(0xF93);



typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RC0:1;
        volatile unsigned char RC1:1;
        volatile unsigned char RC2:1;
        volatile unsigned char RC3:1;
        volatile unsigned char RC4:1;
        volatile unsigned char RC5:1;
        volatile unsigned char RC6:1;
        volatile unsigned char RC7:1;
    };
}_PORTCdata;
volatile _PORTCdata* p_PORTCdata = (_PORTCdata*)(0xF82);


typedef union{
    volatile unsigned char PORT;
    struct{
        volatile unsigned char RC0:1;
        volatile unsigned char RC1:1;
        volatile unsigned char RC2:1;
        volatile unsigned char RC3:1;
        volatile unsigned char RC4:1;
        volatile unsigned char RC5:1;
        volatile unsigned char RC6:1;
        volatile unsigned char RC7:1;
    };
}_PORTCdirection;
volatile _PORTCdirection* p_PORTCdirection = (_PORTCdirection*)(0xF94);



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
volatile _PORTDdata* p_PORTDdata = (_PORTDdata*)(0xF83);


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
volatile _PORTDdirection* p_PORTDdirection = (_PORTDdirection*)(0xF95);
# 11 "./BTN.h" 2





unsigned char BTN_u8getFilteredStatus(DEVICE* btn);
void BTN_vdRead(DEVICE* btn);
unsigned char BTN_u8getStatus(DEVICE* btn);
# 8 "BTN.c" 2

# 1 "./DIO.h" 1
# 11 "./DIO.h"
void DIO_vdInit(DEVICE* dev);
void DIO_vdWritePin(unsigned char data,unsigned char port,unsigned char pin);
void DIO_vdWriteDirPin(unsigned char data,unsigned char port,unsigned char pin);
void DIO_vdWritePort(unsigned char data,unsigned char port);
void DIO_vdtogglePin(unsigned char port,unsigned char pin);
unsigned char DIO_u8ReadPin(unsigned char port,unsigned char pin);
unsigned char DIO_u8ReadPort(unsigned char port);
# 9 "BTN.c" 2



static unsigned char BTNstatus[] = {0,0,0,0,0,0,0,0};

unsigned char BTN_u8getFilteredStatus(DEVICE* btn){
 switch( btn->status )
 {
  case 1 :
  return 1;
  break;
  case 0 :
  return 0;
  break;
  case 3 :
  return 3;
  break;
 }
 return 1;
}







void BTN_vdRead(DEVICE* btn){
 unsigned char temp2 = DIO_u8ReadPin(btn->PORT,btn->pin);

 if(btn->temp1 == temp2){
  (btn->i)++;
 }else{
  btn->temp1 = temp2;
  btn->i =1;
 }

 if(btn->i % 3 == 0){
  btn->status = temp2;
  btn->i =0;
 }

 if(btn->i == 400 && btn->status==1){
  btn->status = 3;
  btn->i = 0;
 }
}

unsigned char BTN_u8getStatus(DEVICE* btn){
 return DIO_u8ReadPin(btn->PORT,btn->pin);
}
