#ifndef CLIB_LOGGER_H
#define CLIB_LOGGER_H

#include "types.h"

#include <stdio.h>
#include <stdarg.h>

static uint64_t fcount = 0,
                lcount = 0;

#define clib_logger(flag, ...)\
    switch (flag){\
        case CLIB_SUCCESS:\
            printf("[call: %20llu] CLIB_SUCCESS\n",fcount);break;\
        case CLIB_INDEX:\
            printf("[call: %20llu] CLIB_INDEX\n",fcount);break;\
        case CLIB_MEMORY:\
            printf("[call: %20llu] CLIB_MEMORY\n",fcount);break;\
        default:\
            printf("[call: %20llu] CLIB_UNNAMED_FLAG\n",fcount);break;\
    }\
    fcount++;

void clib_log(clib_flag flag){
    switch (flag){
        case CLIB_SUCCESS:
            printf("[call: %20llu] CLIB_SUCCESS\n",fcount);break;
        case CLIB_INDEX:
            printf("[call: %20llu] CLIB_INDEX\n",fcount);break;
        case CLIB_MEMORY:
            printf("[call: %20llu] CLIB_MEMORY\n",fcount);break;
        default:
            printf("[call: %20llu] CLIB_UNNAMED_FLAG\n",fcount);break;
    }
        fcount++;
    }while((flag=va_arg(args,flag))!=CLIB_ENDLOG);
    printf("[logger: %18llu] CLIB_LOG_ENDED\n", lcount);
    va_end(args);
    lcount++;
    return;
}

#endif