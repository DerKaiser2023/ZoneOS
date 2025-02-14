CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
CFLAGS = -mcpu=arm920t -marm -nostdlib -ffreestanding -Wall
LDFLAGS = -T ../boot/linker.ld

OBJS = ../kernel/kernel.o ../drivers/display.o ../drivers/input.o

all: kernel.img

kernel.img: $(OBJS)
    $(LD) $(LDFLAGS) -o kernel.elf $(OBJS)
    arm-none-eabi-objcopy -O binary kernel.elf kernel.img

clean:
    rm -f *.o kernel.elf kernel.img
