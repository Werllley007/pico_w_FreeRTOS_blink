/*
Visualizar no minicom:
alias minicompico='sudo minicom -b 115200 -o -D /dev/ttyACM0'
*/

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#define LED_BLUE 12


int main()
{
    stdio_init_all();
    gpio_init(LED_BLUE);
    gpio_set_slew_rate(LED_BLUE, GPIO_SLEW_RATE_SLOW);
    gpio_set_dir(LED_BLUE, true);
    
    while (true) {
        gpio_put(LED_BLUE,true);
        printf("Led Aceso\n");
        sleep_ms(500);
        gpio_put(LED_BLUE,false);
        printf("Led apagado!\n");
        sleep_ms(500);
    }
}
