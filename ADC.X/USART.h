 
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>   
#include <stdio.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 20000000                 //CHANGE FOR DIFFERENT FREQUENCY
#define _BAUD_RATE 19200                    //CHANGE FOR DIFFERENT BAUD

void USART_INIT(void);                      //UART INITIALIZATION CODE HERE
void USART_SEND_CHAR(char ch);              //UART CHAR SENDING FUNCTION
void USART_SEND_STRING(char *str);          //UART STRING SENDING FUNCTION
void USART_SEND_INT(int val);               //UART INT SENDING FUNCTION


#endif	

