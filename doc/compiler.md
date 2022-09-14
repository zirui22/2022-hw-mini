# Cross-compiler install

Microcontrollers generally use a different CPU architecture than your laptop.
While it's possible to use a full Raspberry Pi to program the Pico, here we assume you'll use a laptop.
It's straightforward to install the 32-bit ARM C/C++ cross-compiler on popular operating systems.

Please follow the section relevant to your laptop operating system.
Note that about 2..5 gigabytes of hard drive space is required overall.

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

This install command gives Git, CMake, the cross-compiler, and libraries for:

* laptop/desktop with: WSL Ubuntu, Ubuntu/Debian-like distros
* full Raspberry Pi (e.g. Raspberry Pi 4)

```sh
sudo apt update
sudo apt install git make cmake g++ gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib
```

NOTE: if upon `cmake -B build` you get an immediate error about CMake being too old,
please install a newer CMake via [scripts/install_cmake_linux.sh](../scripts/install_cmake_linux.sh)

## Windows

The Visual Studio cross-compiler setup is described in Section 9.2 of the
[Pico install guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf).
We choose to use Windows Subsystem for Linux (WSL) instead, which is useful for many projects.
Sometimes WSL is the only feasible way to work with non-Windows projects on Windows.
[WSL install](https://docs.microsoft.com/en-us/windows/wsl/install) from Windows Commant Prompt:

```sh
wsl --install
```

This defaults to Ubuntu Linux distribution on WSL.
This process takes 10-20 minutes depending on download speed.

[WSL can use](https://docs.microsoft.com/en-us/windows/wsl/filesystems)
the native Windows filesystem and vice versa.

The cross-compiler install on WSL Ubuntu is just like plain Linux in the section above.

To make switching between Windows and WSL easier, we generally use
[Windows Terminal](https://docs.microsoft.com/en-us/windows/terminal/install).
