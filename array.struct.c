#include <stdlib.h>
#include <stdio.h>

auto * arr_init(long long int len)
{
    auto * a=(auto *)calloc(sizeof(auto),len+1)+1;
    a[-1]=len;
    for(long long int i=0;i<a[-1];i++){
        a[i]=0;
    }
    return a;
}

void arr_print(auto * a)
{
    for(long long int i=0;i<a[-1];i++){
        printf(i==a[-1]-1?"%d":"%d ",a[i]);
    }
}

void arr_del(auto * a)
{
    for(long long int i=-1;i<a[-1];i++){
        free(a);
    }
}

auto arr_isEqual(auto * a, auto * b)
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

void arr_swap(auto * a, long long int i1, long long int i2)
{
    i1%=a[-1];
    i2%=a[-1];
    a[i1]+=a[i2];
    a[i2]-=a[i1];
    a[i1]-=a[i2];
}

void arr_rearr(auto * a, long long int i1, long long int i2)
{
    i1%=a[-1];
    i2%=a[-1];
    auto buff=a[i1];
    for(long long int i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void arr_erase(auto * a, long long int i1, long long int i2)
{
    i1%=a[-1]+1;
    i2%=a[-1]+1;
    for(long long int i=0;i<a[-1]-i2;i++){
        a[i+i1]=a[i+i2];
    }
    for(long long int i=a[-1]-i2+i1;i<a[-1];i++){
        free(a+i);
    }
    a[-1]-=i2-i1;
}

auto * arr_substr(auto * a, long long int i1, long long int i2)
{
    i1%=a[-1]+1;
    i2%=a[-1]+1;
    auto * b=arr_init(i2-i1);
    for(long long int i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

auto arr_find(auto * a, auto key, auto entry)
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

auto arr_count(auto * a, auto n)
{
    auto c=0;
    for(long long int i=0;i<a[-1];i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

auto arr_countArr(auto * a, auto * b)
{
    auto c=0;
    for(long long int i=0;i<a[-1]-b[-1];i++){
        if(arr_isEqual(arr_substr(a,i,i+b[-1]),b)){
            c++;
        }
    }
    return c;
}

void arr_pob(auto * a)
{
    free(a+a[-1]-1);
    a[-1]--;
}

void arr_pub(auto ** a, auto n)
{
    auto * b=arr_init((*a)[-1]+1);
    for(long long int i=0;i<(*a)[-1];i++){
        b[i]=(*a)[i];
    }
    b[b[-1]-1]=n;
    *a=b;
}

void arr_pof(auto * a)
{
    for(long long int i=0;i<a[-1]-1;i++){
        a[i]=a[i+1];
    }
    free(a+a[-1]-1);
    a[-1]--;
}

void arr_puf(auto ** a, auto n)
{
    auto * b=arr_init((*a)[-1]+1);
    for(long long int i=0;i<(*a)[-1];i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    *a=b;
}

auto * arr_concat(auto * a, auto * b)
{
    auto * c=arr_init(a[-1]+b[-1]);
    for(long long int i=0;i<a[-1];i++){
        c[i]=a[i];
    }
    for(long long int i=0;i<b[-1];i++){
        c[i+a[-1]]=b[i];
    }
    return c;
}

void arr_ins(auto ** a, auto n, long long int i)
{
    i%=(*a)[-1]+1;
    arr_pub(a,n);
    arr_rearr(*a,(*a)[-1]-1,i);
}

void arr_insArr(auto ** a, auto * b, long long int i)
{
    i%=(*a)[-1]+1;
    *a=arr_concat(arr_concat(arr_substr(*a,0,i),b),arr_substr(*a,i,(*a)[-1]));
}

void arr_replace(auto ** a, auto n, long long int i1, long long int i2)
{
    i1%=(*a)[-1]+1;
    i2%=(*a)[-1]+1;
    arr_erase(*a,i1,i2);
    arr_ins(a,n,i1);
}

void arr_replaceArr(auto ** a, auto * b, long long int i1, long long int i2)
{
    i1%=(*a)[-1]+1;
    i2%=(*a)[-1]+1;
    arr_erase(*a,i1,i2);
    arr_insArr(a,b,i1);
}