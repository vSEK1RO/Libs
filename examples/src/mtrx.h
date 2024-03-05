#ifndef MTRX_H
#define MTRX_H

#include <inttypes.h>

#include "../../src/array.h"
#include "../../src/types.h"

typedef void * mtrx;

void mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size);
void mtrx_del(mtrx * out);
void mtrx_subsLine();
void mtrx_mutLine();

#endif
