/*
 * File:   main.c
 * Author: Subhranil Das
 *
 * Created on 20 September, 2020, 7:58 PM
 */
// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (RC oscillator) HS for external OSCILLATOR
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.



#include <xc.h>
#include <pic16f877a.h>
#include "USART.h"

#define _XTAL_FREQ 20000000




void main(void) {
    
    /* Registers for the configuration of ADC */
    ADCON1 = 0B11001110;                    
    ADCON0 = 0B10000001;
    // ADCON0 contains the bits to set channel for ADC
    /* End of ADC configuration */
    
    TRISB=0;                                // PORTB pins set as output
    PORTB=0;                                // PORTB pins set to low
    
    USART_INIT();
    
    while(1){
        ADCON0 |= (1<<2);                   // START ADC CONVERSION 
        while(ADCON0 & 0b00000100);         // WAIT UNTIL CONVERSION IS COMPLETE
        int val = ((ADRESH<<8)|ADRESL);     // PUT THE 10 BIT VALUE IN VAL
        
        
        if(val>100 && val<300) PORTB = 0b00000001;
        else if(val>=300 && val<500) PORTB = 0b00000011;
        else if(val>=500 && val<700) PORTB = 0b00000111;
        else if(val>=700 && val<900) PORTB = 0b00001111;
        else PORTB = 0b00000000;
        
        USART_SEND_INT(val);
        USART_SEND_STRING("\n");
        
        
        __delay_ms(100);
    }
    return;
}


