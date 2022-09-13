# 2022 Hardware Miniproject

[![ci](https://github.com/BostonUniversitySeniorDesign/2022-hw-mini/actions/workflows/ci.yml/badge.svg)](https://github.com/BostonUniversitySeniorDesign/2022-hw-mini/actions/workflows/ci.yml)

---

[Miniproject assignment](./assignment.md)

---

This project assumes you have installed
[CMake, Git, and C/C++ cross-compiler](./doc/compiler.md).
This example project downloads the Pico SDK automatically.
Optionally, you can download [Pico SDK manually](./doc/pico-sdk.md).
The code examples here generally come from https://github.com/raspberrypi/pico-examples.

Configure the CMake project once, unless changing an option or doing a major change to code:

```sh
cmake -B build
```

If you have a Pico W wireless board (has a 1 cm gray metal square opposite micro USB jack) use command:

```sh
cmake -B build -DPICO_BOARD=pico_w
```

This command builds all targets:

```sh
cmake --build build
```

Or, one can pick a particular code "target" to build like:

```sh
cmake --build build -t blink
```

This creates a "build/blink/blink.uf2" file.
The .uf2 file is the binary image we need to copy to the Pico board for a particular program.

[Upload executable to Pico](./doc/upload.md)

## MicroPython

The Pico is also capable of
[running MicroPython scripts](https://projects.raspberrypi.org/en/projects/getting-started-with-the-pico/3).
MicroPython uses a subset of the Python language with additional modules specific to the microcontroller.

## USB console

The USB console (if used by your program) uses the TinyUSB library.
CMake must be configured as in the
[hello_usb](./src/hello_usb/CMakeLists.txt)
to enable USB and disable UART for the particular target.
Each operating system has a distinct way of accessing USB-serial gateways:

* Windows: look in Device Manager under Ports-there should be COM* device. Use [PuTTY](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html) to connect at 115200 baud serial
* Linux: look under /dev/ttyACM* and connect with PuTTY or `screen /dev/ttyACM0 115200`
* macOS: look under "/dev/cu.usbserial" and connect with PuTTY `brew install putty` or `screen /dev/cu.usbserial 115200`

## Troubleshooting

As with any build system, CMake looks to environment variable to populate options including compile and link flags.
The configure step prints a few key variables.
If build errors occur, compare the messages with the printed flags to see if you have environment variables setting incompatible options for the cross compiler.

Example: on macOS, some may set `LDFLAGS=-Wl,-no-compact-unwind` but this is not acceptable to the cross compiler, resulting in link error:

```
Error: unable to disambiguate: -no_compact_unwind (did you mean --no_compact_unwind ?)
```

In this case, we set LDFLAGS to empty, reconfigure and build like:

```sh
LDFLAGS='' cmake -Bbuild --fresh
cmake --build build
```
