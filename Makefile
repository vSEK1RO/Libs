CC = gcc
CFLAGS = -Wall -Wextra -Werror -O0
OBJS = array.o numsys.o string.o utils.o

SRCDIR = src
OBJDIR = obj
TESTSDIR = tests

build: ${OBJDIR} ${OBJS}
	
${OBJDIR}:
	mkdir ${OBJDIR}

array.o: ${SRCDIR}/array.c ${SRCDIR}/array.h
	${CC} -o ${OBJDIR}/array.o -c $< ${CFLAGS}
string.o: ${SRCDIR}/string.c ${SRCDIR}/string.h
	${CC} -o ${OBJDIR}/string.o -c $< ${CFLAGS}
numsys.o: ${SRCDIR}/numsys.c ${SRCDIR}/numsys.h
	${CC} -o ${OBJDIR}/numsys.o -c $< ${CFLAGS}
utils.o: ${SRCDIR}/utils.c ${SRCDIR}/utils.h
	${CC} -o ${OBJDIR}/utils.o -c $< ${CFLAGS}

tests: build array_test.exe

array_test.exe: 
	${CC} -o ${TESTSDIR}/array_test.o -g -c ${TESTSDIR}/array_test.c ${CFLAGS}
	${CC} -o ${TESTSDIR}/array_test.exe ${patsubst %.o, ${OBJDIR}/%.o, ${OBJS}} ${TESTSDIR}/array_test.o ${CFLAGS}
	./${TESTSDIR}/array_test.exe