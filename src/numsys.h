#ifndef CLIB_NUMSYS_H
#define CLIB_NUMSYS_H

#include <inttypes.h>

char numsys_dtoc(int64_t digit);
int64_t numsys_ctod(char digit);
char * numsys_ntos(int64_t num, uint8_t base);
int64_t numsys_ston(char * str, uint8_t base);

#include "numsys.c" 

#endif