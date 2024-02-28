#ifndef CLIB_ARRAY_H
#define CLIB_ARRAY_H

#include <inttypes.h>
#include "types.h"

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

#endif