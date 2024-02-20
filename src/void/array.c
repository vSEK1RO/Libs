#include "array.h"

#include <inttypes.h>
#include "types.h"

/********************************* GENERAL 10 *********************************/

clib_resp_arr arr_init(uint64_t len, uint64_t size)
{
    clib_resp_arr resp;
    resp.data=(clib_arr)((uint64_t *)calloc(size*len+sizeof(uint64_t)*2)+2);
    if(resp.data==NULL){
        resp.flag=clib_index;
    }else{
        resp.flag=clib_success;
        ((uint64_t *)resp.data)[-1]=len;
        ((uint64_t *)resp.data)[-1]=size;
    }
    return resp;
}
clib_resp_arr arr_cast(uint64_t sizeof, ...)
{
}
clib_resp_uint64 arr_len(clib_arr * a)
{

}
clib_resp_void arr_del(clib_arr * a)
{

}
clib_resp_void arr_copy(clib_arr * a, clib_arr b)
{

}
clib_resp_void arr_isEqual(clib_arr * a, clib_arr b)
{

}
clib_resp_uint64 arr_find(clib_arr * a, clib_item b, uint64_t entry)
{

}
clib_resp_uint64 arr_findArr(clib_arr * a, clib_item * b, uint64_t entry)
{

}
clib_resp_uint64 arr_find(clib_arr * a, clib_item b)
{

}
clib_resp_uint64 arr_find(clib_arr * a, clib_item * b)
{

}

/******************************* PERMUTATIONS 7 *******************************/

clib_resp_void arr_swap(clib_arr * a, uint64_t i1, uint64_t i2)
{

}
clib_resp_void arr_rearr(clib_arr * a, uint64_t i1, uint64_t i2)
{

}
clib_resp_void arr_erase(clib_arr * a, uint64_t i1, uint64_t i2)
{

}
clib_resp_void arr_reverse(clib_arr * a)
{

}
clib_resp_arr arr_substr(clib_arr * a, uint64_t i1, uint64_t i2)
{

}
clib_resp_arr arr_slice(clib_arr * a, uint64_t i1, uint64_t i2)
{

}
clib_resp_arr arr_splice(clib_arr * a, uint64_t i1, uint64_t i2)
{

}

/********************************* STACKABLE 4 ********************************/

clib_resp_item arr_pob(clib_arr * a)
{

}
clib_resp_void arr_pub(clib_arr * a, clib_item b)
{

}
clib_resp_item arr_pof(clib_arr * a)
{

}
clib_resp_void arr_puf(clib_arr * a, clib_item b)
{

}

/******************************** INSERTIONS 5 ********************************/

clib_resp_arr arr_concat(clib_arr * a, clib_arr b)
{

}
clib_resp_void arr_ins(clib_arr * a, clib_item b, uint64_t i)
{

}
clib_resp_void arr_insArr(clib_arr * a, clib_arr b, uint64_t i)
{

}
clib_resp_arr arr_repl(clib_arr * a, clib_item b, uint64_t i)
{

}
clib_resp_arr arr_replArr(clib_arr * a, clib_arr b, uint64_t i)
{

}