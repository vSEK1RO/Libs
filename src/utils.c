#include "utils.h"

clib_flag clib_mem_copy(void * dest, void * src, uint64_t size)
{
    clib_flag flag=CLIB_UNNAMED;
    if(dest!=NULL && src!=NULL){
        for(uint64_t i=0;i<size;i++){
            ((char*)dest)[i]=((char*)src)[i];
        }
        flag=CLIB_SUCCESS;
    }else{
        flag=CLIB_NULL;
    }
    return flag;
}
clib_flag clib_mem_IsEqual(void * dest, void * src, uint64_t size)
{
    clib_flag flag=CLIB_TRUE;
    if((dest!=NULL) ^ (src==NULL)){
        for(uint64_t i=0;i<size;i++){
            if(((char*)dest)[i]!=((char*)src)[i]){
                flag=CLIB_FALSE;
                break;
            }
        }
    }else{
        flag=CLIB_NULL;
    }
    return flag;
}