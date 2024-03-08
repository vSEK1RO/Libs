#include "mtrx.h"

#define flagcheck(flag) if(flag!=CLIB_SUCCESS)return flag
clib_flag mtrx_init(mtrx * out, uint64_t m, uint64_t n, uint64_t size)
{
    clib_flag flag=CLIB_UNNAMED;
    flag=clib_arr_init((clib_arr*)out,m,sizeof(void*));
    flagcheck(flag);
    for(uint64_t i=0;i<m;i++){
        clib_arr buff=(clib_arr)clib_arr_get((clib_arr*)out,i);
        flag=clib_arr_init(buff,n,size);
        flagcheck(flag);
    }
    return flag;
}
uint64_t mtrx_height(mtrx * m)
{
    return clib_arr_len((clib_arr*)m);
}
uint64_t mtrx_width(mtrx * m)
{
    return clib_arr_len((clib_arr*)clib_arr_get((clib_arr*)m,0));
}
uint64_t mtrx_size(mtrx * m)
{
    return clib_arr_size((clib_arr*)clib_arr_get((clib_arr*)m,0));
}
mtrx_item mtrx_get(mtrx * m, uint64_t im, uint64_t jn)
{
    mtrx_item item=NULL;
    if(im>mtrx_height(m) || jn>mtrx_width(m))return item;
    item=(mtrx_item)clib_arr_get(clib_arr_get((clib_arr*)m,im),jn);
    return item;
}
clib_flag mtrx_del(mtrx * m)
{
    clib_flag flag=CLIB_UNNAMED;
    for(uint64_t i=0;i<mtrx_height(m);i++){
        clib_arr buff=(clib_arr)clib_arr_get((clib_arr*)m,i);
        flag=clib_arr_del(&buff);
        flagcheck(flag);
    }
    flag=clib_arr_del((clib_arr*)m);
    return flag;
}
clib_flag mtrx_subRow(mtrx * m, uint64_t i1, uint64_t i2, clib_flag(*sub)(clib_item a, clib_item b, uint64_t size))
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr a=(clib_arr)clib_arr_get((clib_arr*)m,i1);
    clib_arr b=(clib_arr)clib_arr_get((clib_arr*)m,i2);
    for(uint64_t i=0;i<clib_arr_len(&a);i++){
        flag=sub(clib_arr_get(&a,i),clib_arr_get(&b,i),clib_arr_size(&a));
        flagcheck(flag);
    }
    return flag;
}
clib_flag mtrx_mutRow(mtrx * m, uint64_t im, mtrx_item lambda, clib_flag(*mut)(clib_item a, clib_item b, uint64_t size))
{
    clib_flag flag=CLIB_UNNAMED;
    clib_arr a=(clib_arr)clib_arr_get((clib_arr*)m,im);
    for(uint64_t i=0;i<clib_arr_len(&a);i++){
        flag=mut(clib_arr_get(&a,i),(clib_item)lambda,clib_arr_size(&a));
        flagcheck(flag);
    }
    return flag;
}
// clib_flag mtrx_concat(mtrx * out, mtrx * m, mtrx b)
// {
//     clib_flag flag=CLIB_UNNAMED;
//     if(mtrx_height(m)!=mtrx_height(&b))return CLIB_TYPE_INCORRECT;
//     flag=mtrx_init(out,mtrx_height(m),mtrx_width(m)+mtrx_width(&b),mtrx_size(m));
//     flagcheck(flag);
//     return flag;
// }
// clib_flag mtrx_splitByColumn(mtrx * out1, mtrx * out2, mtrx * m, uint64_t i)
// {

// }