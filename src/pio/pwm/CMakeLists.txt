add_executable(pio_pwm)

pico_generate_pio_header(pio_pwm ${CMAKE_CURRENT_LIST_DIR}/pwm.pio)

target_sources(pio_pwm PRIVATE pwm.c)

target_link_libraries(pio_pwm PRIVATE pico_stdlib hardware_pio)
pico_add_extra_outputs(pio_pwm)

if(TARGET tinyusb_device)
  # enable USB output, disable UART output
  pico_enable_stdio_usb(pio_pwm 1)
  pico_enable_stdio_uart(pio_pwm 0)
elseif(PICO_ON_DEVICE)
  message(STATUS "pio_pwm build without USB terminal output")
endif()
