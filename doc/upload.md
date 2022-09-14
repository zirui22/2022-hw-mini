## Pico Drag-n-Drop

A convenient way to upload .uf2 compiled binaries to the Pico is the Drag-n-drop mode.
This requires a micro-USB cable that connects to your laptop.
**You need to obtain a micro-USB cable as that's what the Pico has.**
Check which type of USB port your laptop has.
Almost all laptops have a USB-C or USB-A port.
Some USB cables don't have the data pins connected, though this is uncommon nowadays.
Suitable USB cables can be obtained from Microcenter or online.

Connect the micro-USB to the Pico.
Just before and as you plug the other end of the cable into your laptop, hold down the "BOOTSEL" button on the Pico.
The Pico will appear almost instantly (while holding down BOOTSEL) as an external flash drive in the file browser of your laptop.
You can then release BOOTSEL button.

![bootsel switch](./bootsel.png)

Once the file is copied, the **Pico automatically reboots and runs the program**.

### Windows

Windows File Explorer will show the Pico under "This PC" "RPI-RP2".
If you don't see it, check in Device Manager: "Disk drives", "RPI RP2 USB Device".

[WSL can use](https://docs.microsoft.com/en-us/windows/wsl/filesystems)
the native Windows filesystem and vice versa.
From Windows Command Prompt, see the WSL filesystem by:

```pwsh
explorer \\wsl$
```

### macOS

The Pico will appear on the Desktop as RPI-RP2 with a grey box icon.

### Linux

On Linux, the Pico will typically in the distro file explorer as "RPI_RP2", whether using a full Raspberry Pi or Linux laptop.
The exact device path varies between Linux distros if looking to use Terminal, use `lsblk` to find the mount point.
