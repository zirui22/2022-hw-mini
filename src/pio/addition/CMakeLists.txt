add_executable(pio_addition addition.c)
target_link_libraries(pio_addition PRIVATE pico_stdlib hardware_pio)

pico_generate_pio_header(pio_addition ${CMAKE_CURRENT_LIST_DIR}/addition.pio)

if(TARGET tinyusb_device)
  # enable USB output, disable UART output
  pico_enable_stdio_usb(pio_addition 1)
  pico_enable_stdio_uart(pio_addition 0)
elseif(PICO_ON_DEVICE)
  message(STATUS "pio_addition build without USB terminal output")
endif()

pico_add_extra_outputs(pio_addition)
