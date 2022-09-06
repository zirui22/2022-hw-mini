if(NOT TARGET tinyusb_device AND PICO_ON_DEVICE)
  message(WARNING "onboard_temperature will not be able to print to USB debug console due to missing TinyUSB in SDK")
endif()

add_executable(onboard_temperature onboard_temperature.c)

target_link_libraries(onboard_temperature pico_stdlib hardware_adc)

# enable USB output, disable UART output
pico_enable_stdio_usb(onboard_temperature 1)
pico_enable_stdio_uart(onboard_temperature 0)

# create map/bin/hex file etc.
pico_add_extra_outputs(onboard_temperature)
