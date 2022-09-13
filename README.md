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

[Troubleshooting](./doc/trouble.md)
