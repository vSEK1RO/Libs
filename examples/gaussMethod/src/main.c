#include <stdio.h>
#include <ncursesw/curses.h>
#include "mtrx.h"
#include "mtrx_int.h"

int main()
{
    mtrx m;
    mtrx_init(&m,2,2,sizeof(int));
    printf("%lu %lu",mtrx_height(&m),mtrx_width(&m));
    for(uint64_t i=0;i<mtrx_height(&m);i++){
        for(uint64_t j=0;j<mtrx_width(&m);j++){
            scanf("%d",&((int**)m)[i][j]);
        }
    }
    mtrx_mutRow(&m,0,(int[]){2},mtrx_mut_int);
    mtrx_mutRow(&m,1,(int[]){4},mtrx_mut_int);
    mtrx_subRow(&m,0,1,mtrx_sub_int);
    for(uint64_t i=0;i<mtrx_height(&m);i++){
        for(uint64_t j=0;j<mtrx_width(&m);j++){
            printf("%d ",((int**)m)[i][j]);
        }
        printf("\n");
    }
}