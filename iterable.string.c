#include <stdlib.h>
#include <stdio.h>

char * str_init(long long int len)
{
    char * a=(char *)calloc(sizeof(char),len+1);
    a[len]='\0';
    for(long long int i=0;i<len;i++){
        a[i]=' ';
    }
    return a;
}

char * str_cast(const char * a)
{   
    long long int len=sizeof(a)/sizeof(*a);
    char * b=str_init(len);
    for(long long int i=0;i<len;i++){
        b[i]=a[i];
    }
    return b;
}

long long int str_len(char * a)
{
    long long int c=0;
    while(a[c]!='\0'){
        c++;
    }
    return c;
}

void str_print(char * a)
{
    for(long long int i=0;i<str_len(a);i++){
        printf("%c",a[i]);
    }
}

void str_del(char * a)
{
    free((void *)a);
}

long long int str_isEqual(char * a, char * b)
{
    if(str_len(a)!=str_len(b)){
        return 0;
    }
    for(long long int i=0;i<str_len(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void str_swap(char * a, long long int i1, long long int i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    a[i1]+=a[i2];
    a[i2]=a[i1]-a[i2];
    a[i1]-=a[i2];
}

void str_rearr(char * a, long long int i1, long long int i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    char buff=a[i1];
    for(long long int i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void str_erase(char ** a, long long int i1, long long int i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    char * b=str_init(str_len(*a)-i2+i1);
    for(long long int i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(long long int i=i2;i<str_len(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    str_del(*a);
    *a=b;
}

char * str_substr(char * a, long long int i1, long long int i2)
{
    i1%=str_len(a)+1;
    i2%=str_len(a)+1;
    char * b=str_init(i2-i1);
    for(long long int i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

long long int str_find(char * a, char key, long long int entry)
{
    entry%=str_len(a)+1;
    long long int i=-1;
    while(entry && i!=str_len(a)){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?-1:i);
}

long long int str_count(char * a, char n)
{
    long long int c=0;
    for(long long int i=0;i<str_len(a);i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

long long int str_countArr(char * a, char * b)
{
    long long int c=0;
    for(long long int i=0;i<str_len(a)-str_len(b);i++){
        if(str_isEqual(str_substr(a,i,i+str_len(b)),b)){
            c++;
        }
    }
    return c;
}

void str_pob(char ** a)
{   
    if(str_len(*a)!=0){
        char * b=str_init(str_len(*a)-1);
        for(long long int i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i];
        }
        str_del(*a);
        *a=b;
    }
}

void str_pub(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(long long int i=0;i<str_len(*a);i++){
        b[i]=(*a)[i];
    }
    b[str_len(b)-1]=n;
    str_del(*a);
    *a=b;
}

void str_pof(char ** a)
{
    if(str_len(*a)!=0){
        char * b=str_init(str_len(*a)-1);
        for(long long int i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        str_del(*a);
        *a=b;
    }
}

void str_puf(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(long long int i=0;i<str_len(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    str_del(*a);
    *a=b;
}

char * str_concat(char * a, char * b)
{
    char * c=str_init(str_len(a)+str_len(b));
    for(long long int i=0;i<str_len(a);i++){
        c[i]=a[i];
    }
    for(long long int i=0;i<str_len(b);i++){
        c[i+str_len(a)]=b[i];
    }
    return c;
}

void str_ins(char ** a, char n, long long int i)
{
    i%=str_len(*a)+1;
    str_pub(a,n);
    str_rearr(*a,str_len(*a)-1,i);
}

void str_insArr(char ** a, char * b, long long int i)
{
    i%=str_len(*a)+1;
    *a=str_concat(str_concat(str_substr(*a,0,i),b),str_substr(*a,i,str_len(*a)));
}

void str_replace(char ** a, char n, long long int i1, long long int i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_ins(a,n,i1);
}

void str_replaceArr(char ** a, char * b, long long int i1, long long int i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_insArr(a,b,i1);
}

void str_reverse(char *a)
{
    for(long long int i=0;i<str_len(a)/2;i++){
        str_swap(a,i,str_len(a)-1-i);
    }
}