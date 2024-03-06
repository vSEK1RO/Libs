CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0 -g
OBJS = array.o numsys.o string.o utils.o
TESTS = array.exe

SRCDIR = src
OBJDIR = obj
TESTSDIR = tests

build: ${OBJDIR} ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}}
	
${OBJDIR}:
	mkdir ${OBJDIR}

${OBJDIR}/array.o: ${SRCDIR}/array.c ${SRCDIR}/array.h
	${CC} -o $@ -c $< ${CFLAGS}
${OBJDIR}/string.o: ${SRCDIR}/string.c ${SRCDIR}/string.h
	${CC} -o $@ -c $< ${CFLAGS}
${OBJDIR}/numsys.o: ${SRCDIR}/numsys.c ${SRCDIR}/numsys.h
	${CC} -o $@ -c $< ${CFLAGS}
${OBJDIR}/utils.o: ${SRCDIR}/utils.c ${SRCDIR}/utils.h
	${CC} -o $@ -c $< ${CFLAGS}

${TESTSDIR}: build ${patsubst %.exe, ${TESTSDIR}/%.exe, ${TESTS}}
	./${TESTSDIR}/*.exe

${TESTSDIR}/array.exe: ${TESTSDIR}/array.c
	${CC} -o $@ ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} $< ${CFLAGS}

clean:
	rm */*.o
	rm */*.exe