#include "array.h"

#include <inttypes.h>
#include "types.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/********************************* GENERAL 10 *********************************/

clib_flag clib_arr_init(clib_arr * out, uint64_t len, uint64_t size)
{
    clib_flag flag;
    *out=(clib_arr)((uint64_t *)malloc(size*len+sizeof(uint64_t)*2)+2);
    if(*out==NULL){
        flag=CLIB_MEMORY;
    }else{
        flag=CLIB_SUCCESS;
        ((uint64_t *)*out)[-1]=len;
        ((uint64_t *)*out)[-1]=size;
    }
    return flag;
}
clib_flag clib_arr_cast(clib_arr * out, uint64_t size, ...);
clib_flag clib_arr_get(clib_item * out, clib_arr * a, uint64_t i)
{
    clib_flag flag;
    printf("%lld",((uint64_t *)*a)[-1]);
    if(0){
        flag=CLIB_INDEX;
        *out=(clib_item)NULL;
    }else{
        flag=CLIB_SUCCESS;
        *out=(clib_item)&((char *)*a)[i*((uint64_t *)*a)[-2]];
    }
    return flag;
}
clib_flag clib_arr_len(uint64_t * out, clib_arr * a);
clib_flag clib_arr_del(clib_arr * a);
clib_flag clib_arr_copy(clib_arr * a, clib_arr b);
clib_flag clib_arr_isEqual(clib_arr * a, clib_arr b);
clib_flag clib_arr_find(uint64_t * out, clib_arr * a, clib_item b, uint64_t entry);
clib_flag clib_arr_findArr(uint64_t * out, clib_arr * a, clib_item * b, uint64_t entry);
clib_flag clib_arr_count(uint64_t * out, clib_arr * a, clib_item b);
clib_flag clib_arr_countArr(uint64_t * out, clib_arr * a, clib_item * b);

/******************************* PERMUTATIONS 5 *******************************/

clib_flag clib_arr_swap(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_rearr(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_erase(clib_arr * a, uint64_t i1, uint64_t i2);
clib_flag clib_arr_reverse(clib_arr * a);
clib_flag clib_arr_substr(clib_arr * out, clib_arr * a, uint64_t i1, uint64_t i2);

/********************************* STACKABLE 4 ********************************/

clib_flag clib_arr_pob(clib_item * out, clib_arr * a);
clib_flag clib_arr_pub(clib_arr * a, clib_item b);
clib_flag clib_arr_pof(clib_item * out, clib_arr * a);
clib_flag clib_arr_puf(clib_arr * a, clib_item b);

/******************************** INSERTIONS 5 ********************************/

clib_flag clib_arr_concat(clib_arr * out, clib_arr * a, clib_arr b);
clib_flag clib_arr_ins(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_insArr(clib_arr * a, clib_arr b, uint64_t i);
clib_flag clib_arr_repl(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_replArr(clib_arr * a, clib_arr b, uint64_t i);