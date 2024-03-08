CC = gcc
DBG = gdb
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = mtrx.o
INCS = array.o utils.o

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

TARGET = ${SRCDIR}/main.c

${BINDIR}/app.exe: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} ${TARGET} ${BINDIR}
	${CC} -o $@ $< ${patsubst %.o, ${INCDIR}/%.o, ${INCS}} ${TARGET} ${CFLAGS}

run: ${BINDIR}/app.exe
	./${BINDIR}/app.exe

${DBG}: ${BINDIR}/app.exe
	gdb ${BINDIR}/app.exe

${OBJDIR}:
	mkdir ${OBJDIR}
${BINDIR}:
	mkdir ${BINDIR}

${OBJDIR}/mtrx.o: ${SRCDIR}/mtrx.c ${SRCDIR}/mtrx.h ${OBJDIR}
	${CC} -o $@ -c $< ${CFLAGS}

clean:
	rm obj/*.o
	rm */*.exe