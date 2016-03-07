#configure your build of gen

PREFIX=/usr/local

CC=cc

CFLAGS=-Wall -Wextra -pedantic -O2
LDFLAGS=-s -lm

TARGET=gen
OBJS=gen.o
