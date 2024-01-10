CROSS_COMPILE:=arm-none-eabi-
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)ld
OBJCOPY:=$(CROSS_COMPILE)objcopy


CFLAGS:=-mcpu=cortex-m3 -mthumb -g -ggdb -Wall -Wno-main
LDFLAGS:=-T target.ld -gc-sections -nostdlib -Map=image.map


image.bin: image.elf
	$(OBJCOPY) -O binary $^ $@

image.elf: startup.o target.ld
	$(LD) $(LDFLAGS) startup.o -o $@

startup.o: startup.c

clean:
	rm -f image.bin image.elf *.o image.map

stlinkDownload:
	STM32_Programmer_CLI.exe -c port=SWD freq=4000 -w image.bin 0x8000000 -v
	STM32_Programmer_CLI.exe -c port=SWD freq=4000 -hardRst