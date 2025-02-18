CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CFLAGS = -mcpu=arm920t -marm -nostdlib -ffreestanding -Wall
LDFLAGS = -T ../boot/linker.ld

# List of source files
SRC = ../kernel/kernel.c \
      ../drivers/display.c \
      ../drivers/input.c \
      ../gps/gps.c \
      ../ui/map.c

# Object files
OBJS = $(SRC:.c=.o)

all: kernel.img

kernel.img: $(OBJS)
	$(LD) $(LDFLAGS) -o kernel.elf $(OBJS)
	arm-none-eabi-objcopy -O binary kernel.elf kernel.img

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) kernel.elf kernel.img