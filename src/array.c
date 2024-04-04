#include <clib/array.h>

#define nullcheck(arr,ret) if(arr==NULL)return ret
#define flagcheck(flag) if(flag!=CLIB_SUCCESS)goto end
#define CLIB_ARR_OFFSET sizeof(uint64_t)*4

/********************************* GENERAL 16 *********************************/

clib_flag clib_arr_init(clib_arr * out, uint64_t len, uint64_t size)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_eInit(out,len,size,0);
    return flag;
}
clib_flag clib_arr_eInit(clib_arr * out, uint64_t len, uint64_t size, uint64_t eLen)
{
    clib_flag flag=CLIB_UNNAMED;
    uint64_t offset=CLIB_ARR_OFFSET+eLen;
    if(CLIB_ARR_OFFSET>(uint64_t)-1-eLen)return CLIB_ARR_MEMORY;
    if(size>(uint64_t)-1/len)return CLIB_ARR_MEMORY;
    if(size*len>(uint64_t)-1-offset)return CLIB_ARR_MEMORY;
    *out=(clib_arr)((char*)malloc(size*len+offset)+offset);
    if(*out==NULL){
        flag=CLIB_ARR_MEMORY;
    }else{
        flag=CLIB_SUCCESS;
        ((uint64_t*)*out)[-1]=len;
        ((uint64_t*)*out)[-2]=size;
        ((uint64_t*)*out)[-3]=len;
        ((uint64_t*)*out)[-4]=eLen;
    }
    return flag;
}
clib_flag clib_arr_cast(clib_arr * out, uint64_t len, uint64_t size, void* arr)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_init(out,len,size);
    flagcheck(flag);
    flag=clib_mem_copy(*out,arr,len*size);

    end:
    return flag;
}
clib_flag clib_arr_eCast(clib_arr * out, uint64_t len, uint64_t size, uint64_t eLen, void* arr)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_eInit(out,len,size,eLen);
    flagcheck(flag);
    flag=clib_mem_copy(*out,arr,len*size);

    end:
    return flag;
}
uint64_t clib_arr_len(clib_arr * a)
{
    nullcheck(a,0);
    nullcheck(*a,0);
    return ((uint64_t*)*a)[-1];
}
clib_flag __clib_arr_lenSet(clib_arr * a, uint64_t len)
{
    nullcheck(a,CLIB_ARR_NULL);
    nullcheck(*a,CLIB_ARR_NULL);
    ((uint64_t*)*a)[-1]=len;
    return CLIB_SUCCESS;
}
uint64_t clib_arr_size(clib_arr * a)
{
    nullcheck(a,0);
    nullcheck(*a,0);
    return ((uint64_t*)*a)[-2];
}
uint64_t clib_arr_mLen(clib_arr * a)
{
    nullcheck(a,0);
    nullcheck(*a,0);
    return ((uint64_t*)*a)[-3];
}
uint64_t clib_arr_eLen(clib_arr * a)
{
    nullcheck(a,0);
    nullcheck(*a,0);
    return ((uint64_t*)*a)[-4];
}
clib_item clib_arr_get(clib_arr * a, uint64_t i)
{
    clib_item item=NULL;
    if(i<clib_arr_len(a)){
        item=(clib_item)&((char*)*a)[i*clib_arr_size(a)];
    }
    return item;
}
clib_item clib_arr_eGet(clib_arr * a, uint64_t eI)
{
    clib_item item=NULL;
    uint64_t offset=CLIB_ARR_OFFSET+clib_arr_eLen(a);
    if(eI<clib_arr_eLen(a)){
        item=(clib_item)((char*)*a-offset+eI);
    }
    return item;
}
clib_flag clib_arr_del(clib_arr * a)
{
    clib_flag flag=CLIB_UNNAMED;
    nullcheck(a,CLIB_ARR_NULL);
    uint64_t offset=CLIB_ARR_OFFSET+clib_arr_eLen(a);
    free((void *)((char*)*a-offset));
    *a=NULL;
    flag=CLIB_SUCCESS;
    return flag;
}
clib_flag clib_arr_copy(clib_arr * a, clib_arr b)
{
    clib_flag flag=CLIB_UNNAMED;
    nullcheck(b,CLIB_ARR_NULL);
    flag=clib_arr_init(a,clib_arr_len(&b),clib_arr_size(&b));
    flagcheck(flag);
    flag=clib_mem_copy(*a,b,clib_arr_len(&b)*clib_arr_size(&b));

    end:
    return flag;
}
clib_flag clib_arr_isEqual(clib_arr * a, clib_arr * b)
{
    clib_flag flag=CLIB_TRUE;
    if(
        clib_arr_len(a)!=clib_arr_len(b) ||
        clib_arr_size(a)!=clib_arr_size(b)
    ){
        flag=CLIB_FALSE;
    }else{
        flag=clib_mem_IsEqual(*a,*b,clib_arr_len(a)*clib_arr_size(a));
    }
    return flag;
}
uint64_t clib_arr_find(clib_arr * a, clib_item key, uint64_t entry)
{
    entry%=clib_arr_len(a)+1;
    uint64_t i=(uint64_t)-1;
    while(entry && i!=(clib_arr_len(a)-1)){
        i++;
        if(clib_mem_IsEqual(clib_arr_get(a,i),key,clib_arr_size(a))){
            entry--;
        }
    }
    return entry!=0?(uint64_t)-1:i;
}
uint64_t clib_arr_findArr(clib_arr * a, clib_arr key, uint64_t entry)
{
    if(clib_arr_size(a)!=clib_arr_size(&key)){
        return CLIB_TYPE_INCORRECT;
    }
    entry%=clib_arr_len(a)+1;
    uint64_t i=(uint64_t)-1;
    if(clib_arr_len(a)<clib_arr_len(&key)){
        return (uint64_t)-1;
    }
    while(entry && i!=(clib_arr_len(a)-clib_arr_len(&key))){
        i++;
        if(
            clib_mem_IsEqual(
                clib_arr_get(a,i),
                key,clib_arr_size(&key)*clib_arr_len(&key)
            )
        ){
            entry--;
        }
    }
    return entry!=0?(uint64_t)-1:i;
}
uint64_t clib_arr_count(clib_arr * a, clib_item key)
{
    uint64_t c=0;
    for(uint64_t i=0;i<clib_arr_len(a);i++){
        if(clib_mem_IsEqual(clib_arr_get(a,i),key,clib_arr_size(a))){
            c++;
        }
    }
    return c;
}
uint64_t clib_arr_countArr(clib_arr * a, clib_arr key)
{
    if(clib_arr_size(a)!=clib_arr_size(&key)){
        return CLIB_TYPE_INCORRECT;
    }
    uint64_t c=0;
    if(clib_arr_len(a)<clib_arr_len(&key)){
        return 0;
    }
    for(uint64_t i=0;i<clib_arr_len(a)-clib_arr_len(&key);i++){
        if(
            clib_mem_IsEqual(
                clib_arr_get(a,i),
                key,clib_arr_size(&key)*clib_arr_len(&key)
            )
        ){
            c++;
        }
    }
    return c;
}

/******************************* PERMUTATIONS 5 *******************************/

clib_flag clib_arr_swap(clib_arr * a, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    if(i1>clib_arr_len(a) || i2>clib_arr_len(a)){
        return CLIB_ARR_INDEX;
    }
    clib_item buff=malloc(clib_arr_size(a));
    nullcheck(buff,CLIB_ARR_MEMORY);
    flag=clib_mem_copy(
        buff,clib_arr_get(a,i1),clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(a,i1),clib_arr_get(a,i2),clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(a,i2),buff,clib_arr_size(a)
    );

    end:
    free(buff);
    return flag;
}
clib_flag clib_arr_rearr(clib_arr * a, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    if(i1>clib_arr_len(a) || i2>clib_arr_len(a)){
        return CLIB_ARR_INDEX;
    }
    clib_item buff=malloc(clib_arr_size(a));
    nullcheck(buff,CLIB_ARR_MEMORY);
    flag=clib_mem_copy(
        buff,clib_arr_get(a,i1),clib_arr_size(a)
    );
    flagcheck(flag);
    if(i1>i2){
        for(uint64_t i=i1;i>i2;i--){
            flag=clib_mem_copy(
                clib_arr_get(a,i),
                clib_arr_get(a,i-1),
                clib_arr_size(a)
            );
            flagcheck(flag);
        }
    }else{
        for(uint64_t i=i1;i<i2;i++){
            flag=clib_mem_copy(
                clib_arr_get(a,i),
                clib_arr_get(a,i+1),
                clib_arr_size(a)
            );
            flagcheck(flag);
        }
    }
    flag=clib_mem_copy(
        clib_arr_get(a,i2),
        buff,
        clib_arr_size(a)
    );

    end:
    free(buff);
    return flag;
}
clib_flag clib_arr_erase(clib_arr * a, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    if(i1>i2 || i1>clib_arr_len(a) || i2>clib_arr_len(a)){
        return CLIB_ARR_INDEX;
    }
    if(i2-i1==0)return CLIB_SUCCESS;
    uint64_t len=clib_arr_len(a)-(i2-i1);
    uint64_t mLen=clib_arr_mLen(a);
    if(mLen/2<=len){
        for(uint64_t i=i2;i<clib_arr_len(a);i++){
            clib_mem_copy(
                clib_arr_get(a,i-(i2-i1)),
                clib_arr_get(a,i),
                clib_arr_size(a)
            );
        }
        return __clib_arr_lenSet(a,len);
    }
    while(mLen/2>len){
        mLen/=2;
    }
    clib_arr buff;
    flag=clib_arr_init(
        &buff,
        mLen,
        clib_arr_size(a)
    );
    flagcheck(flag);
    flag=__clib_arr_lenSet(a,len);
    flagcheck(flag);
    flag=clib_mem_copy(buff,*a,clib_arr_size(a)*i1);
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(&buff,i1),
        clib_arr_get(a,i2),
        clib_arr_size(a)*(clib_arr_len(a)-i2)
    );

    end:
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
clib_flag clib_arr_reverse(clib_arr * a)
{
    clib_flag flag=CLIB_UNNAMED;
    for(uint64_t i=0;i<clib_arr_len(a)/2;i++){
        flag=clib_arr_swap(a,i,clib_arr_len(a)-1-i);
        if(flag!=CLIB_SUCCESS){
            return flag;
        }
    }
    return flag;
}
clib_flag clib_arr_substr(clib_arr * out, clib_arr * a, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    if(i1>clib_arr_len(a) || i2>clib_arr_len(a)){
        return CLIB_ARR_INDEX;
    }
    clib_arr buff;
    flag=clib_arr_init(
        &buff,
        i2-i1,
        clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(
        buff,clib_arr_get(a,i1),
        clib_arr_size(a)*(i2-i1)
    );

    end:
    if(flag==CLIB_SUCCESS){
        *out=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}

/********************************* STACKABLE 4 ********************************/
//////////
clib_flag clib_arr_pob(clib_arr * a)
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr buff;
    flag=clib_arr_cast(
        &buff,clib_arr_len(a)-1,
        clib_arr_size(a),*a
    );
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
//////////
clib_flag clib_arr_pub(clib_arr * a, clib_item b)
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr buff;
    flag=clib_arr_init(&buff,clib_arr_len(a)+1,clib_arr_size(a));
    flagcheck(flag);
    flag=clib_mem_copy(buff,*a,clib_arr_len(a)*clib_arr_size(a));
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(&buff,clib_arr_len(&buff)-1),
        b,clib_arr_size(a)
    );

    end:
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
//////////
clib_flag clib_arr_pof(clib_arr * a)
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr buff;
    flag=clib_arr_cast(
        &buff,clib_arr_len(a)-1,
        clib_arr_size(a),
        clib_arr_get(a,1)
    );
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
//////////
clib_flag clib_arr_puf(clib_arr * a, clib_item b)
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr buff;
    flag=clib_arr_init(&buff,clib_arr_len(a)+1,clib_arr_size(a));
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(&buff,1),
        *a,clib_arr_len(a)*clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(buff,b,clib_arr_size(a));

    end:
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}

/******************************** INSERTIONS 5 ********************************/

clib_flag clib_arr_concat(clib_arr * out, clib_arr * a, clib_arr * b)
{
    clib_flag flag=CLIB_UNNAMED;
    if(clib_arr_size(a)!=clib_arr_size(b)){
        return CLIB_TYPE_INCORRECT;
    }
    clib_arr buff;
    flag=clib_arr_init(
        &buff,
        clib_arr_len(a)+clib_arr_len(b),
        clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(
        buff,
        *a,
        clib_arr_len(a)*clib_arr_size(a)
    );
    flagcheck(flag);
    flag=clib_mem_copy(
        clib_arr_get(&buff,clib_arr_len(a)),
        *b,
        clib_arr_len(b)*clib_arr_size(b)
    );

    end:
    if(flag==CLIB_SUCCESS){
        *out=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
//////////
clib_flag clib_arr_ins(clib_arr * a, clib_item b, uint64_t i)
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr buff;
    flag=clib_arr_copy(&buff,*a);
    flagcheck(flag);
    flag=clib_arr_pub(&buff,b);
    flagcheck(flag);
    flag=clib_arr_rearr(&buff,clib_arr_len(&buff)-1,i);

    end:
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buff;
    }else{
        clib_arr_del(&buff);
    }
    return flag;
}
//////////
clib_flag clib_arr_insArr(clib_arr * a, clib_arr b, uint64_t i)
{
    clib_flag flag=CLIB_UNNAMED;
    if(clib_arr_size(a)!=clib_arr_size(&b)){
        return CLIB_TYPE_INCORRECT;
    }
    clib_arr buffl, buffr, buff;
    flag=clib_arr_substr(&buffl,a,0,i);
    flagcheck(flag);
    flag=clib_arr_substr(&buffr,a,i,clib_arr_len(a));
    flagcheck(flag);
    flag=clib_arr_concat(&buff,&buffl,&b);
    flagcheck(flag);
    clib_arr_del(&buffl);
    flag=clib_arr_concat(&buffl,&buff,&buffr);
    flagcheck(flag);
    clib_arr_del(&buff);
    clib_arr_del(&buffr);

    end:
    if(flag==CLIB_SUCCESS){
        clib_arr_del(a);
        *a=buffl;
    }else{
        clib_arr_del(&buffl);
    }
    return flag;
}
//////////
clib_flag clib_arr_repl(clib_arr * a, clib_item b, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_erase(a,i1,i2);
    flagcheck(flag);
    flag=clib_arr_ins(a,b,i1);

    end:
    return flag;
}
//////////
clib_flag clib_arr_replArr(clib_arr * a, clib_arr b, uint64_t i1, uint64_t i2)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_erase(a,i1,i2);
    flagcheck(flag);
    flag=clib_arr_insArr(a,b,i1);

    end:
    return flag;
}