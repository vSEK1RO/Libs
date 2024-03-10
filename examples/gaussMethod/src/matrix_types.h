#ifndef MATRIX_TYPES_H
#define MATRIX_TYPES_H

#include <clib/types.h>

typedef void * mtrx;
typedef void * mtrx_item;

typedef struct mtrx_field{
    uint64_t size;
    clib_flag (*null)(mtrx_item out);
    clib_flag (*neg)(mtrx_item out, mtrx_item a);
    clib_flag (*add)(mtrx_item out, mtrx_item a, mtrx_item b);
    clib_flag (*sub)(mtrx_item out, mtrx_item a, mtrx_item b);
    clib_flag (*mut)(mtrx_item out, mtrx_item a, mtrx_item b);
    clib_flag (*div)(mtrx_item out, mtrx_item a, mtrx_item b);
    clib_flag (*scan)(mtrx_item a);
    clib_flag (*print)(mtrx_item a);
    clib_flag (*prints)(char * s);
} mtrx_field;

#endif