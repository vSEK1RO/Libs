#ifndef FIELD_INT_H
#define FIELD_INT_H

#include <inttypes.h>
#include <clib/types.h>

#include "matrix.h"
#include "matrix_types.h"
clib_flag mtrx_item_null_int(mtrx_item out){
    *(int*)out=0;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_neg_int(mtrx_item out, mtrx_item a)
{
    *(int*)out=-*(int*)a;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_add_int(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(int*)a>INT32_MAX-*(int*)b)return CLIB_OVERFLOW;
    *(int*)out=*(int*)a+*(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_sub_int(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(int*)a<INT32_MIN+*(int*)b)return CLIB_OVERFLOW;
    *(int*)out=*(int*)a-*(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mut_int(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(int*)b!=0){
        if(*(int*)a>INT32_MAX/ *(int*)b)return CLIB_OVERFLOW;
    }
    *(int*)out=*(int*)a**(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_div_int(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(int*)b==0)return CLIB_NULL;
    *(int*)out=*(int*)a/ *(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mod_int(mtrx_item out, mtrx_item a, mtrx_item b)
{
    *(int*)out=*(int*)a% *(int*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_scan_int(mtrx_item a)
{
    scanf("%d",(int*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_print_int(mtrx_item a)
{
    printf("%d",*(int*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_prints_int(char * s)
{
    printf("%s",s);
    return CLIB_SUCCESS;
}
clib_flag mtrx_field_int_init(mtrx_field * out)
{
    *out=(mtrx_field){
        .size=sizeof(int),
        .null=mtrx_item_null_int,
        .neg=mtrx_item_neg_int,
        .add=mtrx_item_add_int,
        .sub=mtrx_item_sub_int,
        .mut=mtrx_item_mut_int,
        .div=mtrx_item_div_int,
        .mod=mtrx_item_mod_int,
        .scan=mtrx_item_scan_int,
        .print=mtrx_item_print_int,
        .prints=mtrx_item_prints_int
    };
    return CLIB_SUCCESS;
}

#endif