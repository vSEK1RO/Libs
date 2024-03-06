CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = mtrx.o
INCS = array.o utils.o

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCDIR = include

TARGET = ${SRCDIR}/main.c

build: ${BINDIR} ${OBJDIR} ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	${CC} -o ${BINDIR}/app.exe \
	${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} \
	${patsubst %.o, ${INCDIR}/%.o, ${INCS}} \
	${TARGET} ${CFLAGS}
	./${BINDIR}/app.exe

${OBJDIR}:
	mkdir ${OBJDIR}
${BINDIR}:
	mkdir ${BINDIR}

${OBJDIR}/mtrx.o: ${SRCDIR}/mtrx.c ${SRCDIR}/mtrx.h
	${CC} -o $@ -c $< ${CFLAGS}

clean:
	rm */*.o
	rm */*.exe