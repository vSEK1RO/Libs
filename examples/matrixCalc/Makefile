### Change -I -L -l vars for your dependencies locations
DEPSDIR = /home/sek1ro/Desktop/se/libs
DEPS = clib
-I = ${patsubst %, -I${DEPSDIR}/%/include, ${DEPS}}
-L = ${patsubst %, -L${DEPSDIR}/%/lib, ${DEPS}}
-l = -lclib -lncurses
### Read upper

CC = gcc
DBG = gdb
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = matrix.o

SRCDIR = src
OBJDIR = obj
BINDIR = bin
DIRS = ${OBJDIR} ${BINDIR}

TARGET = ${SRCDIR}/main.c

build: ${DIRS} ${BINDIR}/app.exe

${DIRS}:
	mkdir $@

${BINDIR}/app.exe: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} ${TARGET}
	${CC} -o $@ $^ ${-I} ${-L} ${-l} ${CFLAGS}

run: build
	./${BINDIR}/app.exe

${DBG}: ${BINDIR}/app.exe
	gdb $^

${OBJDIR}/%.o: ${SRCDIR}/%.c ${SRCDIR}/%.h
	${CC} -o $@ -c $< ${-I} ${CFLAGS}

clean:
	rm obj/*.o
	rm */*.exe