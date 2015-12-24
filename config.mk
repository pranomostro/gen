#configure your build of gen

PREFIX=/usr/local

CC=gcc

CFLAGS=-Wall -Wextra -pedantic -O2
LDFLAGS=-s -lm

TARGET=gen
OBJS=gen.o
