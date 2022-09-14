# 2022 Hardware Miniproject

[![ci](https://github.com/BostonUniversitySeniorDesign/2022-hw-mini/actions/workflows/ci.yml/badge.svg)](https://github.com/BostonUniversitySeniorDesign/2022-hw-mini/actions/workflows/ci.yml)

---

[Miniproject assignment](./assignment.md)

---

It's necessary to install
[CMake, Git, and the 32-bit ARM compiler](./doc/compiler.md).
This example project downloads the Pico SDK automatically.

Configure the CMake project once, unless changing an option or doing a major change to code:

```sh
cmake -B build
```

To save build time, pick a particular target to build like:

```sh
cmake --build build -t pwm_led_fade
```

or if you wish, build all target:

```sh
cmake --build build
```

This creates a "build/src/pwm/led_fade/pwm_led_fade.uf2" file.
The .uf2 file is the binary image we need to
[upload to the Pico board](./doc/upload.md)
for a particular program.

---

[Troubleshooting](./doc/trouble.md)
