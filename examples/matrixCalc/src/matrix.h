#ifndef CLIB_MATRIX_H
#define CLIB_MATRIX_H

#include <inttypes.h>
#include <clib/array.h>
#include <clib/types.h>

#include "matrix_types.h"

clib_flag mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size, mtrx_field * field);
clib_flag mtrx_eInit(mtrx * out, uint64_t m, uint64_t n, uint64_t size, uint64_t eLen, mtrx_field * field);
uint64_t mtrx_height(mtrx * m);
uint64_t mtrx_width(mtrx * m);
uint64_t mtrx_size(mtrx * m);
uint64_t mtrx_eLen(mtrx * m);
mtrx_item mtrx_get(mtrx * m, uint64_t im, uint64_t jn);
mtrx_item mtrx_eGet(mtrx * m, uint64_t eI);
mtrx_field * mtrx_fGet(mtrx * m);
clib_flag mtrx_del(mtrx * m);
clib_flag mtrx_subRow(mtrx * m, uint64_t i1, uint64_t i2);
clib_flag mtrx_mutRow(mtrx * m, uint64_t im, mtrx_item lambda);
clib_flag mtrx_scan(mtrx * m);
clib_flag mtrx_print(mtrx * m, char * sep, char * end);
clib_flag mtrx_concat(mtrx * out, mtrx * m, mtrx * b);
clib_flag mtrx_splitByColumn(mtrx * out1, mtrx * out2, mtrx * m, uint64_t j);
clib_flag mtrx_add(mtrx * out, mtrx * m, mtrx * b);
clib_flag mtrx_mut(mtrx * out, mtrx * m, mtrx * b);
clib_flag mtrx_transp(mtrx * out, mtrx * m);

#endif