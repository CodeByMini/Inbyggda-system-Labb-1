#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "serial.h"

// (TX) enligt 8N1 i 38400 baud.
#define BAUD 38400
#define BRC (((F_CPU /(16*BAUD)))-1)

void uart_init(){
    /*Set baudrate to registers*/
    UBRR0H = ((BRC) >> 8);
    UBRR0L = BRC;

    /* Sets TX and RX bits to 1 thus enabling transmission and reception */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);

    /* 8N1 will be set by default */
    /* buuut...lets do it anyway */
    UCSR0C = 0
    | (0<<UPM01) | (0<<UPM00)       // Parity Disabled
    | (0<<USBS0)                    // 1 stop bit
    | (1<<UCSZ01) | (1<<UCSZ00) ;   // 8 bit data
}

bool SerialAvailable(){
    if(!(UCSR0A & (1 << UDRE0))){
        return false;
    }
    return true;
}

/* Sends a charachter to the serial interface*/
void uart_putchar(char chr){
    if(chr =='\r' || chr =='\n'){
        while (!SerialAvailable());
        UDR0 = '\r';
        while (!SerialAvailable());
        UDR0  = '\n';
    }
    else{
        while (!SerialAvailable());
        UDR0 = chr;
    }
}
/* send a string to uart */
void uart_putstr(char *name){
    int i = 0;
    while(name[i] !='\0'){
        uart_putchar(name[i]);
        i++;
    }
}

char uart_getchar(){
    char chr;
        while(!(UCSR0A & (1 << RXC0)));
        chr = UDR0;
return chr;
}

void uart_echo(){
    uart_putchar(uart_getchar());
}

