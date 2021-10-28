#include <avr/io.h>
#include "led.h"

int main () {
    InitLed();

    while(1){
        BlinkLed();
    }
    return 1;
}