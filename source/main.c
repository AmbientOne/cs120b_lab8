/*	Author: Abdirahman Abdi
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #8  Exercise #4
 *	Exercise Description: [optional - include for your own benefit]
 * 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned long  MAX = 767;
unsigned long x ;
unsigned long  led;
void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1<< ADATE);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    ADC_init();
    unsigned long tmpB;
    while (1) {
        x = 0x00;
        led = MAX/8;
        x = ADC;
        tmpB = (long)x; 
        if(tmpB <= led){
            PORTB = 0x01;
        }else if(tmpB <= led * 2){
            PORTB = 0x03;
        }else if(tmpB <= led * 3){
               PORTB = 0x07;
        } else if(tmpB <= led * 4){
               PORTB = 0x0F;
        } else if(tmpB <= led * 5){
               PORTB = 0x1F;
        } else if(tmpB <= led * 6){
               PORTB = 0x3F;
        } else if(tmpB <= led * 7){
               PORTB = 0x7F;
        } else if(tmpB <= led * 8){
               PORTB = 0xFF;
        }
    }
    return 1;
}