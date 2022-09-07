add_executable(adc_console adc_console.c)
target_link_libraries(adc_console pico_stdlib hardware_adc)

if(TARGET tinyusb_device)
  # enable USB output, disable UART output
  pico_enable_stdio_usb(adc_console 1)
  pico_enable_stdio_uart(adc_console 0)
elseif(PICO_ON_DEVICE)
  message(STATUS "adc_console build without USB terminal output")
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(adc_console)
