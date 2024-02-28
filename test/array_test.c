#include "../src/void/array.c"
#include "../src/void/types.h"
#include <stdio.h>

clib_flag clib_general(){
    clib_arr a;
    int arr[]={1,2,3,4,5};
/******************************** clib_arr_cast *******************************/
    clib_arr_cast(&a,5,sizeof(int),(int[]){1,2,3,4,5});
    for(int i=0;i<clib_arr_len(&a);i++){
        if(arr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_len ********************************/
    if(clib_arr_len(&a)!=5){
        return CLIB_TEST_FAILED;
    }
/******************************** clib_arr_size *******************************/
    if(clib_arr_size(&a)!=4){
        return CLIB_TEST_FAILED;
    }
/******************************** clib_arr_get ********************************/
    for(int i=0;i<clib_arr_len(&a);i++){
        if(arr[i]!=*(int*)clib_arr_get(&a,i)){
            return CLIB_TEST_FAILED;
        }
    }
//comt clib_arr_copy
    clib_arr b;
    clib_arr_copy(&b,a);
    for(int i=0;i<clib_arr_len(&a);i++){
        if(((int*)b)[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
//comt clib_arr_isEqual
    if(!clib_arr_isEqual(&a,b)){
        return CLIB_TEST_FAILED;
    }
//comt clib_arr_find
    if(clib_arr_find(&b,10,1)!=-1)
        return CLIB_TEST_FAILED;
    if(clib_arr_find(&b,2,1)!=1)
        return CLIB_TEST_FAILED;
//comt clib_arr_findArr
    clib_arr c;
    clib_arr_cast(&c,3,sizeof(int),(int[]){2,3,4});
    if(clib_arr_findArr(&b,c,10)!=-1)
        return CLIB_TEST_FAILED;
    if(clib_arr_findArr(&b,c,1)!=1)
        return CLIB_TEST_FAILED;
    return CLIB_SUCCESS;
}

void logger(char * s, clib_flag f){
    if(f!=CLIB_SUCCESS){
        printf("----%s FAILED",s);
    }else{
        printf("%s success",s);
    }
}

int main(){
    logger("clib_general",clib_general());
}