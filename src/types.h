#ifndef CLIB_TYPES_H
#define CLIB_TYPES_H

#include <inttypes.h>

/*********************************** GENERAL **********************************/

typedef void * clib_item;
typedef void * clib_arr;
typedef void * clib_str;

/************************************ FLAG ************************************/

typedef enum{
    //general
    CLIB_FALSE = 0,
    CLIB_TRUE = 1,
    CLIB_SUCCESS,
    CLIB_UNNAMED,
    CLIB_TYPE_INCORRECT,
    CLIB_TEST_FAILED,
    CLIB_NULL,
    //array
    CLIB_ARR_INDEX,
    CLIB_ARR_MEMORY,
    CLIB_ARR_NULL,
    //string
    
} clib_flag;

#endif