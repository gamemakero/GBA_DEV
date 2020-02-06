###EXAMPLE OF GBA MAKEFILE
### Must compile in arm thumb format
### -fno-strict-aliasing helps since raw memory usage and pointers
### usage is very common while programming for GBA

PATH := $(DEVKITARM)/bin:$(PATH) 		#compiler
#PATH := $(DEVKITPRO)/tools/bin:$(PATH) 	#GBA FIX

PROJ 	:= testBotones
TARGET 	:= $(PROJ)
OBJS	:= botones.o keys.o


PREFIX := arm-none-eabi-

CC		:= $(PREFIX)gcc
LD 		:= $(PREFIX)gcc
OBJCOPY	:= $(PREFIX)objcopy

ARCH    := -mthumb-interwork -mthumb
CFLAGS	:= $(ARCH) -fno-strict-aliasing -O2
LFLAGS	:= $(ARCH) -specs=gba.specs
ELFLAGS	:= -v -O binary

.PHONY: build clean

####build proccess
build: $(TARGET).gba
#Step 3, strip debug info and fix header
$(TARGET).gba: $(TARGET).elf
	$(OBJCOPY) $(ELFLAGS) $< $@
	-@gbafix $@
#Step 2, link
$(TARGET).elf: $(OBJS)
	$(LD) $^ $(LFLAGS) -o $@
#STEP 1, compile
$(OBJS): %.o : %.c
	$(CC) -c $< $(CFLAGS) -o $@
clean:
	rm *.o
	rm *.elf
	rm *.gba
