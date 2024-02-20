#ifndef CLIB_TYPES_H
#define CLIB_TYPES_H

#include <inttypes.h>

/*********************************** GENERAL **********************************/

typedef void * clib_item;
typedef void * clib_arr;
typedef void * clib_str;

/************************************ FLAG ************************************/

typedef enum {
    clib_success,
    clib_index,
    clib_memory,
} clib_flag;

/********************************** RESPONSE **********************************/

typedef struct {
    clib_flag flag;
    //void mean no data
} clib_resp_void;

typedef struct {
    clib_flag flag;
    uint64_t item;
} clib_resp_uint64;

typedef struct {
    clib_flag flag;
    clib_item data;
} clib_resp_item;

typedef struct {
    clib_flag flag;
    clib_arr data;
} clib_resp_arr;

#endif