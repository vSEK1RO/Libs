#include <stdlib.h>
#include <stdio.h>

Array * arr_init(long long int len)
{
    Array * a=(Array *)malloc(sizeof(Array));
    a->len=len;
    a->val=(long long int *)calloc(sizeof(long long int),len);
    for(long long int i=0;i<a->len;i++){
        a->val[i]=0;
    }
    return a;
}

void arr_print(Array * a)
{
    for(long long int i=0;i<a->len;i++){
        printf(i==a->len-1?"%d":"%d ",a->val[i]);
    }
}

void arr_del(Array * a)
{
    for(long long int i=0;i<a->len;i++){
        free(a->val+i);
    }
    free(a);
}

long long int arr_isEqual(Array * a, Array * b)
{
    if(a->len!=b->len){
        return 0;
    }
    for(long long int i=0;i<a->len;i++){
        if(a->val[i]!=b->val[i]){
            return 0;
        }
    }
    return 1;
}

void arr_swap(Array * a, long long int i1, long long int i2)
{
    i1%=a->len;
    i2%=a->len;
    a->val[i1]=a->val[i1]+a->val[i2];
    a->val[i2]=a->val[i2]-a->val[i1];
    a->val[i1]=a->val[i1]-a->val[i2];
}

void arr_rearr(Array * a, long long int i1, long long int i2)
{
    i1%=a->len;
    i2%=a->len;
    long long int buff=a->val[i1];
    for(long long int i=i1;i>i2;i--){
        a->val[i]=a->val[i-1];
    }
    a->val[i2]=buff;
}

void arr_erase(Array * a, long long int i1, long long int i2)
{
    i1%=a->len+1;
    i2%=a->len+1;
    for(long long int i=0;i<a->len-i2;i++){
        a->val[i+i1]=a->val[i+i2];
    }
    for(long long int i=a->len-i2+i1;i<a->len;i++){
        free(a->val+i);
    }
    a->len-=i2-i1;
}

Array * arr_substr(Array * a, long long int i1, long long int i2)
{
    i1%=a->len+1;
    i2%=a->len+1;
    Array * b=arr_init(i2-i1);
    for(int i=0;i<i2-i1;i++){
        b->val[i]=a->val[i+i1];
    }
    return b;
}

long long int arr_find(Array * a, long long int key, long long int entry)
{
    entry%=a->len+1;
    long long int i=-1;
    while(entry && i!=a->len){
        i++;
        if(a->val[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

long long int arr_count(Array * a, long long int n)
{
    long long int c=0;
    for(long long int i=0;i<a->len;i++){
        if(a->val[i]==n){
            c++;
        }
    }
    return c;
}

long long int arr_countArr(Array * a, Array * b)
{
    long long int c=0;
    for(long long int i=0;i<a->len-b->len;i++){
        if(arr_isEqual(arr_substr(a,i,i+b->len),b)){
            c++;
        }
    }
    return c;
}

void arr_pob(Array * a)
{
    free(a->val+a->len-1);
    a->len--;
}

void arr_pub(Array ** a, long long int n)
{
    Array * b=arr_init((*a)->len+1);
    for(long long int i=0;i<(*a)->len;i++){
        b->val[i]=(*a)->val[i];
    }
    b->val[b->len-1]=n;
    *a=b;
}

void arr_pof(Array * a)
{
    for(long long int i=0;i<a->len-1;i++){
        a->val[i]=a->val[i+1];
    }
    free(a->val+a->len-1);
    a->len--;
}

void arr_puf(Array ** a, long long int n)
{
    Array * b=arr_init((*a)->len+1);
    for(long long int i=0;i<(*a)->len;i++){
        b->val[i+1]=(*a)->val[i];
    }
    b->val[0]=n;
    *a=b;
}

Array * arr_concat(Array * a, Array * b)
{
    Array * c=arr_init(a->len+b->len);
    for(long long int i=0;i<a->len;i++){
        c->val[i]=a->val[i];
    }
    for(long long int i=0;i<b->len;i++){
        c->val[i+a->len]=b->val[i];
    }
    return c;
}

void arr_ins(Array ** a, long long int n, long long int i)
{
    i%=(*a)->len+1;
    arr_pub(a,n);
    arr_rearr((*a),(*a)->len-1,i);
}

void arr_insArr(Array ** a, Array * b, long long int i)
{
    i%=(*a)->len+1;
    *a=arr_concat(arr_concat(arr_substr((*a),0,i),b),arr_substr((*a),i,(*a)->len));
}

void arr_replace(Array ** a, long long int n, long long int i1, long long int i2)
{
    i1%=(*a)->len+1;
    i2%=(*a)->len+1;
    arr_erase((*a),i1,i2);
    arr_ins(a,n,i1);
}

void arr_replaceArr(Array ** a, Array * b, long long int i1, long long int i2)
{
    i1%=(*a)->len+1;
    i2%=(*a)->len+1;
    arr_erase((*a),i1,i2);
    arr_insArr(a,b,i1);
}