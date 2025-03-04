# File:   Makefile
# Author: A. Hingston, R. Beck
# Date:   19 Oct 2021
# Descr:  Makefile for game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I. -I../../utils -I../../fonts -I../../drivers -I../../drivers/avr
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: main.out


# Compile: create object files from C source files.
main.o: main.c ../../drivers/avr/system.h ledHeader.h world.h movement.h ../../utils/pacer.h numbers.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

ledHeader.o: ledHeader.c ledHeader.h
	$(CC) -c $(CFLAGS) $< -o $@
	
timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@
	
pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@
	
ledmat.o: ../../drivers/ledmat.c ../../drivers/ledmat.h  ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@
	
world.o: world.c world.h
	$(CC) -c $(CFLAGS) $< -o $@
	
movement.o: movement.c ../../drivers/avr/system.h ../../drivers/avr/pio.h movement.h ../../drivers/navswitch.h ../../drivers/ledmat.h world.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/navswitch.h  ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/delay.h
	$(CC) -c $(CFLAGS) $< -o $@

numbers.o: numbers.c numbers.h ../../drivers/ledmat.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@





# Link: create ELF output file from object files.
main.out: main.o system.o ledHeader.o pacer.o timer.o ledmat.o world.o movement.o navswitch.o numbers.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Target: clean project.
.PHONY: clean
clean: 
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: main.out
	$(OBJCOPY) -O ihex main.out main.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash main.hex; dfu-programmer atmega32u2 start
