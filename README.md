# ATMega328USBasp_example
Example PlatformIO project for bare ATMega328P programmed with USBasp

## Some notes

PlatformIO had a problem with reliable uploading the firmware over USBasp. However this command in terminal worked always worked: `avrdude -c usbasp -p m328p -U flash:w:.pio/build/ATmega328P/firmware.hex`.<br>
Because of this, platformio.ini file contains:

```
upload_protocol = custom
upload_command = avrdude -c usbasp -p m328p -U flash:w:$SOURCE:i
```

### Warning to ignore

If you would have `avrdude error: cannot set sck period; please check for usbasp firmware update` warning, ignore it. After updating the firmware on the USBasp, I was not able to achieve full upload speed in any way (however the warning dissappeared).

## Crystal oscilator

I have used 11.0592 MHz external.

## Fuse bits

I have used the following:

- lfuse	0xF7	Full Swing Crystal Oscillator, 16K + 64ms startup (slow startup)<br>
  my project had to be very stable so I set slow startup
- hfuse	0xD9	SPIEN on, BOOTRST off, BOD off
- efuse	0xFF	Brown-Out Detection off (change to 0xFD if you want BOD 2.7 V)

I set fuse bits with this command:
```
avrdude -c usbasp -p m328p -U lfuse:w:0xF7:m -U hfuse:w:0xD9:m -U efuse:w:0xFF:m
```

You can read existing fuse with this command:
```
avrdude -c usbasp -p m328p -U lfuse:r:-:h -U hfuse:r:-:h -U efuse:r:-:h
```
