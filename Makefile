# make
# make tests
# make clean
DEBUG ?= false

AR = ar
CC = gcc
CFLAGS = -Werror
OBJS = array.o numsys.o string.o utils.o
TESTS = array.exe

ifneq (${DEBUG}, false)
CFLAGS += -fsanitize=address,undefined -g -O0
else
CFLAGS += -O3
endif

LIB = clib

SRCDIR = src
INCDIR = include
OBJDIR = obj
LIBDIR = lib
TESTSDIR = tests
DIRS = ${OBJDIR} ${LIBDIR}

build: ${DIRS} ${LIBDIR}/lib${LIB}.a

${DIRS}:
	mkdir $@

${OBJDIR}/%.o: ${SRCDIR}/%.c ${INCDIR}/${LIB}/%.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}

${LIBDIR}/lib${LIB}.a: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	${AR} rcs $@ $^

${TESTSDIR}: build ${patsubst %.exe, ${TESTSDIR}/%.exe, ${TESTS}}
	${patsubst %.exe, ./${TESTSDIR}/%.exe, ${TESTS}}

${TESTSDIR}/%.exe: ${TESTSDIR}/%.c
	${CC} -o $@ $^ -I${INCDIR} -L${LIBDIR} -l${LIB} ${CFLAGS}

clean:
	rm ${OBJDIR}/*.o
	rm ${LIBDIR}/*.a
	rm */*.exe
