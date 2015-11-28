#configure your build of gen

PREFIX=/usr/local

CC=gcc

CFLAGS=-Wall -Wextra -std=c89 -pedantic -O2
LDFLAGS=-s -lm

TARGET=gen
OBJS=gen.o
