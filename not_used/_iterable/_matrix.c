#include <stdlib.h>
#include <stdio.h>
#include "_array.h"
#include "_array.ptr.h"

long long int ** mtrx_init(long long int height, long long int width)
{
    long long int ** a=arr_ptr_init(height);
    for(long long int i=0;i<arr_ptr_len(a);i++){
        a[i]=arr_init(width);
    }
    return a;
}

long long int mtrx_width(long long int ** a)
{
    return arr_len(a[0]);
}

long long int mtrx_height(long long int ** a)
{
    return arr_ptr_len(a);
}

void mtrx_print(long long int ** a)
{
    for(long long int i=0;i<mtrx_height(a);i++){
        for(long long int j=0;j<mtrx_width(a);j++){
            printf(j==mtrx_width(a)-1?"%lld":"%lld ",a[i][j]);
        }
        if(i!=mtrx_height(a)-1){
            printf("\n");
        }
    }
}

void mtrx_del(long long int ** a)
{
    for(long long int i=0;i<mtrx_height(a);i++){
        arr_del(a[i]);
    }
    arr_ptr_del(a);
}

long long int mtrx_isEqual(long long int ** a, long long int ** b)
{
    if(mtrx_width(a)!=mtrx_width(b)||mtrx_height(a)!=mtrx_height(b)){
        return 0;
    }
    for(long long int i=0;i<mtrx_height(a);i++){
        for(long long int j=0;j<mtrx_width(a);j++){
            if(a[i][j]!=b[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

long long int ** mtrx_substr(long long int ** a, long long int x1, long long int y1, long long int x2, long long int y2)
{
    y1%=mtrx_height(a);
    y2%=mtrx_height(a);
    x1%=mtrx_width(a);
    x2%=mtrx_width(a);
    long long int ** b=mtrx_init(y2-y1,x2-x1);
    for(long long int i=0;i<y2-y1;i++){
        for(long long int j=0;j<x2-x1;j++){
            b[i][j]=a[i+y1][j+x1];
        }
    }
    return b;
}

void mtrx_replace(long long int ** a, long long int ** b, long long int x, long long int y)
{
    y%=mtrx_height(a);
    x%=mtrx_width(a);
    for(long long int i=0;i<(mtrx_height(b)>mtrx_height(a)-y?mtrx_height(a)-y:mtrx_height(b));i++){
        for(long long int j=0;j<(mtrx_width(b)>mtrx_width(a)-x?mtrx_width(a)-x:mtrx_width(b));j++){
            a[i+y][j+x]=b[i][j];
        }
    }
}

void mtrx_rotateCW(long long int *** a)
{
    long long int ** b=mtrx_init(mtrx_width(a), mtrx_height(a));
    for(long long int i=0;i<mtrx_height(a);i++){
        for(long long int j=0;j<mtrx_width(a);j++){
            b[j][i]=a[i][j];
        }
    }
    mtrx_del(a);
    *a=b;
}

void mtrx_rotateACW(long long int *** a)
{
    long long int ** b=mtrx_init(mtrx_width(a), mtrx_height(a));
    for(long long int i=0;i<mtrx_height(a);i++){
        for(long long int j=0;j<mtrx_width(a);j++){
            b[mtrx_height(a)-j][mtrx_width(a)-i]=a[i][j];
        }
    }
    mtrx_del(a);
    *a=b;
}

void mtrx_reverseVer(long long int ** a)
{

}

void mtrx_reverseHor(long long int ** a)
{

}

void mtrx_swapCol(long long int ** a, long long int x1, long long int x2)
{
    
}

void mtrx_swapRow(long long int ** a, long long int y1, long long int y2)
{

}

void mtrx_insCol(long long int *** a, long long int * b, long long int x);
void mtrx_insRow(long long int *** a, long long int * b, long long int y);
void mtrx_delCol(long long int *** a, long long int * b, long long int x);
void mtrx_delRow(long long int *** a, long long int * b, long long int y);
void mtrx_rearrCol(long long int *** a, long long int * b, long long int x);
void mtrx_rearrRow(long long int *** a, long long int * b, long long int y);