/*
 * File:   USART.c
 * Author: subhr
 *
 * Created on 22 September, 2020, 7:17 PM
 */


#include <USART.h>

void USART_INIT(void){
    
    SPBRG = ((_XTAL_FREQ/16)/_BAUD_RATE) - 1;       // 19200 baud in high speed mode
    TXSTA = 0b00100100;                             // transmit enable, async, high speed mode
    RCSTA = 0b10010000;                             // serial port enable, continuous receive enable
    TRISC = 0b10000000;
    
    INTCON |= 1<<7;                                 // GIE bit set
    INTCON |= 1<<6;                                 // PEIE bit set
    PIE1 |= 1<<5;                                   // RCIE (receive interrupt enable)
}
void USART_SEND_CHAR(char ch){
    while(!TRMT);
    TXREG = ch;       
}

void USART_SEND_STRING(char *str){
    int i;
    for(i=0;str[i]!='\0';i++)
    USART_SEND_CHAR(str[i]); 
}
void USART_SEND_INT(int val){       
    char str[10];
    sprintf(str, "%d", val);        
    USART_SEND_STRING(str);
}



/* Interrupt routine below */
void __interrupt() isr(void){       // all interrupt routines go here check for each
    char received = RCREG;          // serial receiver register data stored
    USART_SEND_CHAR(received);      // data is sent back through ex register                     // 
}