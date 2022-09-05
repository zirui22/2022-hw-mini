# 2022 Hardware Miniproject

This project assumes you have installed
[CMake, Git, and C/C++ cross-compiler](./doc/compiler.md) and
[download the Pico SDK](./doc/pico-sdk.md).

Configure the CMake project once, unless changing an option or doing a major change to code:

```sh
cmake -B build
```

Then we can pick a particular code "target" to build like:

```sh
cmake --build build -t blink
```

This creates a "build/blink/blink.uf2" file.
The .uf2 file is the binary image we need to copy to the Pico board for a particular program.

## Pico Drag-n-Drop

A convenient way to upload .uf2 compiled binaries to the Pico is the Drag-n-drop mode.
This requires a micro-USB cable that connects to your laptop.
**You need to obtain a micro-USB cable as that's what the Pico has.**
Check which type of USB port your laptop has.
Almost all laptops have a USB-C or USB-A port.
Some USB cables don't have the data pins connected, though this is uncommon nowadays.
Suitable USB cables can be obtained from Microcenter or online.

Connect the microUSB to the Pico.
Just before and as you plug the other end of the cable into your laptop, hold down the "BOOTSEL" button on the Pico.
The Pico will appear as an external flash drive in the file browser of your laptop.

![bootsel switch](./doc/bootsel.png)

Once the file is copied, unplug and replug in the Pico (without holding BOOTSEL) to run the program.

## MicroPython

The Pico is also capable of
[running MicroPython scripts](https://projects.raspberrypi.org/en/projects/getting-started-with-the-pico/3).
MicroPython uses a subset of the Python language with additional modules specific to the microcontroller.
