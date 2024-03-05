#include "string.h"

char * str_init(uint64_t len)
{
    char * a=(char *)calloc(sizeof(char),len+1);
    a[len]='\0';
    for(uint64_t i=0;i<len;i++){
        a[i]=' ';
    }
    return a;
}

char * str_cast(const char * a)
{   
    uint64_t len=0;
    while(a[len]!='\0'){
        len++;
    }
    char * b=str_init(len);
    for(uint64_t i=0;i<len;i++){
        b[i]=a[i];
    }
    return b;
}

uint64_t str_len(char * a)
{
    uint64_t len=0;
    while(a[len]!='\0'){
        len++;
    }
    return len;
}

void str_del(char * a)
{
    free((void *)a);
}

void str_copy(char ** a, char * b)
{
    *a = str_init(str_len(b));
    for(uint64_t i=0;i<str_len(b);i++){
        (*a)[i]=b[i];
    }
}

uint8_t str_isEqual(char * a, char * b)
{
    if(str_len(a)!=str_len(b)){
        return 0;
    }
    for(uint64_t i=0;i<str_len(a);i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}

void str_swap(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    a[i1]+=a[i2];
    a[i2]=a[i1]-a[i2];
    a[i1]-=a[i2];
}

void str_rearr(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a);
    i2%=str_len(a);
    char buff=a[i1];
    for(uint64_t i=i1;i>i2;i--){
        a[i]=a[i-1];
    }
    a[i2]=buff;
}

void str_erase(char ** a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    char * b=str_init(str_len(*a)-i2+i1);
    for(uint64_t i=0;i<i1;i++){
        b[i]=(*a)[i];
    }
    for(uint64_t i=i2;i<str_len(*a);i++){
        b[i+i1-i2]=(*a)[i];
    }
    str_del(*a);
    *a=b;
}

char * str_substr(char * a, uint64_t i1, uint64_t i2)
{
    i1%=str_len(a)+1;
    i2%=str_len(a)+1;
    char * b=str_init(i2-i1);
    for(uint64_t i=0;i<i2-i1;i++){
        b[i]=a[i+i1];
    }
    return b;
}

uint64_t str_find(char * a, char key, uint64_t entry)
{
    entry%=str_len(a)+1;
    uint64_t i=(uint64_t)-1;
    while(entry && i!=str_len(a)-1){
        i++;
        if(a[i]==key){
            entry--;
        }
    }
    return (entry!=0?(uint64_t)-1:i);
}

uint64_t str_findStr(char * a, char * b, uint64_t entry)
{
    entry%=str_len(a)+1;
    uint64_t i=(uint64_t)-1;
    while(entry && i!=(str_len(a)-str_len(b))){
        i++;
        if(str_isEqual(str_substr(a,i,i+str_len(b)),b)){
            entry--;
        }
    }
    return (entry!=0?(uint64_t)-1:i);
}

uint64_t str_count(char * a, char n)
{
    uint64_t c=0;
    for(uint64_t i=0;i<str_len(a);i++){
        if(a[i]==n){
            c++;
        }
    }
    return c;
}

uint64_t str_countStr(char * a, char * b)
{
    uint64_t c=0;
    for(uint64_t i=0;i<str_len(a)-str_len(b);i++){
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
        for(uint64_t i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i];
        }
        str_del(*a);
        *a=b;
    }
}

void str_pub(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(uint64_t i=0;i<str_len(*a);i++){
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
        for(uint64_t i=0;i<str_len(*a)-1;i++){
            b[i]=(*a)[i+1];
        }
        str_del(*a);
        *a=b;
    }
}

void str_puf(char ** a, char n)
{
    char * b=str_init(str_len(*a)+1);
    for(uint64_t i=0;i<str_len(*a);i++){
        b[i+1]=(*a)[i];
    }
    b[0]=n;
    str_del(*a);
    *a=b;
}

char * str_concat(char * a, char * b)
{
    char * c=str_init(str_len(a)+str_len(b));
    for(uint64_t i=0;i<str_len(a);i++){
        c[i]=a[i];
    }
    for(uint64_t i=0;i<str_len(b);i++){
        c[i+str_len(a)]=b[i];
    }
    return c;
}

void str_ins(char ** a, char n, uint64_t i)
{
    i%=str_len(*a)+1;
    str_pub(a,n);
    str_rearr(*a,str_len(*a)-1,i);
}

void str_insStr(char ** a, char * b, uint64_t i)
{
    i%=str_len(*a)+1;
    *a=str_concat(str_concat(str_substr(*a,0,i),b),str_substr(*a,i,str_len(*a)));
}

void str_repl(char ** a, char n, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_ins(a,n,i1);
}

void str_replStr(char ** a, char * b, uint64_t i1, uint64_t i2)
{
    i1%=str_len(*a)+1;
    i2%=str_len(*a)+1;
    str_erase(a,i1,i2);
    str_insStr(a,b,i1);
}

void str_reverse(char * a)
{
    for(uint64_t i=0;i<str_len(a)/2;i++){
        str_swap(a,i,str_len(a)-1-i);
    }
}