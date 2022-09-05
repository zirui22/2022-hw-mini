# Download Pico SDK

Download the Pico SDK like:

```sh
cd

git clone --depth 1 https://github.com/raspberrypi/pico-sdk.git
```

For convenience, set environment variable PICO_SDK_PATH so you don't have to type it each time you configure CMake.

## macOS

edit ~/.zprofile adding:

```sh
export PICO_SDK_PATH=$HOME/pico-sdk
```

## Linux / Windows Subsystem for Linux

edit ~/.bashrc adding:

```sh
export PICO_SDK_PATH=$HOME/pico-sdk
```
