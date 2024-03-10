#include <stdio.h>
#include <PDCurses/curses.h>
#include "matrix.h"
#include "field_int.h"

#define flagcheck(flag) if(flag!=CLIB_SUCCESS)return 0;

int main()
{
    clib_flag flag;
    mtrx_field f;
    flag=mtrx_field_int_init(&f);
    flagcheck(flag)
    mtrx m;
    flag=mtrx_init(&m,2,2,sizeof(int),&f);
    flagcheck(flag)
    flag=mtrx_scan(&m);
    flagcheck(flag)
    mtrx_mutRow(&m,0,(int[]){2});
    mtrx_mutRow(&m,1,(int[]){4});
    mtrx_subRow(&m,0,1);
    mtrx_print(&m," ","\n");
    mtrx_del(&m);
}