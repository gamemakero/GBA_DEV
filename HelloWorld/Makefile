###EXAMPLE OF GBA MAKEFILE
### Must compile in arm thumb format
### -fno-strict-aliasing helps since raw memory usage and pointers
### usage is very common while programming for GBA
CFLAGS= -mthumb-interwork -mthumb -fno-strict-aliasing 
LFLAGS= $(CFLAGS) -specs=gba.specs
ELFLAGS= -v -O binary
gbacc=arm-none-eabi-gcc
gba_obj_copy=arm-none-eabi-objecopy
main.gba: main.o
	$(gbacc) main.o -o main.elf $(LFLAGS)
	$(gba_obj_copy) $(ELFLAGS) main.elf main.gba
	gbafix main.gba
main.o: main.c
	$(gbacc) -c main.c $(CFLAGS)

