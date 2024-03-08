#ifndef MTRX_H
#define MTRX_H

#include <inttypes.h>

#include "../../../src/array.h"
#include "../../../src/types.h"

typedef void * mtrx;
typedef void * mtrx_item;

clib_flag mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size);
uint64_t mtrx_height(mtrx * m);
uint64_t mtrx_width(mtrx * m);
uint64_t mtrx_size(mtrx * m);
mtrx_item mtrx_get(mtrx * m, uint64_t im, uint64_t jn);
clib_flag mtrx_del(mtrx * m);
clib_flag mtrx_subRow(mtrx * m, uint64_t i1, uint64_t i2, clib_flag(*sub)(clib_item a, clib_item b, uint64_t size));
clib_flag mtrx_mutRow(mtrx * m, uint64_t im, mtrx_item lambda, clib_flag(*mut)(clib_item a, clib_item b, uint64_t size));
// clib_flag mtrx_concat(mtrx * out, mtrx * m, mtrx b);
// clib_flag mtrx_splitByColumn(mtrx * out1, mtrx * out2, mtrx * m, uint64_t i);

#endif