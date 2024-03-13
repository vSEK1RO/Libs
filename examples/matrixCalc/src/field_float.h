#ifndef FIELD_FLOAT_H
#define FIELD_FLOAT_H

#include <inttypes.h>
#include <clib/types.h>
#include <PDCurses/curses.h>

#include "matrix.h"
#include "matrix_types.h"
clib_flag mtrx_item_null_float(mtrx_item out){
    *(float*)out=0;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_neg_float(mtrx_item out, mtrx_item a)
{
    *(float*)out=-*(float*)a;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_add_float(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(float*)a>INT32_MAX-*(float*)b)return CLIB_OVERFLOW;
    *(float*)out=*(float*)a+*(float*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_sub_float(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(float*)a<INT32_MIN+*(float*)b)return CLIB_OVERFLOW;
    *(float*)out=*(float*)a-*(float*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mut_float(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(float*)b!=0){
        if(*(float*)a>INT32_MAX/ *(float*)b)return CLIB_OVERFLOW;
    }
    *(float*)out=*(float*)a**(float*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_div_float(mtrx_item out, mtrx_item a, mtrx_item b)
{
    if(*(float*)b==0)return CLIB_NULL;
    *(float*)out=*(float*)a/ *(float*)b;
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_mod_float(
    __attribute__((unused)) mtrx_item out,
    __attribute__((unused)) mtrx_item a,
    __attribute__((unused)) mtrx_item b)
{
    return CLIB_TYPE_INCORRECT;
}
clib_flag mtrx_item_scan_float(mtrx_item a)
{
    scanw("%d",(float*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_print_float(mtrx_item a)
{
    printw("%d",*(float*)a);
    return CLIB_SUCCESS;
}
clib_flag mtrx_item_prints_float(char * s)
{
    printw("%s",s);
    return CLIB_SUCCESS;
}
clib_flag mtrx_field_float_init(mtrx_field * out)
{
    *out=(mtrx_field){
        .size=sizeof(float),
        .null=mtrx_item_null_float,
        .neg=mtrx_item_neg_float,
        .add=mtrx_item_add_float,
        .sub=mtrx_item_sub_float,
        .mut=mtrx_item_mut_float,
        .div=mtrx_item_div_float,
        .mod=mtrx_item_mod_float,
        .scan=mtrx_item_scan_float,
        .print=mtrx_item_print_float,
        .prints=mtrx_item_prints_float
    };
    return CLIB_SUCCESS;
}

#endif