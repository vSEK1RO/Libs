#include <stdio.h>
#include <clib/array.h>
#include <clib/types.h>

void clib_arr_print_int(clib_arr * a){
    for(uint64_t i=0;i<clib_arr_len(a);i++){
        printf("%d ",((int*)*a)[i]);
    }
    printf("\n");
}

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
/******************************* clib_arr_substr ******************************/
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
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&buff)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    return CLIB_SUCCESS;
}

clib_flag clib_stackable()
{
/******************************** clib_arr_pob ********************************/
    clib_arr a;
    clib_arr_cast(&a,7,sizeof(int),(int[]){2,1,4,5,3,2,3});
    int crr[]={2,1,4,5,3,2};
    clib_arr_pob(&a);
    for(uint64_t i=0;i<6;i++){
        if(crr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_pof ********************************/
    int drr[]={1,4,5,3,2};
    clib_arr_pof(&a);
    for(uint64_t i=0;i<5;i++){
        if(drr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_pub ********************************/
    clib_arr_puf(&a,(int[]){2});
    for(uint64_t i=0;i<6;i++){
        if(crr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_puf ********************************/
    int err[]={2,1,4,5,3,2,3};
    clib_arr_pub(&a,(int[]){3});
    for(uint64_t i=0;i<7;i++){
        if(err[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    return CLIB_SUCCESS;
}

clib_flag clib_insertions()
{
/******************************* clib_arr_concat ******************************/
    int crr[]={2,1,4,5,3,2};
    int drr[]={1,4,5,3,2};
    clib_arr a;
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr b;
    clib_arr_cast(&a,3,sizeof(int),(int[]){2,1,4});
    clib_arr_cast(&b,3,sizeof(int),(int[]){5,3,2});
    clib_arr c;
    clib_arr_concat(&c,&a,b);
    for(uint64_t i=0;i<6;i++){
        if(crr[i]!=((int*)c)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_ins ********************************/
    clib_arr d;
    clib_arr_cast(&d,4,sizeof(int),(int[]){1,4,3,2});
    clib_arr_ins(&d,(int[]){5},2);
    for(uint64_t i=0;i<5;i++){
        if(drr[i]!=((int*)d)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************* clib_arr_insArr ******************************/
    int frr[]={2,1,5,3,2,4};
    clib_arr_insArr(&a,b,2);
    for(uint64_t i=0;i<6;i++){
        if(frr[i]!=((int*)a)[i]){
            return CLIB_TEST_FAILED;
        }
    }
/******************************** clib_arr_repl *******************************/
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&b)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&c)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&d)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr_cast(&a,5,sizeof(int),(int[]){1,2,3,4,5});
    clib_arr_cast(&b,4,sizeof(int),(int[]){1,2,10,5});
    clib_arr_repl(&a,(int[]){10},2,4);
    if(!clib_arr_isEqual(&a,b))
        return CLIB_TEST_FAILED;
/****************************** clib_arr_replArr ******************************/
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    clib_arr_cast(&a,6,sizeof(int),(int[]){1,0,3,4,10,5});
    clib_arr_cast(&c,2,sizeof(int),(int[]){2,10});
    clib_arr_replArr(&a,c,1,5);
    if(!clib_arr_isEqual(&a,b))
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&a)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&b)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    if(clib_arr_del(&c)!=CLIB_SUCCESS)
        return CLIB_TEST_FAILED;
    return CLIB_SUCCESS;
}

void logger(char * s, clib_flag f){
    if(f!=CLIB_SUCCESS){
        printf("\033[41mFAILED\033[m\t%s",s);
    }else{
        printf("\033[42mSUCCESS\033[m\t%s",s);
    }
}

int main(){
    logger("\033[2mclib:\033[m\tarr_general\n",clib_general());
    logger("\033[2mclib:\033[m\tarr_permutations\n",clib_permutations());
    logger("\033[2mclib:\033[m\tarr_stackable\n",clib_stackable());
    logger("\033[2mclib:\033[m\tarr_insertions\n",clib_insertions());
    return 0;
}