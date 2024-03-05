#ifndef CLIB_ARRAY_H
#define CLIB_ARRAY_H

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

#include "types.h"
#include "utils.h"

/********************************* GENERAL 12 *********************************/

clib_flag clib_arr_init(clib_arr * out, uint64_t len, uint64_t size);
clib_flag clib_arr_cast(clib_arr * out, uint64_t len, uint64_t size, void* arr);
uint64_t clib_arr_len(clib_arr * a);
uint64_t clib_arr_size(clib_arr * a);
clib_item clib_arr_get(clib_arr * a, uint64_t i);
clib_flag clib_arr_del(clib_arr * a);
clib_flag clib_arr_copy(clib_arr * a, clib_arr b);
clib_flag clib_arr_isEqual(clib_arr * a, clib_arr b);
uint64_t clib_arr_find(clib_arr * a, clib_item key, uint64_t entry);
uint64_t clib_arr_findArr(clib_arr * a, clib_arr key, uint64_t entry);
uint64_t clib_arr_count(clib_arr * a, clib_item key);
uint64_t clib_arr_countArr(clib_arr * a, clib_arr key);

/******************************* PERMUTATIONS 5 *******************************/

clib_flag clib_arr_swap(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_rearr(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_erase(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_reverse(clib_arr * a);
clib_flag clib_arr_substr(clib_arr * out, clib_arr * a, uint64_t i1, uint64_t i2);

/********************************* STACKABLE 4 ********************************/

clib_flag clib_arr_pob(clib_arr * a);
clib_flag clib_arr_pub(clib_arr * a, clib_item b);
clib_flag clib_arr_pof(clib_arr * a);
clib_flag clib_arr_puf(clib_arr * a, clib_item b);

/******************************** INSERTIONS 5 ********************************/

clib_flag clib_arr_concat(clib_arr * out, clib_arr * a, clib_arr b);
clib_flag clib_arr_ins(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_insArr(clib_arr * a, clib_arr b, uint64_t i);
clib_flag clib_arr_repl(clib_arr * a, clib_item b, uint64_t i1, uint64_t i2);
clib_flag clib_arr_replArr(clib_arr * a, clib_arr b, uint64_t i1, uint64_t i2);

#endif

/************************** IMPLEMENTATION_ON_MACROS **************************/

#ifdef ARR_TYPE

#define ARR_FUNC_T(type, name) clib_arr_  ## name ## _ ## type
#define ARR_FUNC(...) ARR_FUNC_T(__VA_ARGS__)

#define ARR_TDEF_T(type, name) name ## _ ## type
#define ARR_TDEF(...) ARR_TDEF_T(__VA_ARGS__)

typedef ARR_TYPE * ARR_TDEF(ARR_TYPE,clib_arr);
typedef ARR_TYPE * ARR_TDEF(ARR_TYPE,clib_item);

#define ARR_CHECK_TYPE(type, arr, res)\
    if(clib_arr_size((clib_arr*)arr)!=sizeof(type))\
        return res

//comt GENERAL 12

clib_flag ARR_FUNC(ARR_TYPE,init)(ARR_TDEF(ARR_TYPE,clib_arr) * out, uint64_t len)
{
    return clib_arr_init((clib_arr*)out,len,sizeof(ARR_TYPE));
}
clib_flag ARR_FUNC(ARR_TYPE,cast)(ARR_TDEF(ARR_TYPE,clib_arr) * out, uint64_t len, void* arr)
{
    return clib_arr_cast((clib_arr*)out,len,sizeof(ARR_TYPE),arr);
}
uint64_t ARR_FUNC(ARR_TYPE,len)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_len((clib_arr*)a);
}
uint64_t ARR_FUNC(ARR_TYPE,size)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_size((clib_arr*)a);
}
ARR_TDEF(ARR_TYPE,clib_item) ARR_FUNC(ARR_TYPE,get)(ARR_TDEF(ARR_TYPE,clib_arr) * a, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,NULL);
    return (ARR_TDEF(ARR_TYPE,clib_item))clib_arr_get((clib_arr*)a,i);
}
clib_flag ARR_FUNC(ARR_TYPE,del)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_del((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,copy)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_copy((clib_arr*)a,(clib_arr)b);
}
clib_flag ARR_FUNC(ARR_TYPE,isEqual)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_isEqual((clib_arr*)a,(clib_arr)b);
}
uint64_t ARR_FUNC(ARR_TYPE,find)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) key, uint64_t entry)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_find((clib_arr*)a,(clib_item)key,entry);
}
uint64_t ARR_FUNC(ARR_TYPE,findArr)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) key, uint64_t entry)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_findArr((clib_arr*)a,(clib_arr)key,entry);
}
uint64_t ARR_FUNC(ARR_TYPE,count)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) key)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_count((clib_arr*)a,(clib_item)key);
}
uint64_t ARR_FUNC(ARR_TYPE,countArr)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) key)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_countArr((clib_arr*)a,(clib_arr)key);
}

/******************************* PERMUTATIONS 5 *******************************/

clib_flag ARR_FUNC(ARR_TYPE,swap)(ARR_TDEF(ARR_TYPE,clib_arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_swap((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,rearr)(ARR_TDEF(ARR_TYPE,clib_arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_rearr((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,erase)(ARR_TDEF(ARR_TYPE,clib_arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_erase((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,reverse)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_reverse((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,substr)(ARR_TDEF(ARR_TYPE,clib_arr) * out, ARR_TDEF(ARR_TYPE,clib_arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_substr((clib_arr*)out,(clib_arr*)a,i1,i2);
}

/********************************* STACKABLE 4 ********************************/

clib_flag ARR_FUNC(ARR_TYPE,pob)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pob((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,pub)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pub((clib_arr*)a,(clib_item)b);
}
clib_flag ARR_FUNC(ARR_TYPE,pof)(ARR_TDEF(ARR_TYPE,clib_arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pof((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,puf)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_puf((clib_arr*)a,(clib_item)b);
}

/******************************** INSERTIONS 5 ********************************/

clib_flag ARR_FUNC(ARR_TYPE,concat)(ARR_TDEF(ARR_TYPE,clib_arr) * out, ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_concat((clib_arr*)out,(clib_arr*)a,(clib_arr)b);
}
clib_flag ARR_FUNC(ARR_TYPE,ins)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) b, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_ins((clib_arr*)a,(clib_item)b,i);
}
clib_flag ARR_FUNC(ARR_TYPE,insArr)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) b, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_insArr((clib_arr*)a,(clib_arr)b,i);
}
clib_flag ARR_FUNC(ARR_TYPE,repl)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_item) b, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_repl((clib_arr*)a,(clib_item)b,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,replArr)(ARR_TDEF(ARR_TYPE,clib_arr) * a, ARR_TDEF(ARR_TYPE,clib_arr) b, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_replArr((clib_arr*)a,(clib_arr)b,i1,i2);
}

#undef ARR_TYPE
#undef ARR_FUNC_T
#undef ARR_FUNC
#undef ARR_TDEF_T
#undef ARR_TDEF
#endif