/*
 * File:   main.c
 * Author: subhr
 *
 * Created on 22 September, 2020, 9:41 PM
 */
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#include <pic16f877a.h>

int i = 0;

void TIM0_INIT(void);
void main(void) {
    
    TIM0_INIT();
    TRISB = 0x00;               // PORT B SET TO OUTPUT
    PORTB = 0x00;               // ALL PORT PINS SET TO LOW
    while(1){
        
    }
    return;
}
void TIM0_INIT(void){
    T0CS = 0;                   // TIMER 0 CLK SOURCE SET TO SYSTEM CLK
    T0SE = 1;                   // INCREMENT ON HIGH TO LOW
    PSA = 0;                    // PRESCALAR ASSIGNED TO TIMER0 NOT WDT
    PS2 = 1;                    // SET FOR 256 PRESCALAR
    PS1 = 1;                    // SET FOR 256 PRESCALAR
    PS0 = 1;                    // SET FOR 256 PRESCALAR
    GIE = 1;                    // GLOBAL INTERRUPT ENABLE BIT SET
    PEIE = 1;                   // PERIPHERAL INTERRUPT ENABLE BIT SET
    TMR0IE =1;                  // TIMER 0 INTERRUPT ENABLE
}

void __interrupt() ISR(void){
    if(TMR0IF == 1){            // CHECKING TIMER 0 INTERRUPT FLAG
        TMR0IF = 0;             // IF SET THE FLAG IS CLEARED
        i++;
        if(i > 76){             // GIVES APPROXIMATELY 1 SECOND ON/OFF TIME
            i = 0;
            PORTB ^= 0x0F;
        }   
    }
}