#include <clib/array.h>
#include <stdio.h>

void logger(char * s, clib_flag f){
    if(f!=CLIB_SUCCESS){
        printf("\033[41mFAILED\033[m\t%s",s);
    }else{
        printf("\033[42mSUCCESS\033[m\t%s",s);
    }
}

int main(){
    return 0;
}