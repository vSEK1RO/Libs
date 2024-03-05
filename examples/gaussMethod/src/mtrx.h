#ifndef MTRX_H
#define MTRX_H

#include <inttypes.h>

#include "../../../src/array.h"
#include "../../../src/types.h"

typedef void * mtrx;
typedef void * mtrx_item;

typedef enum{
    MTRX_FALSE = 0,
    MTRX_TRUE = 1,
    MTRX_SUCCESS,
    MTRX_HEIGHT_INCORRECT,
    MTRX_WIDTH_INCORRECT,
    MTRX_UNNAMED,
} mtrx_flag;

mtrx_flag mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size);
uint64_t mtrx_height(mtrx * m);
uint64_t mtrx_width(mtrx * m);
mtrx_flag mtrx_del(mtrx * m);
mtrx_flag mtrx_subRow(mtrx * m, uint64_t i1, uint64_t i2);
mtrx_flag mtrx_mutRow(mtrx * m, mtrx * b, uint64_t i, mtrx_item lambda);
mtrx_flag mtrx_concat(mtrx * out, mtrx * m, mtrx b);
mtrx_flag mtrx_splitByColumn(mtrx * out1, mtrx * out2, mtrx * m, uint64_t i);

#endif