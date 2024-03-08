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
DIRS = ${SCRDIR} ${INCDIR} ${OBJDIR} ${LIBDIR} ${BINDIR}

build: ${DIRS} ${LIBDIR}/lib${LIB}.a

${SCRDIR}:
	mkdir ${SCRDIR}
${INCDIR}:
	mkdir ${INCDIR}
${OBJDIR}:
	mkdir ${OBJDIR}
${LIBDIR}:
	mkdir ${LIBDIR}
${BINDIR}:
	mkdir ${BINDIR}

${OBJDIR}/array.o: ${SRCDIR}/array.c ${INCDIR}/${LIB}/array.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}
${OBJDIR}/string.o: ${SRCDIR}/string.c ${INCDIR}/${LIB}/string.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}
${OBJDIR}/numsys.o: ${SRCDIR}/numsys.c ${INCDIR}/${LIB}/numsys.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}
${OBJDIR}/utils.o: ${SRCDIR}/utils.c ${INCDIR}/${LIB}/utils.h
	${CC} -o $@ -c $< -I${INCDIR} ${CFLAGS}

${LIBDIR}/lib${LIB}.a: ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	ar rcs $@ $^

${TESTSDIR}: ${patsubst %.exe, ${TESTSDIR}/%.exe, ${TESTS}}
	${patsubst %.exe, ./${TESTSDIR}/%.exe, ${TESTS}}

${TESTSDIR}/array.exe: ${TESTSDIR}/array.c
	${CC} -o $@ $^ -I${INCDIR} -L${LIBDIR} -l${LIB} ${CFLAGS}

clean:
	rm ${OBJDIR}/*.o
	rm ${LIBDIR}/*.a
	rm */*.exe