stm32flash
==========

Fork of https://code.google.com/p/stm32flash/stm32flash - http://stm32flash.googlecode.com/

```
Usage: stm32flash [-bvngfhc] [-[rw] filename] [-RB [-]DTR|RTS] /dev/ttyS0
	-b rate		Baud rate (default 115200)
	-r filename	Read flash to file
	-w filename	Write flash to file
	-u		Disable the flash write-protection
	-e n		Only erase n pages before writing the flash
	-v		Verify writes
	-n count	Retry failed writes up to count times (default 10)
	-g address	Start execution at specified address (0 = flash start)
	-s start_page	Flash at specified page (0 = flash start)
	-f		Force binary parser
	-h		Show this help
	-l              Show a list of available IO pins
	-c		Resume the connection (don't send initial INIT)
			*Baud rate must be kept the same as the first init*
			This is useful if the reset fails
	-R signal	Reset device after upload using IO.
			NONE can be given if one does not wish to reset at all
			List availble IO with -l
	-B signal	Use signal to select boot mode using IO.
			Logic low is applied for system boot (upload) and logic high
			for normal boot
			List availble IO with -l

Examples:
	Get device information:
		stm32flash /dev/ttyS0

	Write with verify and then start execution:
		stm32flash -w filename -v -g 0x0 /dev/ttyS0

	Read flash to file:
		stm32flash -r filename /dev/ttyS0

	Start execution:
		stm32flash -g 0x0 /dev/ttyS0

	Use IO for boot selector, write flash and then reset
	Using 1MBAUD (suitable for 24 MHz devices) on first USB serial
		stm32flash -w filename /dev/ttyUSB0 -B cs.dtr -R cs.rts
```


Installation
-----------

```
git clone https://github.com/devilholk/stm32flash
cd stm32flash
make
sudo make install
```
