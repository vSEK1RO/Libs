#ifndef CLIB_TYPES_H
#define CLIB_TYPES_H

#include <inttypes.h>

/*********************************** GENERAL **********************************/

typedef void * clib_item;
typedef void * clib_arr;
typedef void * clib_str;

/************************************ FLAG ************************************/

typedef enum{
    CLIB_SUCCESS,
    CLIB_INDEX,
    CLIB_MEMORY,
    CLIB_ENDLOG,
} clib_flag;

#endif