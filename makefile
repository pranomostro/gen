#Makefile for the gen program.

DESTDIR = /usr
TARGET = gen
SRC = gen.c

CC = gcc
CFLAGS = -Wall -W -Wextra -O3 -fexpensive-optimizations -funroll-loops -fno-builtin -s -std=c99
LIBS = -lm

all : ${TARGET}

${TARGET} : ${SRC}
	${CC} ${CFLAGS} ${SRC} ${LIBS} -o ${TARGET}

clean :
	rm -f ${TARGET}

install : all
	cp ${TARGET} ${DESTDIR}/bin
	cp ${TARGET}.1 ${DESTDIR}/share/man/man1

uninstall :
	rm -f ${DESTDIR}/bin/${TARGET}
	rm -f ${DESTDIR}/share/man/man1/${TARGET}.1
