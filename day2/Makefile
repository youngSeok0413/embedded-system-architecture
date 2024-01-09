#stm32f103r8tx - stm32f103x - medium density
CROSS_COMPILE:=arm-none-eabi-
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)gcc

BUILD_DIR=./build
PRJ_DIR=./

OBJS:=main.o interrupt.o
OBJECTS:=$(patsubst %.o,$(BUILD_DIR)/%.o,$(OBJS))
DEPS:=$(OBJECTS:.o=.d)

LSCRIPT:=target.ld

OBJCOPY:=$(CROSS_COMPILE)objcopy

CFLAGS:=-mcpu=cortex-m3 -mthumb -g -ggdb -Wall -Wno-main -Wstack-usage=200 -ffreestanding -Wno-unused -nostdlib
LDFLAGS:=-T $(LSCRIPT) -Wl,-gc-sections -Wl,-Map=$(BUILD_DIR)/image.map -nostdlib

.PHONY: all
all: $(BUILD_DIR)/image.bin 

$(BUILD_DIR)/image.bin: $(BUILD_DIR)/image.elf
	$(OBJCOPY) -O binary $^ $@

$(BUILD_DIR)/image.elf: $(OBJECTS) $(LSCRIPT)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@

$(BUILD_DIR)/%.o: $(PRJ_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MD $(LDFLAGS)

$(BUILD_DIR):
	mkdir $@

.PHONY: clean
clean:
	rm -f $(BUILD_DIR)/image.bin $(BUILD_DIR)/image.elf $(BUILD_DIR)/image.map $(DEPS) $(OBJECTS)

.PHONY: stlinkDownload
stlinkDownload:
#	sudo ntpdate -s time.bora.net			//only if you got time skew warning
#	sudo apt-get -y install ntpdate
#	sudo apt-get update
#	sudo hwclock --systohc
	STM32_Programmer_CLI.exe -c port=SWD freq=4000 -w $(BUILD_DIR)/image.bin 0x8000000 -v
	STM32_Programmer_CLI.exe -c port=SWD freq=4000 -hardRst

-include $(DEPS)
