cmake_minimum_required(VERSION 3.13)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

set(PICO_SDK_FETCH_FROM_GIT true)
set(PICO_PLATFORM "rp2040")

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(cmake/pico_sdk_import.cmake)

project(pico_examples C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- auto-ignore build directory
if(NOT EXISTS ${PROJECT_BINARY_DIR}/.gitignore)
  file(WRITE ${PROJECT_BINARY_DIR}/.gitignore "*")
endif()

# Initialize the SDK
pico_sdk_init()

# we put each example in a subdirectory for clarity
add_subdirectory(blink)
