#ifndef FIELD_FLOAT_H
#define FIELD_FLOAT_H

#include <inttypes.h>
#include <clib/types.h>
#include <curses.h>

#include "matrix.h"
#include "matrix_types.h"
clib_flag mtrx_item_null_double(mtrx_item out){
    *(double*)out=0;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_neg_double(mtrx_item out, mtrx_item a)
{
    *(double*)out=-*(double*)a;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_add_double(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(double*)a>INT32_MAX-*(double*)b)return CLIB_OVERFLOW;
    *(double*)out=*(double*)a+*(double*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_sub_double(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(double*)a<INT32_MIN+*(double*)b)return CLIB_OVERFLOW;
    *(double*)out=*(double*)a-*(double*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mut_double(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(double*)b!=0){
        if(*(double*)a>INT32_MAX/ *(double*)b)return CLIB_OVERFLOW;
    }
    *(double*)out=*(double*)a**(double*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_div_double(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(double*)b==0)return CLIB_NULL;
    *(double*)out=*(double*)a/ *(double*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mod_double(
    __attribute__((unused)) mtrx_item out,
    __attribute__((unused)) mtrx_item a,
    __attribute__((unused)) mtrx_item b)
{
    return CLIB_TYPE_INCORRECT;
}
clib_flag mtrx_item_scan_double(mtrx_item a)
{
    scanw("%d",(double*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_print_double(mtrx_item a)
{
    printw("%d",*(double*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_prints_double(char * s)
{
    printw("%s",s);
    return CLIB_SUCCESS;
}
clib_flag mtrx_field_double_init(mtrx_field * out)
{
    *out=(mtrx_field){
        .size=sizeof(double),
        .null=mtrx_item_null_double,
        .neg=mtrx_item_neg_double,
        .add=mtrx_item_add_double,
        .sub=mtrx_item_sub_double,
        .mut=mtrx_item_mut_double,
        .div=mtrx_item_div_double,
        .mod=mtrx_item_mod_double,
        .scan=mtrx_item_scan_double,
        .print=mtrx_item_print_double,
        .prints=mtrx_item_prints_double
    };
    return CLIB_SUCCESS;
}

#endif