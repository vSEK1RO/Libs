#include <stdlib.h>
#include <stdio.h>

long long int ** arr_ptr_init(long long int len)
{
    long long int ** a=(long long int **)calloc(sizeof(long long int *),len+1)+1;
    a[-1]=(long long int *)malloc(sizeof(long long int));
    *(a[-1])=len;
    return a;
}

long long int arr_ptr_len(long long int ** a)
{
    return *(a[-1]);
}

void arr_ptr_del(long long int ** a)
{
    free((void *)(a-1));
}

void arr_ptr_swap(long long int ** a, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(a);
    i2%=arr_ptr_len(a);
    long long int * buff=a[i1];
    a[i1]=a[i2];
    a[i2]=buff;
}

void arr_ptr_rearr(long long int ** a, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(a);
    i2%=arr_ptr_len(a);
    long long int * buff=a[i1];
    for(long long int i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void arr_ptr_erase(long long int *** a, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(*a)+1;
    i2%=arr_ptr_len(*a)+1;
    long long int ** b=arr_ptr_init(arr_ptr_len(*a)-i2+i1);
    for(long long int i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(long long int i=i2;i<arr_ptr_len(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    arr_ptr_del(*a);
    *a=b;
}

long long int ** arr_ptr_substr(long long int ** a, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(a)+1;
    i2%=arr_ptr_len(a)+1;
    long long int ** b=arr_ptr_init(i2-i1);
    for(long long int i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

void arr_ptr_pob(long long int *** a)
{
    if(arr_ptr_len(*a)!=0){
        long long int ** b=arr_ptr_init(arr_ptr_len(*a)-1);
        for(long long int i=0;i<arr_ptr_len(*a)-1;i++){
            b[i]=(*a)[i];
        }
        arr_ptr_del(*a);
        *a=b;
    }
}

void arr_ptr_pub(long long int *** a, long long int * n)
{
    long long int ** b=arr_ptr_init(arr_ptr_len(*a)+1);
    for(long long int i=0;i<arr_ptr_len(*a);i++){
        b[i]=(*a)[i];
    }
    b[arr_ptr_len(b)-1]=n;
    *a=b;
}

void arr_ptr_pof(long long int *** a)
{
    if(arr_ptr_len(*a)!=0){
        long long int ** b=arr_ptr_init(arr_ptr_len(*a)-1);
        for(long long int i=0;i<arr_ptr_len(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        arr_ptr_del(*a);
        *a=b;
    }
}

void arr_ptr_puf(long long int *** a, long long int * n)
{
    long long int ** b=arr_ptr_init(arr_ptr_len(*a)+1);
    for(long long int i=0;i<arr_ptr_len(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

long long int ** arr_ptr_concat(long long int ** a, long long int ** b)
{
    long long int ** c=arr_ptr_init(arr_ptr_len(a)+arr_ptr_len(b));
    for(long long int i=0;i<arr_ptr_len(a);i++){
        c[i]=a[i];
    }
    for(long long int i=0;i<arr_ptr_len(b);i++){
        c[i+arr_ptr_len(a)]=b[i];
    }
    return c;
}

void arr_ptr_ins(long long int *** a, long long int * n, long long int i)
{
    i%=arr_ptr_len(*a)+1;
    arr_ptr_pub(a,n);
    arr_ptr_rearr(*a,arr_ptr_len(*a)-1,i);
}

void arr_ptr_insArr(long long int *** a, long long int ** b, long long int i)
{
    i%=arr_ptr_len(*a)+1;
    *a=arr_ptr_concat(arr_ptr_concat(arr_ptr_substr(*a,0,i),b),arr_ptr_substr(*a,i,arr_ptr_len(*a)));
}

void arr_ptr_replace(long long int *** a, long long int * n, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(*a)+1;
    i2%=arr_ptr_len(*a)+1;
    arr_ptr_erase(a,i1,i2);
    arr_ptr_ins(a,n,i1);
}

void arr_ptr_replaceArr(long long int *** a, long long int ** b, long long int i1, long long int i2)
{
    i1%=arr_ptr_len(*a)+1;
    i2%=arr_ptr_len(*a)+1;
    arr_ptr_erase(a,i1,i2);
    arr_ptr_insArr(a,b,i1);
}

void arr_ptr_reverse(long long int ** a)
{
    for(long long int i=0;i<arr_ptr_len(a)/2;i++){
        arr_ptr_swap(a,i,arr_ptr_len(a)-1-i);
    }
}