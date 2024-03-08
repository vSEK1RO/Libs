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
clib_flag mtrx_scan_int(mtrx * m)
{
    if(mtrx_size(m)!=sizeof(int))return CLIB_TYPE_INCORRECT;
    for(uint64_t i=0;i<mtrx_height(m);i++){
        for(uint64_t j=0;j<mtrx_width(m);j++){
            scanf("%d",&((int**)*m)[i][j]);
        }
    }
    return CLIB_SUCCESS;
}
clib_flag mtrx_print_int(mtrx * m)
{
    if(mtrx_size(m)!=sizeof(int))return CLIB_TYPE_INCORRECT;
    for(uint64_t i=0;i<mtrx_height(m);i++){
        for(uint64_t j=0;j<mtrx_width(m);j++){
            printf("%d ",((int**)*m)[i][j]);
        }
        printf("\n");
    }
    return CLIB_SUCCESS;
}

#endif