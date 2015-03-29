#Makefile for the gen program.

CC = gcc
CFLAGS = -Wall -W -Wextra -O3 -fexpensive-optimizations -funroll-loops -fno-builtin -s -std=c99
LIBS = -lm

all : gen
gen : gen.c
	$(CC) $(CFLAGS) gen.c $(LIBS) -o gen

