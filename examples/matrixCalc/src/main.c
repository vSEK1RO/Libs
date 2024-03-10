#include <stdio.h>
#include <PDCurses/curses.h>
#include "matrix.h"
#include "field_int.h"

#define flagcheck(flag) if(flag!=CLIB_SUCCESS)return -1;

int main()
{
    mtrx_field f;
    mtrx_field_int_init(&f);
    uint64_t h,w,h2,w2;
    scanf("%lu %lu %lu %lu",&h,&w,&h2,&w2);
    mtrx a,b;
    mtrx_init(&a,h,w,sizeof(int),&f);
    mtrx_init(&b,h2,w2,sizeof(int),&f);
    mtrx_scan(&a);
    mtrx_scan(&b);
    mtrx c;
    mtrx_add(&c,&a,&b);
    mtrx_print(&c,"\t","\n");
    mtrx_del(&a);
    mtrx_del(&b);
    mtrx_del(&c);
}