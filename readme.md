currantOS

# How to build

```
cd proj_root/build
sh gen_make.sh
make
```

# How to connect via serial

1. Connect to raspberry-pi via AE-UM232R.
2. Type below command on Terminal.
```
screen /dev/tty.usbserial-AH01JAUX 115200
```
3. Power on raspberry-pi.

# Check assembler code

```
arm-none-eabi-objdump -S currantOS > currantOS.disasm
```



