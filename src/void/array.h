#ifndef CLIB_ARRAY_H
#define CLIB_ARRAY_H

#include <inttypes.h>
#include "types.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

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

#ifndef ARR_TYPE //TODO edit to ifdef

#define ARR_FUNC_T(type, name) clib_arr_  ## name ## _ ## type
#define ARR_FUNC(...) ARR_FUNC_T(__VA_ARGS__)

#define ARR_TDEF_T(type) clib_arr_ ## type
#define ARR_TDEF(...) ARR_TDEF_T(__VA_ARGS__)
typedef ARR_TYPE * ARR_TDEF(ARR_TYPE);

#define ARR_TDEFI_T(type) clib_item_ ## type
#define ARR_TDEFI(...) ARR_TDEFI_T(__VA_ARGS__)
typedef ARR_TYPE ARR_TDEFI(ARR_TYPE);

//comt GENERAL 12

clib_flag ARR_FUNC(ARR_TYPE,init)(ARR_TDEF(ARR_TYPE) * out, uint64_t len)
{
    clib_flag flag=CLIB_UNNAMED;
    *out=(ARR_TDEF(ARR_TYPE))((uint64_t*)malloc(sizeof(ARR_TYPE)*len+sizeof(uint64_t)*2)+2);
    if(*out==NULL){
        flag=CLIB_ARR_MEMORY;
    }else{
        flag=CLIB_SUCCESS;
        ((uint64_t*)*out)[-1]=len;
        ((uint64_t*)*out)[-2]=sizeof(ARR_TYPE);
    }
    return flag;
}
clib_flag ARR_FUNC(ARR_TYPE,cast)(clib_arr * out, uint64_t len, uint64_t size, void* arr)
{
    clib_flag flag=CLIB_UNNAMED; //TODO
    flag=clib_arr_init(out,len,size);
    if(flag!=CLIB_SUCCESS)return flag;
    flag=clib_mem_copy(*out,arr,len*size);
    return flag;
}
uint64_t ARR_FUNC(ARR_TYPE,len)(ARR_TYPE * a)
{
    return ((uint64_t *)a)[-1];
}

void ARR_FUNC(ARR_TYPE,del)(ARR_TYPE * a)
{
    uint64_t memlen;//-2 uint64_t instead of memlen
    if(sizeof(ARR_TYPE)>sizeof(uint64_t)){
        memlen=1;
    }else{
        if(sizeof(uint64_t)%sizeof(ARR_TYPE)==0){
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE);
        }else{
            memlen=sizeof(uint64_t)/sizeof(ARR_TYPE)+1;
        }
    }
    free((void *)(a-memlen));
}

void ARR_FUNC(ARR_TYPE,copy)(ARR_TYPE ** a, ARR_TYPE * b)
{
    *a = ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(b));
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(b);i++){
        (*a)[i]=b[i];
    }
}

ARR_TYPE ARR_FUNC(ARR_TYPE,max)(ARR_TYPE * a)
{
    ARR_TYPE max=a[0];
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

ARR_TYPE ARR_FUNC(ARR_TYPE,min)(ARR_TYPE * a)
{
    ARR_TYPE min=a[0];
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    return min;
}

uint8_t ARR_FUNC(ARR_TYPE,isEqual)(ARR_TYPE * a, ARR_TYPE * b)
{
    if(ARR_FUNC(ARR_TYPE,len)(a)!=ARR_FUNC(ARR_TYPE,len)(b)){
        return 0;
    }
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void ARR_FUNC(ARR_TYPE,swap)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a);
    i2%=ARR_FUNC(ARR_TYPE,len)(a);
    ARR_TYPE buff = a[i1];
    a[i1]=a[i2];
    a[i2]=buff;
}

void ARR_FUNC(ARR_TYPE,rearr)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a);
    i2%=ARR_FUNC(ARR_TYPE,len)(a);
    ARR_TYPE buff=a[i1];
    for(uint64_t i=i1;i>i2;i--){//dont work if i1<i2
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void ARR_FUNC(ARR_TYPE,erase)(ARR_TYPE ** a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-i2+i1);
    for(uint64_t i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(uint64_t i=i2;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    ARR_FUNC(ARR_TYPE,del)(*a);
    *a=b;
}

ARR_TYPE * ARR_FUNC(ARR_TYPE,substr)(ARR_TYPE * a, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(i2-i1);
    for(uint64_t i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

uint64_t ARR_FUNC(ARR_TYPE,find)(ARR_TYPE * a, ARR_TYPE key, uint64_t entry)
{
    entry%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    uint64_t i=-1;
    while(entry && i!=(ARR_FUNC(ARR_TYPE,len)(a)-1)){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

uint64_t ARR_FUNC(ARR_TYPE,findArr)(ARR_TYPE * a, ARR_TYPE * b, uint64_t entry)
{
    entry%=ARR_FUNC(ARR_TYPE,len)(a)+1;
    uint64_t i=-1;
    ARR_TYPE * c;
    while(entry && i!=(ARR_FUNC(ARR_TYPE,len)(a)-ARR_FUNC(ARR_TYPE,len)(b))){
        i++;
        c=ARR_FUNC(ARR_TYPE,substr)(a,i,i+ARR_FUNC(ARR_TYPE,len)(b));
        if(ARR_FUNC(ARR_TYPE,isEqual)(c,b)){
            entry--;
        }
        ARR_FUNC(ARR_TYPE,del)(c);
    }
    return (entry!=0?-1:i);
}

uint64_t ARR_FUNC(ARR_TYPE,count)(ARR_TYPE * a, ARR_TYPE n)
{
    uint64_t c=0;
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

uint64_t ARR_FUNC(ARR_TYPE,countArr)(ARR_TYPE * a, ARR_TYPE * b)
{
    uint64_t c=0;
    ARR_TYPE * d;
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a)-ARR_FUNC(ARR_TYPE,len)(b);i++){
        d=ARR_FUNC(ARR_TYPE,substr)(a,i,i+ARR_FUNC(ARR_TYPE,len)(b));
        if(ARR_FUNC(ARR_TYPE,isEqual)(d,b)){
            c++;
        }
        ARR_FUNC(ARR_TYPE,del)(d);
    }
    return c;
}

void ARR_FUNC(ARR_TYPE,pob)(ARR_TYPE ** a)
{
    if(ARR_FUNC(ARR_TYPE,len)(*a)!=0){
        ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i];
        }
        ARR_FUNC(ARR_TYPE,del)(*a);
        *a=b;
    }
}

void ARR_FUNC(ARR_TYPE,pub)(ARR_TYPE ** a, ARR_TYPE n)
{
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i]=(*a)[i];
    }
    b[ARR_FUNC(ARR_TYPE,len)(b)-1]=n;
    *a=b;
}

void ARR_FUNC(ARR_TYPE,pof)(ARR_TYPE ** a)
{
    if(ARR_FUNC(ARR_TYPE,len)(*a)!=0){
        ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)-1);
        for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        ARR_FUNC(ARR_TYPE,del)(*a);
        *a=b;
    }
}

void ARR_FUNC(ARR_TYPE,puf)(ARR_TYPE ** a, ARR_TYPE n)
{
    ARR_TYPE * b=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(*a)+1);
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

ARR_TYPE * ARR_FUNC(ARR_TYPE,concat)(ARR_TYPE * a, ARR_TYPE * b)
{
    ARR_TYPE * c=ARR_FUNC(ARR_TYPE,init)(ARR_FUNC(ARR_TYPE,len)(a)+ARR_FUNC(ARR_TYPE,len)(b));
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a);i++){
        c[i]=a[i];
    }
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(b);i++){
        c[i+ARR_FUNC(ARR_TYPE,len)(a)]=b[i];
    }
    return c;
}

void ARR_FUNC(ARR_TYPE,ins)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i)
{
    i%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,pub)(a,n);
    ARR_FUNC(ARR_TYPE,rearr)(*a,ARR_FUNC(ARR_TYPE,len)(*a)-1,i);
}

void ARR_FUNC(ARR_TYPE,insArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i)
{
    i%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_TYPE * c, * d, * e;
    c=ARR_FUNC(ARR_TYPE,substr)(*a,0,i);
    d=ARR_FUNC(ARR_TYPE,concat)(c,b);
    e=ARR_FUNC(ARR_TYPE,substr)(*a,i,ARR_FUNC(ARR_TYPE,len)(*a));
    *a=ARR_FUNC(ARR_TYPE,concat)(d,e);
    ARR_FUNC(ARR_TYPE,del)(c);
    ARR_FUNC(ARR_TYPE,del)(d);
    ARR_FUNC(ARR_TYPE,del)(e);
}

void ARR_FUNC(ARR_TYPE,repl)(ARR_TYPE ** a, ARR_TYPE n, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,erase)(a,i1,i2);
    ARR_FUNC(ARR_TYPE,ins)(a,n,i1);
}

void ARR_FUNC(ARR_TYPE,replArr)(ARR_TYPE ** a, ARR_TYPE * b, uint64_t i1, uint64_t i2)
{
    i1%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    i2%=ARR_FUNC(ARR_TYPE,len)(*a)+1;
    ARR_FUNC(ARR_TYPE,erase)(a,i1,i2);
    ARR_FUNC(ARR_TYPE,insArr)(a,b,i1);
}

void ARR_FUNC(ARR_TYPE,reverse)(ARR_TYPE * a)
{
    for(uint64_t i=0;i<ARR_FUNC(ARR_TYPE,len)(a)/2;i++){
        ARR_FUNC(ARR_TYPE,swap)(a,i,ARR_FUNC(ARR_TYPE,len)(a)-1-i);
    }
}

#undef ARR_TYPE
#undef ARR_FUNC_T
#undef ARR_FUNC
#undef ARR_TDEF_T
#undef ARR_TDEF
#undef ARR_TDEFI_T
#undef ARR_TDEFI
#endif