add_subdirectory(hello_usb)

add_subdirectory(adc/adc_console)
add_subdirectory(adc/hello_adc)
add_subdirectory(adc/onboard_temperature)

add_subdirectory(pio/addition)
add_subdirectory(pio/pio_blink)

if(PICO_BOARD STREQUAL "pico_w")
  # Pico W wireless model accesses the LED distinctly from the non-W model
  add_subdirectory(pico_w/blink)
else()
  # non-wireless Pico
  add_subdirectory(blink)
  add_subdirectory(pio/pwm)
  add_subdirectory(pwm/led_fade)
endif()
