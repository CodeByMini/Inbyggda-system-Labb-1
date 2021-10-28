#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
    char * name = {"Daniel Johansson\n"};
    InitLed();
    uart_init();

    while(1){
        uart_putstr(name);
    }
    return 1;
}