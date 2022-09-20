/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// API documentation: https://raspberrypi.github.io/pico-sdk-doxygen/modules.html

// Fade an LED between low and high brightness.
// An interrupt handler updates the PWM slice's output level each time the counter wraps.

#include "pico/stdlib.h"
#include <stdint.h>
#include <stdbool.h>
#include "pico/time.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"
#include <string.h>

#ifndef PICO_DEFAULT_LED_PIN
#error pwm/led_fade example requires a board with a regular LED
#endif

#define max_on_time 800
#define min_on_time 250
#define cst_off_time 250


void on_pwm_wrap() {
    
    //sos equals in morse code is repersented by '...---...'
    static char str[] = "...---...";
    int count = 0;
    do{
        int on_time, off_time;
        switch(str[count]){
            case'.':
                on_time = min_on_time;
                off_time = cst_off_time;
                break;
            case'-':
                on_time = max_on_time;
                off_time = cst_off_time;
                break;
        }
        count++;

        //PWM level ranges from 10Hz to 8kHz
        pwm_set_gpio_level(PICO_DEFAULT_LED_PIN, 8000);
        busy_wait_ms (on_time);
        pwm_set_gpio_level(PICO_DEFAULT_LED_PIN, 30);
        busy_wait_ms (off_time);

    }while(count<strlen(str));

    //wait 2000ms after each round
    busy_wait_ms (2000);
    
}


int main(void) {
    // Tell the LED pin that the PWM is in charge of its value.
    gpio_set_function(PICO_DEFAULT_LED_PIN, GPIO_FUNC_PWM);
    // Figure out which slice we just connected to the LED pin
    uint slice_num = pwm_gpio_to_slice_num(PICO_DEFAULT_LED_PIN);

    // Mask our slice's IRQ output into the PWM block's single interrupt line
    pwm_clear_irq(slice_num);
    pwm_set_irq_enabled(slice_num, true);

    // Register the interrupt handler: here it's function on_pwm_wrap() defined above
    irq_set_exclusive_handler(PWM_IRQ_WRAP, on_pwm_wrap);
    irq_set_enabled(PWM_IRQ_WRAP, true);

    // Get some sensible defaults for the slice configuration. By default, the
    // counter is allowed to wrap over its maximum range (0 to 2**16-1)
    pwm_config config = pwm_get_default_config();
    // Set divider, reduces counter clock to sysclock/this value
    pwm_config_set_clkdiv(&config, 4.f);
    // Load the configuration into our PWM slice, and set it running.
    pwm_init(slice_num, &config, true);

    // This empty loop allows the PWM interrupt handler to effectively take over program control.
    // tight_loop_contents() is an empty no-op function that's a placeholder.
    while (true)
        tight_loop_contents();
}
