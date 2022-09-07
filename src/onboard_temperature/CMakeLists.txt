add_executable(onboard_temperature onboard_temperature.c)
target_link_libraries(onboard_temperature pico_stdlib hardware_adc)

if(TARGET tinyusb_device)
  # enable USB output, disable UART output
  pico_enable_stdio_usb(onboard_temperature 1)
  pico_enable_stdio_uart(onboard_temperature 0)
elseif(PICO_ON_DEVICE)
  message(STATUS "onboard_temperature build without USB terminal output")
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(onboard_temperature)
