#include <stdio.h>
#include <PDCurses/curses.h>
#include "matrix.h"
#include "field_int.h"

#define flagcheck(flag) if(flag!=CLIB_SUCCESS)return -1;

int main()
{
    mtrx_field f;
    mtrx_field_int_init(&f);
    uint64_t h,w;
    scanf("%lu %lu",&h,&w);
    mtrx m;
    mtrx_init(&m,h,w,sizeof(int),&f);
    for(uint64_t i=0;i<mtrx_height(&m);i++){
        for(uint64_t j=0;j<mtrx_width(&m);j++){
            ((int**)m)[i][j]=(int)(i*mtrx_width(&m)+j);
        }
    }
    mtrx b;
    mtrx_init(&b,h,1,sizeof(int),&f);
    for(uint64_t i=0;i<mtrx_height(&b);i++){
        for(uint64_t j=0;j<mtrx_width(&b);j++){
            ((int**)b)[i][j]=(int)(i*mtrx_width(&b)+j);
        }
    }
    mtrx_print(&m," ","\n");
    mtrx_print(&b," ","\n");
    mtrx em;
    mtrx_concat(&em,&m,&b);
    mtrx_print(&em,"\t","\n");
    mtrx ema, emb;
    mtrx_splitByColumn(&ema,&emb,&em,mtrx_width(&em)-1);
    mtrx_print(&ema,"\t","\n");
    mtrx_print(&emb,"\t","\n");
    mtrx_del(&m);
    mtrx_del(&em);
    mtrx_del(&ema);
    mtrx_del(&emb);
}