# 2022 Hardware Miniproject

This project assumes CMake, cross-compiler and Pico SDK have already been installed.

We configure the CMake project once, unless desired to change an option or doing a major change to code:

```sh
cmake -B build
```

Then we can pick a particular code "target" to build like:

```sh
cmake --build build -t blink
```
