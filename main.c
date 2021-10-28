#include <avr/io.h>
#include "led.h"
#include "serial.h"

int main () {
    char *command[MAX_COMMAND_SIZE];
    InitLed();
    uart_init();

    while(1){
        uart_get_command(command);
        ChangeLedState(command);
    }
    return 1;
}