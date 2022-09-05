# Cross-compiler install

Microcontrollers generally use a different CPU architecture than your laptop.
While it's possible to use a full Raspberry Pi to program the Pico, here we assume you'll use a laptop.
It's straightforward to install the 32-bit ARM C/C++ cross-compiler on popular operating systems.

Please follow the section relevant to your laptop operating system.

## macOS

Homebrew is popular and generally useful on macOS to get a wide variety of development and creative software packages.
Obtain Homebrew as per https://brew.sh.

Install Git, CMake build system, and ARM cross-compiler by:

```sh
brew install cmake git
brew tap ArmMbed/homebrew-formulae
brew install arm-none-eabi-gcc
```

The "brew tap" installs from "https://github.com/ARMmbed/homebrew-formulae".
If your Mac has an Apple Silicon CPU, you may need to [enable Rosetta](https://support.apple.com/en-us/HT211861).
Rosetta enables most x86 apps on Apple Silicon at nearly full performance.

## Linux

Both WSL Ubuntu and ordinary native Linux distros install Git, CMake, the cross-compiler, and libraries the same way:

```sh
sudo apt update
sudo apt install git make cmake g++ gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
```

## Windows

The Visual Studio cross-compiler setup is described in Section 9.2 of the
[Pico install guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
We choose to use Windows Subsystem for Linux (WSL) instead, which is useful for many projects.
Sometimes WSL is the only feasible way to work with non-Windows projects on Windows.
https://docs.microsoft.com/en-us/windows/wsl/install describes the brief WSL install process.
We suggest Ubuntu Linux distribution on WSL.
The cross-compiler install on WSL Ubuntu is just like plain Linux in the section above.

To make switching between Windows and WSL easier, we generally use
[Windows Terminal](https://docs.microsoft.com/en-us/windows/terminal/install).
