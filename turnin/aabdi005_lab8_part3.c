/*	Author: Abdirahman Abdi
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 * 
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif
unsigned long MAX = 767;
unsigned long x;

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1<< ADATE);
}

int main(void) {
    DDRA = 0x00; PORTA = 0xFF;
    DDRB = 0xFF; PORTB = 0x00;
    ADC_init();
    unsigned long tmpB = 0;
    while (1) {
        x = ADC;
        tmpB = (long)x; 
        if (tmpB >= MAX/2) {
            PORTB = 0x01;
        }
        else {
            PORTB = 0x00;
        }
    }
    return 1;
}