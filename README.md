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
