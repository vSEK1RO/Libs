# make
# make tests
# make clean

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = array.o numsys.o string.o utils.o
TESTS = array.exe

LIB = clib

SRCDIR = src
INCDIR = include
OBJDIR = obj
LIBDIR = lib
TESTSDIR = tests
DIRS = ${SCRDIR} ${INCDIR}

build: ${DIRS} ${LIBDIR}/lib${LIB}.a

${DIRS}:
	mkdir ${DIRS}

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INCDIR}/${LIB}/%.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}

${LIBDIR}/lib${LIB}.a: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	ar rcs $@ $^

${TESTSDIR}: build ${patsubst %.exe, ${TESTSDIR}/%.exe, ${TESTS}}
	${patsubst %.exe, ./${TESTSDIR}/%.exe, ${TESTS}}

${TESTSDIR}/%.exe: ${TESTSDIR}/%.c
	${CC} -o $@ $^ -I${INCDIR} -L${LIBDIR} -l${LIB} ${CFLAGS}

clean:
	rm ${OBJDIR}/*.o
	rm ${LIBDIR}/*.a
	rm */*.exe