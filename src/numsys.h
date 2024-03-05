#ifndef NUMSYS_H
#define NUMSYS_H

#include <math.h>
#include <inttypes.h>

#include "string.h"

char numsys_dtoc(int64_t digit);
int64_t numsys_ctod(char digit);
char * numsys_ntos(int64_t num, uint8_t base);
int64_t numsys_ston(char * str, uint8_t base);

#endif