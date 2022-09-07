add_executable(hello_adc hello_adc.c)
target_link_libraries(hello_adc pico_stdlib hardware_adc)

if(TARGET tinyusb_device)
  # enable USB output, disable UART output
  pico_enable_stdio_usb(hello_adc 1)
  pico_enable_stdio_uart(hello_adc 0)
elseif(PICO_ON_DEVICE)
  message(STATUS "hello_adc build without USB terminal output")
endif()

# create map/bin/hex file etc.
pico_add_extra_outputs(hello_adc)
