# Simple example for ESP32-S3-Zero

This is a simple blink example with code complition working for neovim with LSP.

neovim clangd lsp configuration:

```
  cmd = {
    "/home/yura/.espressif/tools/esp-clang/esp-18.1.2_20240912/esp-clang/bin/clangd",
    "--background-index",
    "--query-driver=**",
    "--log=verbose",
    "--offset-encoding=utf-16",
  },
```

It requires espressif version of clangd.

Generate compile_commands.json:
```
pio run -t compiledb
```

## Debugging

ESP32-S3 has a built-in usb jtag interface. No additional hardware setup is required apart from USB connection.

Install openocd for ESP32: https://aur.archlinux.org/packages/openocd-esp32-bin
```
yay openocd-esp32-bin
```

Install udev rules:
```
sudo cp /usr/share/openocd/contrib/60-openocd.rules /etc/udev/rules.d/
sudo udevadm control --reload
sudo udevadm trigger
```

Start openocd:
```
openocd -f board/esp32s3-builtin.cfg
```

It will start gdb server: `Info : starting gdb server for esp32s3.cpu0 on 3333`

Start ESP32S3 gdb from the project root directory where gdbinit is located:
```
xtensa-esp32s3-elf-gdb -x gdbinit .pio/build/esp32-s3-zero/firmware.elf
```

It should connect to the openocd gdb server and be ready to use.
The TUI mode can be enabled with `--tui` argument or Ctr+X+A.

nvim-gdb plugin also works with PR: https://github.com/sakhnik/nvim-gdb/pull/209

