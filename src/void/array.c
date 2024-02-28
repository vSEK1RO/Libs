#include "array.h"
#include "utils.h"

/********************************* GENERAL 12 *********************************/

clib_flag clib_arr_init(clib_arr * out, uint64_t len, uint64_t size)
{
    clib_flag flag=CLIB_UNNAMED;
    *out=(clib_arr)((uint64_t*)malloc(size*len+sizeof(uint64_t)*2)+2);
    if(*out==NULL){
        flag=CLIB_ARR_MEMORY;
    }else{
        flag=CLIB_SUCCESS;
        ((uint64_t*)*out)[-1]=len;
        ((uint64_t*)*out)[-2]=size;
    }
    return flag;
}
clib_flag clib_arr_cast(clib_arr * out, uint64_t len, uint64_t size, void* arr)
{
    clib_flag flag=clib_arr_init(out,len,size);
    if(flag!=CLIB_ARR_MEMORY){
        clib_memcpy(*out,arr,len*size);
    }
    return flag;
}
uint64_t clib_arr_len(clib_arr * a)
{
    if(*a==NULL){
        return 0;
    }else{
        return ((uint64_t*)*a)[-1];
    }
}
uint64_t clib_arr_size(clib_arr * a)
{
    if(*a==NULL){
        return 0;
    }else{
        return ((uint64_t*)*a)[-2];
    }
}
clib_item clib_arr_get(clib_arr * a, uint64_t i)
{
    clib_item item=NULL;
    if(i<clib_arr_len(a)){
        item=(clib_item)&((char*)*a)[i*clib_arr_size(a)];
    }
    return item;
}
clib_flag clib_arr_del(clib_arr * a)
{
    clib_flag flag=CLIB_UNNAMED;
    if(*a==NULL){
        flag=CLIB_ARR_NULL;
    }else{
        free((void *)*a);
        flag=CLIB_SUCCESS;
    }
    return flag;
}
clib_flag clib_arr_copy(clib_arr * a, clib_arr b)
{
    clib_flag flag=CLIB_UNNAMED;
    if(b==NULL){
        flag=CLIB_ARR_NULL;
    }else{
        if(a==NULL){
            flag=clib_arr_init(a,clib_arr_len(&b),clib_arr_size(&b));
        }else{
            flag=CLIB_SUCCESS;
            clib_memcpy(
                (uint64_t*)*a-2,
                (uint64_t*)b-2,
                clib_arr_len(&b)*clib_arr_size(&b)+sizeof(uint64_t)*2
            );
        }
        return flag;
    }
}
clib_flag clib_arr_isEqual(clib_arr * a, clib_arr b)
{
    clib_flag flag=CLIB_TRUE;
    if(
        clib_arr_len(a)!=clib_arr_len(&b) ||
        clib_arr_size(a)!=clib_arr_size(&b)
    ){
        flag=CLIB_FALSE;
    }
    for(uint64_t i=0;i<clib_arr_len(a);i++){
        for(uint64_t j=0;j<clib_arr_size(a);j++){
            if(
                ((char*)clib_arr_get(a,i))[j]!=
                ((char*)clib_arr_get(&b,i))[j]
            ){
                flag=CLIB_FALSE;
            }
        }
    }
    return flag;
}
uint64_t clib_arr_find(clib_arr * a, clib_item key, uint64_t entry)
{
    entry%=clib_arr_len(a)+1;
    uint64_t i=-1;
    while(entry && i!=clib_arr_len(a)){
        i++;zxzz
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}
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

clib_item clib_arr_pob(clib_arr * a);
clib_flag clib_arr_pub(clib_arr * a, clib_item b);
clib_item clib_arr_pof(clib_arr * a);
clib_flag clib_arr_puf(clib_arr * a, clib_item b);

/******************************** INSERTIONS 5 ********************************/

clib_flag clib_arr_concat(clib_arr * out, clib_arr * a, clib_arr b);
clib_flag clib_arr_ins(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_insArr(clib_arr * a, clib_arr b, uint64_t i);
clib_flag clib_arr_repl(clib_arr * a, clib_item b, uint64_t i);
clib_flag clib_arr_replArr(clib_arr * a, clib_arr b, uint64_t i);