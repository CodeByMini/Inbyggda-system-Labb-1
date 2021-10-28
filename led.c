#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void InitLed(){
    /*Set the DDRB registry for pin 9-11 to be an outputs*/
    DDRB |= (1<<BLUE_PIN);
    DDRB |= (1<<GREEN_PIN);
    DDRB |= (1<<RED_PIN);

    /*Flip the bits so they start high, ie: led off*/
    PORTB |= (1 << BLUE);
    PORTB |= (1 << GREEN);
    PORTB |= (1 << RED);
}

void BlinkLed(){

    /*using BIT_FLIP to change between 0(low) and 1(high) on pin 9 (blue). 
    low turns the led on and high turns it off since its an common anode*/
    BIT_FLIP(PORTB,PB1);
    
    /*using delay from util/delay for pausing between high and low*/
    _delay_ms(500);
}

void ChangeLedState(char*command){
        if(strcmp(command, "off\r\n")==0){
            PORTB |= (1 << BLUE); 
        }
        if(strcmp(command, "on\r\n")==0){
            PORTB &= ~(1 << BLUE); 
        }
        if(strcmp(command, "red\r\n")==0){
            BIT_FLIP(PORTB,RED);
        }
        if(strcmp(command, "green\r\n")==0){
            BIT_FLIP(PORTB,GREEN);
        }
}

    
