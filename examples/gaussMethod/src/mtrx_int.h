#ifndef MTRX_INT_H
#define MTRX_INT_H

#include "mtrx.h"
#include <clib/types.h>

clib_flag mtrx_sub_int(mtrx_item a, mtrx_item b, uint64_t size)
{
    if(size!=sizeof(int))return CLIB_TYPE_INCORRECT;
    *(int*)a-=*(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_mut_int(mtrx_item a, mtrx_item b, uint64_t size)
{
    if(size!=sizeof(int))return CLIB_TYPE_INCORRECT;
    *(int*)a*=*(int*)b;
    return CLIB_SUCCESS;
}

#endif