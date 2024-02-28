#ifndef CLIB_UTILS_H
#define CLIB_UTILS_H

#include <inttypes.h>

void clib_memcpy(void * dest, void * src, uint64_t size)
{
    for(uint64_t i=0;i<size;i++){
        ((char*)dest)[i]=((char*)src)[i];
    }
}

#endif