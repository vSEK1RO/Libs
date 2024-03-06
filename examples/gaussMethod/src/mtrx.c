#include "mtrx.h"

#define flgchk(flag) if(flag!=MTRX_SUCCESS)return flag
mtrx_flag mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size)
{
    mtrx_flag flag=MTRX_UNNAMED;
    flag=clib_arr_init((clib_arr*)out,m,sizeof(void*));
    flgchk(flag);
    for(uint64_t i=0;i<m;i++){
        clib_arr buff=(clib_arr)clib_arr_get((clib_arr*)out,i);
        flag=clib_arr_init(&buff,n,size);
        flgchk(flag);
    }
    return flag;
}
uint64_t mtrx_height(mtrx * m)
{
    return clib_arr_len((clib_arr*)m);
}
uint64_t mtrx_width(mtrx * m)
{
    return clib_arr_len((clib_arr*)*(char**)m);
}
mtrx_flag mtrx_del(mtrx * m)
{
    mtrx_flag flag=MTRX_UNNAMED;
    for(uint64_t i=0;i<mtrx_height(m);i++){
        clib_arr buff=(clib_arr)clib_arr_get((clib_arr*)m,i);
        flag=clib_arr_del(&buff);
        flgchk(flag);
    }
    flag=clib_arr_del((clib_arr*)m);
    return flag;
}
mtrx_flag mtrx_subRow(mtrx * m, uint64_t i1, uint64_t i2)
{
    mtrx_flag=MTRX_UNNAMED;
}
mtrx_flag mtrx_mutRow(mtrx * m, mtrx * b, uint64_t i, mtrx_item lambda);
mtrx_flag mtrx_concat(mtrx * out, mtrx * m, mtrx b);
mtrx_flag mtrx_splitByColumn(mtrx * out1, mtrx * out2, mtrx * m, uint64_t i);