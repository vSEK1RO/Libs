#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

long long int * arr_init(long long int len)
{
    long long int * a=(long long int *)calloc(sizeof(long long int),len+1)+1;
    a[-1]=len;
    for(long long int i=0;i<a[-1];i++){
        a[i]=0;
    }
    return a;
}

long long int arr_max(long long int * a)
{
    long long int max=LLONG_MIN;
    for(long long int i=0;i<a[-1];i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

long long int arr_min(long long int * a)
{
    long long int min=LLONG_MAX;
    for(long long int i=0;i<a[-1];i++){
        if(min>a[i]){
            min=a[i];
        }
    }
    return min;
}

void arr_print(long long int * a)
{
    for(long long int i=0;i<a[-1];i++){
        printf(i==a[-1]-1?"%lld":"%lld ",a[i]);
    }
}

void arr_del(long long int * a)
{
    free((void *)(a-1));
}

long long int arr_isEqual(long long int * a, long long int * b)
{
    if(a[-1]!=b[-1]){
        return 0;
    }
    for(long long int i=0;i<a[-1];i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void arr_swap(long long int * a, long long int i1, long long int i2)
{
    i1%=a[-1];
    i2%=a[-1];
    a[i1]+=a[i2];
    a[i2]=a[i1]-a[i2];
    a[i1]-=a[i2];
}

void arr_rearr(long long int * a, long long int i1, long long int i2)
{
    i1%=a[-1];
    i2%=a[-1];
    long long int buff=a[i1];
    for(long long int i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void arr_erase(long long int ** a, long long int i1, long long int i2)
{
    i1%=(*a)[-1]+1;
    i2%=(*a)[-1]+1;
    long long int * b=arr_init((*a)[-1]-i2+i1);
    for(long long int i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(long long int i=i2;i<(*a)[-1];i++){
        b[i+i1-i2]=(*a)[i];
    }
    arr_del(*a);
    *a=b;
}

long long int * arr_substr(long long int * a, long long int i1, long long int i2)
{
    i1%=a[-1]+1;
    i2%=a[-1]+1;
    long long int * b=arr_init(i2-i1);
    for(long long int i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

long long int arr_find(long long int * a, long long int key, long long int entry)
{
    entry%=a[-1]+1;
    long long int i=-1;
    while(entry && i!=a[-1]){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

long long int arr_count(long long int * a, long long int n)
{
    long long int c=0;
    for(long long int i=0;i<a[-1];i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

long long int arr_countArr(long long int * a, long long int * b)
{
    long long int c=0;
    for(long long int i=0;i<a[-1]-b[-1];i++){
        if(arr_isEqual(arr_substr(a,i,i+b[-1]),b)){
            c++;
        }
    }
    return c;
}

void arr_pob(long long int ** a)
{
    if((*a)[-1]!=0){
        long long int * b=arr_init((*a)[-1]-1);
        for(long long int i=0;i<(*a)[-1]-1;i++){
            b[i]=(*a)[i];
        }
        arr_del(*a);
        *a=b;
    }
}

void arr_pub(long long int ** a, long long int n)
{
    long long int * b=arr_init((*a)[-1]+1);
    for(long long int i=0;i<(*a)[-1];i++){
        b[i]=(*a)[i];
    }
    b[b[-1]-1]=n;
    *a=b;
}

void arr_pof(long long int ** a)
{
    if((*a)[-1]!=0){
        long long int * b=arr_init((*a)[-1]-1);
        for(long long int i=0;i<(*a)[-1]-1;i++){
            b[i]=(*a)[i+1];
        }
        arr_del(*a);
        *a=b;
    }
}

void arr_puf(long long int ** a, long long int n)
{
    long long int * b=arr_init((*a)[-1]+1);
    for(long long int i=0;i<(*a)[-1];i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

long long int * arr_concat(long long int * a, long long int * b)
{
    long long int * c=arr_init(a[-1]+b[-1]);
    for(long long int i=0;i<a[-1];i++){
        c[i]=a[i];
    }
    for(long long int i=0;i<b[-1];i++){
        c[i+a[-1]]=b[i];
    }
    return c;
}

void arr_ins(long long int ** a, long long int n, long long int i)
{
    i%=(*a)[-1]+1;
    arr_pub(a,n);
    arr_rearr(*a,(*a)[-1]-1,i);
}

void arr_insArr(long long int ** a, long long int * b, long long int i)
{
    i%=(*a)[-1]+1;
    *a=arr_concat(arr_concat(arr_substr(*a,0,i),b),arr_substr(*a,i,(*a)[-1]));
}

void arr_replace(long long int ** a, long long int n, long long int i1, long long int i2)
{
    i1%=(*a)[-1]+1;
    i2%=(*a)[-1]+1;
    arr_erase(a,i1,i2);
    arr_ins(a,n,i1);
}

void arr_replaceArr(long long int ** a, long long int * b, long long int i1, long long int i2)
{
    i1%=(*a)[-1]+1;
    i2%=(*a)[-1]+1;
    arr_erase(a,i1,i2);
    arr_insArr(a,b,i1);
}

void arr_reverse(long long int *a)
{
    for(long long int i=0;i<a[-1]/2;i++){
        arr_swap(a,i,a[-1]-1-i);
    }
}