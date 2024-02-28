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
    CLIB_SUCCESS = 1,
    CLIB_TRUE = 1,
    CLIB_FALSE = 0,
    CLIB_UNNAMED = 0,
    CLIB_TYPE_INCORRECT = 0,
    CLIB_TEST_FAILED = 0,
    CLIB_NULL = 0,
    //array
    CLIB_ARR_INDEX = 0,
    CLIB_ARR_MEMORY = 0,
    CLIB_ARR_NULL = 0,
    //string
    
} clib_flag;

#endif