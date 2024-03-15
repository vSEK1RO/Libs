/************************** Tue Mar 05 22:39:34 2024 **************************/
/*                                _      _       __   _        _              */
/*        _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___         */
/*       | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __|        */
/*       | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \        */
/*       |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/        */
/*                        |_|                                                 */
/*                                                                            */
/*                    Created by Vlad Litvinov b23-534                        */
/*                       https://github.com/vSEK1RO                           */
/*                                                                            */
/******************************************************************************/
#ifndef CLIB_ARRAY_H
#define CLIB_ARRAY_H

#include <inttypes.h>
#include <stdlib.h>

#include <clib/types.h>
#include <clib/utils.h>

/********************************* GENERAL 16 *********************************/

clib_flag clib_arr_init(clib_arr * out, uint64_t len, uint64_t size);
clib_flag clib_arr_eInit(clib_arr * out, uint64_t len, uint64_t size, uint64_t eLen);
clib_flag clib_arr_cast(clib_arr * out, uint64_t len, uint64_t size, void* arr);
clib_flag clib_arr_eCast(clib_arr * out, uint64_t len, uint64_t size, uint64_t eLen, void* arr);
uint64_t clib_arr_len(clib_arr * a);
uint64_t clib_arr_size(clib_arr * a);
uint64_t clib_arr_eLen(clib_arr * a);
clib_item clib_arr_get(clib_arr * a, uint64_t i);
clib_item clib_arr_eGet(clib_arr * a, uint64_t eI);
clib_flag clib_arr_del(clib_arr * a);
clib_flag clib_arr_copy(clib_arr * a, clib_arr b);
clib_flag clib_arr_isEqual(clib_arr * a, clib_arr * b);
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

clib_flag clib_arr_concat(clib_arr * out, clib_arr * a, clib_arr * b);
clib_flag clib_arr_ins(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_insArr(clib_arr * a, clib_arr b, uint64_t i);
clib_flag clib_arr_repl(clib_arr * a, clib_item b, uint64_t i1, uint64_t i2);
clib_flag clib_arr_replArr(clib_arr * a, clib_arr b, uint64_t i1, uint64_t i2);

#endif

/************************** IMPLEMENTATION_ON_MACROS **************************/

#ifdef ARR_TYPE

#define ARR_FUNC_T(type, name) clib_arr_  ## name ## _ ## type
#define ARR_FUNC(...) ARR_FUNC_T(__VA_ARGS__)

#define ARR_TDEF_T(type, name) clib_ ## name ## _ ## type
#define ARR_TDEF(...) ARR_TDEF_T(__VA_ARGS__)

typedef ARR_TYPE * ARR_TDEF(ARR_TYPE,arr);
typedef ARR_TYPE * ARR_TDEF(ARR_TYPE,item);

#define ARR_CHECK_TYPE(type, arr, res)\
    if(clib_arr_size((clib_arr*)arr)!=sizeof(type))\
        return res

/********************************* GENERAL 16 *********************************/

clib_flag ARR_FUNC(ARR_TYPE,init)(ARR_TDEF(ARR_TYPE,arr) * out, uint64_t len)
{
    return clib_arr_init((clib_arr*)out,len,sizeof(ARR_TYPE));
}
clib_flag ARR_FUNC(ARR_TYPE,eInit)(ARR_TDEF(ARR_TYPE,arr) * out, uint64_t len, uint64_t eLen)
{
    return clib_arr_eInit((clib_arr*)out,len,sizeof(ARR_TYPE),eLen);
}
clib_flag ARR_FUNC(ARR_TYPE,cast)(ARR_TDEF(ARR_TYPE,arr) * out, uint64_t len, void* arr)
{
    return clib_arr_cast((clib_arr*)out,len,sizeof(ARR_TYPE),arr);
}
clib_flag ARR_FUNC(ARR_TYPE,eCast)(ARR_TDEF(ARR_TYPE,arr) * out, uint64_t len, uint64_t eLen, void* arr)
{
    return clib_arr_eCast((clib_arr*)out,len,sizeof(ARR_TYPE),eLen,arr);
}
uint64_t ARR_FUNC(ARR_TYPE,len)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_len((clib_arr*)a);
}
uint64_t ARR_FUNC(ARR_TYPE,size)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_size((clib_arr*)a);
}
uint64_t ARR_FUNC(ARR_TYPE,eLen)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_eLen((clib_arr*)a);
}
ARR_TDEF(ARR_TYPE,item) ARR_FUNC(ARR_TYPE,get)(ARR_TDEF(ARR_TYPE,arr) * a, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,NULL);
    return (ARR_TDEF(ARR_TYPE,item))clib_arr_get((clib_arr*)a,i);
}
ARR_TDEF(ARR_TYPE,item) ARR_FUNC(ARR_TYPE,eGet)(ARR_TDEF(ARR_TYPE,arr) * a, uint64_t eI)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,NULL);
    return clib_arr_eGet((clib_arr*)a,eI);
}
clib_flag ARR_FUNC(ARR_TYPE,del)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_del((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,copy)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_copy((clib_arr*)a,(clib_arr)b);
}
clib_flag ARR_FUNC(ARR_TYPE,isEqual)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) * b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_isEqual((clib_arr*)a,(clib_arr*)b);
}
uint64_t ARR_FUNC(ARR_TYPE,find)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) key, uint64_t entry)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_find((clib_arr*)a,(clib_item)key,entry);
}
uint64_t ARR_FUNC(ARR_TYPE,findArr)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) key, uint64_t entry)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_findArr((clib_arr*)a,(clib_arr)key,entry);
}
uint64_t ARR_FUNC(ARR_TYPE,count)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) key)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_count((clib_arr*)a,(clib_item)key);
}
uint64_t ARR_FUNC(ARR_TYPE,countArr)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) key)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,0);
    return clib_arr_countArr((clib_arr*)a,(clib_arr)key);
}

/******************************* PERMUTATIONS 5 *******************************/

clib_flag ARR_FUNC(ARR_TYPE,swap)(ARR_TDEF(ARR_TYPE,arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_swap((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,rearr)(ARR_TDEF(ARR_TYPE,arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_rearr((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,erase)(ARR_TDEF(ARR_TYPE,arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_erase((clib_arr*)a,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,reverse)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_reverse((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,substr)(ARR_TDEF(ARR_TYPE,arr) * out, ARR_TDEF(ARR_TYPE,arr) * a, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_substr((clib_arr*)out,(clib_arr*)a,i1,i2);
}

/********************************* STACKABLE 4 ********************************/

clib_flag ARR_FUNC(ARR_TYPE,pob)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pob((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,pub)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pub((clib_arr*)a,(clib_item)b);
}
clib_flag ARR_FUNC(ARR_TYPE,pof)(ARR_TDEF(ARR_TYPE,arr) * a)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_pof((clib_arr*)a);
}
clib_flag ARR_FUNC(ARR_TYPE,puf)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_puf((clib_arr*)a,(clib_item)b);
}

/******************************** INSERTIONS 5 ********************************/

clib_flag ARR_FUNC(ARR_TYPE,concat)(ARR_TDEF(ARR_TYPE,arr) * out, ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) * b)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_concat((clib_arr*)out,(clib_arr*)a,(clib_arr*)b);
}
clib_flag ARR_FUNC(ARR_TYPE,ins)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) b, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_ins((clib_arr*)a,(clib_item)b,i);
}
clib_flag ARR_FUNC(ARR_TYPE,insArr)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) b, uint64_t i)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_insArr((clib_arr*)a,(clib_arr)b,i);
}
clib_flag ARR_FUNC(ARR_TYPE,repl)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,item) b, uint64_t i1, uint64_t i2)
{
    ARR_CHECK_TYPE(ARR_TYPE,a,CLIB_TYPE_INCORRECT);
    return clib_arr_repl((clib_arr*)a,(clib_item)b,i1,i2);
}
clib_flag ARR_FUNC(ARR_TYPE,replArr)(ARR_TDEF(ARR_TYPE,arr) * a, ARR_TDEF(ARR_TYPE,arr) b, uint64_t i1, uint64_t i2)
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