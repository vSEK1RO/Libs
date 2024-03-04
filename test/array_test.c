#include "../src/void/array.c"
#include "../src/void/types.h"
#include <stdio.h>

clib_flag clib_general(){
    clib_arr a;
    int arr[]={1,2,3,4,5};
/******************************** clib_arr_cast *******************************/
    clib_arr_cast(&a,5,sizeof(int),(int[]){1,2,3,4,5});
    for(uint64_t i=0;i<clib_arr_len(&a);i++){
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
    for(uint64_t i=0;i<clib_arr_len(&a);i++){
        if(arr[i]!=*(int*)clib_arr_get(&a,i)){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_copy *******************************/
    clib_arr b;
    clib_arr_copy(&b,a);
    for(uint64_t i=0;i<clib_arr_len(&a);i++){
        if(((int*)b)[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/****************************** clib_arr_isEqual ******************************/
    if(!clib_arr_isEqual(&a,b))
        return CLIB_TEST_FAILED;
/******************************** clib_arr_find *******************************/
    if(clib_arr_find(&b,(int[]){10},1)!=(uint64_t)-1)
        return CLIB_TEST_FAILED;
    if(clib_arr_find(&b,(int[]){2},1)!=1)
        return CLIB_TEST_FAILED;
/****************************** clib_arr_findArr ******************************/
    clib_arr c;
    clib_arr_cast(&c,3,sizeof(int),(int[]){2,3,4});
    if(clib_arr_findArr(&b,c,10)!=(uint64_t)-1)
        return CLIB_TEST_FAILED;
    if(clib_arr_findArr(&b,c,1)!=1)
        return CLIB_TEST_FAILED;
/******************************* clib_arr_count *******************************/
    if(clib_arr_count(&c,(int[]){3})!=1)
        return CLIB_TEST_FAILED;
    if(clib_arr_count(&c,(int[]){10})!=0)
        return CLIB_TEST_FAILED;
/****************************** clib_arr_countArr *****************************/
    if(clib_arr_countArr(&b,c)!=1)
        return CLIB_TEST_FAILED;
    clib_arr d;
    clib_arr_cast(&d,10,sizeof(int),(int[]){1,2,2,3,4,4,5,6,7,10});
    if(clib_arr_countArr(&d,c)!=1)
        return CLIB_TEST_FAILED;
    if(clib_arr_countArr(&b,d)!=0)
        return CLIB_TEST_FAILED;
/******************************** clib_arr_del ********************************/
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&b)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&c)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&d)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    return CLIB_SUCCESS;
}

clib_flag clib_permutations()
{
/******************************** clib_arr_swap *******************************/
    clib_arr a;
    int arr[]={1,4,3,2,5};
    clib_arr_cast(&a,5,sizeof(int),(int[]){1,2,3,4,5});
    clib_arr_swap(&a,1,3);
    for(uint64_t i=0;i<5;i++){
        if(arr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************* clib_arr_rearr *******************************/
    int brr[]={1,4,5,3,2};
    clib_arr_rearr(&a,4,2);
    for(uint64_t i=0;i<5;i++){
        if(brr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************* clib_arr_erase *******************************/
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr_cast(&a,7,sizeof(int),(int[]){1,4,5,2,3,3,2});
    clib_arr_erase(&a,3,5);
    for(uint64_t i=0;i<5;i++){
        if(brr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/****************************** clib_arr_reverse ******************************/
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr_cast(&a,5,sizeof(int),(int[]){2,3,5,4,1});
    clib_arr_reverse(&a);
    for(uint64_t i=0;i<5;i++){
        if(brr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
    //comt clib_arr_substr
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr_cast(&a,7,sizeof(int),(int[]){2,1,4,5,3,2,3});
    clib_arr buff;
    clib_arr_substr(&buff,&a,1,6);
    for(uint64_t i=0;i<5;i++){
        if(brr[i]!=((int*)buff)[i]){
            return CLIB_TEST_FAILED;
        }
    }
    return CLIB_SUCCESS;
}

void logger(char * s, clib_flag f){
    if(f!=CLIB_SUCCESS){
        printf("----%s FAILED\n",s);
    }else{
        printf("%s success\n",s);
    }
}

int main(){
    logger("clib_arr_general",clib_general());
    logger("clib_arr_permutations",clib_permutations());
}