### Change -I -L -l vars for your dependencies locations
DEPSDIR = C:/_SE/libs
DEPS = clib PDCurses
-I = ${patsubst %, -I${DEPSDIR}/%/include, ${DEPS}}
-L = ${patsubst %, -L${DEPSDIR}/%/lib, ${DEPS}}
-l = -lclib -lpdcurses
### Read upper

CC = gcc
DBG = gdb
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = matrix.o

SRCDIR = src
OBJDIR = obj
BINDIR = bin
DIRS = ${SCRDIR} ${OBJDIR} ${BINDIR}

TARGET = ${SRCDIR}/main.c

build: ${DIRS} ${BINDIR}/app.exe

${DIRS}:
	mkdir $@

${BINDIR}/app.exe: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} ${TARGET}
	${CC} -o $@ $^ ${-I} ${-L} ${-l} ${CFLAGS}

run: ${BINDIR}/app.exe
	./$^

${DBG}: ${BINDIR}/app.exe
	gdb $^

${OBJDIR}/%.o: ${SRCDIR}/%.c ${SRCDIR}/%.h
	${CC} -o $@ -c $< ${-I} ${CFLAGS}

clean:
	rm obj/*.o
	rm */*.exe