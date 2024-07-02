# make
# make tests
# make clean

CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = array.o numsys.o string.o utils.o
TESTS = arr_unit.exe arr_spd.exe

LIB = clib

SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin
LIBDIR = lib
TESTDIR = test
DIRS = ${OBJDIR} ${LIBDIR} ${BINDIR}

build: ${DIRS} ${LIBDIR}/lib${LIB}.a ${BINDIR}/lib${LIB}.so

${DIRS}:
	mkdir $@

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INCDIR}/${LIB}/%.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}

${BINDIR}/lib${LIB}.so: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	${CC} -shared -o $@ $^ 

${LIBDIR}/lib${LIB}.a: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	ar rcs $@ $^

${TESTDIR}: build ${patsubst %.exe, ${TESTDIR}/%.exe, ${TESTS}}
	${patsubst %.exe, ./${TESTDIR}/%.exe;, ${TESTS}}

${TESTDIR}/%.exe: ${TESTDIR}/%.c
	${CC} -o $@ $^ -I${INCDIR} -L${LIBDIR} -l${LIB} ${CFLAGS}

clean:
	rm ${OBJDIR}/*.o
	rm ${LIBDIR}/*.a
	rm ${BINDIR}/*.so
	rm */*.exe
