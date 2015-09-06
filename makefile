PREFIX = /usr/local
TARGET = gen
SRC = ${TARGET}.c

CC = gcc
CFLAGS = -Wall -Wextra -O3 -fexpensive-optimizations\
-funroll-loops -fno-builtin -s -std=c89 -static
LIBS = -lm

all: ${TARGET}

${TARGET}: ${SRC}
	${CC} ${CFLAGS} ${SRC} ${LIBS} -o ${TARGET}

clean:
	rm -f ${TARGET}

install: all
	cp ${TARGET} ${PREFIX}/bin
	cp ${TARGET}.1 ${PREFIX}/share/man/man1

uninstall:
	rm -f ${PREFIX}/bin/${TARGET}
	rm -f ${PREFIX}/share/man/man1/${TARGET}.1
