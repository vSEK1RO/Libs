#ifndef CLIB_UTILS_H
#define CLIB_UTILS_H

#include <inttypes.h>
#include <stdlib.h>

#include "types.h"

clib_flag clib_mem_copy(void * dest, void * src, uint64_t size);
clib_flag clib_mem_IsEqual(void * dest, void * src, uint64_t size);

#endif