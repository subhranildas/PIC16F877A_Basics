/*
 * File:   main.c
 * Author: Subhranil Das
 *
 * Created on 20 September, 2020, 8:52 PM
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#define _XTAL_FREQ 20000000

#include <xc.h>
#include <pic16f877a.h>
#include <USART.h>
void USART_INIT(void);                      //UART INITIALIZATION CODE HERE
void USART_SEND_CHAR(char ch);              //UART CHAR SENDING FUNCTION
void USART_SEND_STRING(char *str);          //UART STRING SENDING FUNCTION
void USART_SEND_INT(int val);               //UART INT SENDING FUNCTION

void main(void){
    
    USART_INIT();
    
    while(1){
           
        
        /*
        USART_SEND_STRING("Subhranil Das \n");
        __delay_ms(1000);
        USART_SEND_INT(i);
        i++;
        __delay_ms(1000);
        */
    }
    return;
}

