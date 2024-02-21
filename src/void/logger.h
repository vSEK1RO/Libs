#ifndef CLIB_LOGGER_H
#define CLIB_LOGGER_H

#include "types.h"
#include <stdio.h>
#include <stdarg.h>

void clib_logger(clib_flag flag, ...){
    va_list args;
    va_start(args, flag);
    printf("clib: logging was started\n");
    clib_flag curr_flag=flag;
    while(curr_flag!=CLIB_ENDLOG){
        switch (curr_flag){
            case CLIB_SUCCESS:
                printf("clib: success\n");break;
            case CLIB_INDEX:
                printf("clib: index\n");break;
            case CLIB_MEMORY:
                printf("clib: memory\n");break;
            default:
                printf("clib: unnamed flag\n");break;
        }
        curr_flag=va_arg(args,clib_flag);
    }
    printf("clib: logging was ended\n");
    va_end(args);
    return;
}

#endif