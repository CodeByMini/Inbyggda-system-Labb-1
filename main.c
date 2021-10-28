#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
    uart_init();

    while(1){
        uart_echo();
    }
    return 1;
}