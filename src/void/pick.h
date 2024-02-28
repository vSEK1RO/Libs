#ifndef CLIB_PICK_H
#define CLIB_PICK_H

#include <inttypes.h>
#include "types.h"

#include <stdio.h>
#include "array.h"

#pragma pack(1)

typedef struct{
    char * text;
    clib_flag (*handler)(void);
} clib_pick_option;

typedef struct{
    char * title;
    char * point;
    uint64_t start;
    clib_arr options;
} clib_picker;

clib_flag clib_pick(clib_picker picker)
{
    clib_flag flag;
    uint64_t size;
    uint64_t len;
    clib_arr_size(&size, &picker.options);
    clib_arr_len(&len, &picker.options);
    flag===sizeof(clib_pick_option)?CLIB_SUCCESS:CLIB_TYPE_INCORRECT;
    while(true){
        switch(getchar()){
            '\033[A':
                picker.start++;
                picker.start%=len;
                _clib_pick_render(picker);
                break;
            '\033[B':
                picker.start--;
                picker.start%=len;
                _clib_pick_render(picker);
                break;
            '\x0D':
                (*(clib_pick_option*)picker.options))[picker.start].handler();
                return flag;
                break; 
            default:
                break;
        }
    }
    return flag;
}

void _clib_pick_render(clib_picker picker)
{
    uint64_t size;
    uint64_t len;
    uint64_t point_len
    clib_arr_size(&size, &picker.options);
    clib_arr_len(&len, &picker.options);
    printf("%s\n",picker.title);
    for(uint64_t i=0;i<len;i++){
        if(i==picker.start){
            printf("%s",picker.point);
        }else{
            for(uint64_t j=0;j<point_len;j++){
                putchar(' ');
            }
        }
        printf("%s",(*(clib_pick_option*)picker.options))[picker.start]).text);
    }
}

#endif