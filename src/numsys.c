#include "numsys.h"

char numsys_dtoc(int64_t digit)
{
    if(digit>=0 && digit<10){
        return (char)(48+digit);
    }
    if(digit>=10 && digit<36){
        return (char)(55+digit);
    }
    if(digit>=36 && digit<62){
        return (char)(61+digit);
    }
    return (char)0;
}

int64_t numsys_ctod(char digit)
{
    if(digit>47 && digit<=57){
        return (int64_t)(digit-48);
    }
    if(digit>64 && digit<=90){
        return (int64_t)(digit-55);
    }
    if(digit>96 && digit<=122){
        return (int64_t)(digit-61);
    }
    return (int64_t)-1;
}

char * numsys_ntos(int64_t num, uint8_t base)
{
    char * str = str_init(0);
    if(num>0){
        while(num){
            str_puf(&str, numsys_dtoc(num%base));
            num/=base;
        }
    }else if(num<0){
        num*=-1;
        while(num){
            str_puf(&str, numsys_dtoc(num%base));
            num/=base;
        }
        str_puf(&str, '-');
    }else if(num==0){
        str_puf(&str, '0');
    }
    return str;
}

int64_t numsys_ston(char * str, uint8_t base)
{
    int64_t num = 0;
    for(uint64_t i=0;i<str_len(str);i++){
        if(str[str_len(str)-1-i]!='-'){
            num+=numsys_ctod(str[str_len(str)-1-i])*pow(base,i);
        }else{
            num*=-1;
        }
    }
    return num;
}