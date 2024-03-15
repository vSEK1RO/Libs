### Change -I -L -l vars for your dependencies locations
DEPSDIR = C:/_SE/libs
DEPS = clib
-I = ${patsubst %, -I${DEPSDIR}/%/include, ${DEPS}}
-L = ${patsubst %, -L${DEPSDIR}/%/lib, ${DEPS}}
-l = -lclib
### Read upper

CC = gcc
DBG = gdb
CFLAGS = -Wall -Wextra -Werror -O0 -g

SRCDIR = src
BINDIR = bin
DIRS = ${BINDIR}

TARGET = ${SRCDIR}/main.c

build: ${DIRS} ${BINDIR}/app.exe

${DIRS}:
	mkdir $@

${BINDIR}/app.exe: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} ${TARGET}
	${CC} -o $@ $^ ${-I} ${-L} ${-l} ${CFLAGS}

run: ${DIRS} ${BINDIR}/app.exe
	./${BINDIR}/app.exe

${DBG}: ${BINDIR}/app.exe
	gdb $^

${OBJDIR}/%.o: ${SRCDIR}/%.c ${SRCDIR}/%.h ${DIRS}
	${CC} -o $@ -c $< ${-I} ${CFLAGS}

clean:
	rm obj/*.o
	rm */*.exe