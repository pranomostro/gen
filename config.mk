PREFIX=/usr/local

CC=cc

CFLAGS=-Wall -Wextra -std=c89 -pedantic -O2
LDFLAGS=-s -lm

BIN=gen
OBJ=$(BIN:=.o)
MAN=$(BIN:=.1)
CONF=config.mk
