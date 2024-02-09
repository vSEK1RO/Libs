#define CLIB_ARRAY_H
#include <inttypes.h>
#include "_flag.h"

typedef clib_array void *

clib_array arr_init(uint64_t len, uint64_t sizeof);
uint64_t arr_len(clib_array * a);
clib_flag arr_del(clib_array * a);
clib_flag arr_copy(clib_array * a, clib_array b);