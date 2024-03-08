#include <stdio.h>
#include <ncursesw/curses.h>
#include "mtrx.h"
#include "mtrx_int.h"

int main()
{
    mtrx m;
    mtrx_init(&m,2,2,sizeof(int));
    mtrx_scan_int(&m);
    mtrx_mutRow(&m,0,(int[]){2},mtrx_mut_int);
    mtrx_mutRow(&m,1,(int[]){4},mtrx_mut_int);
    mtrx_subRow(&m,0,1,mtrx_sub_int);
    mtrx_print_int(&m);
    mtrx_del(&m);
}