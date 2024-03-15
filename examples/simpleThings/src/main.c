    #define ARR_TYPE int
#include <clib/array.h>
#include <stdio.h>

int main()
{
    clib_arr_int arr;
    clib_arr_init_int(&arr,5);
    for(uint64_t i=0;i<clib_arr_len_int(&arr);i++){
        scanf("%d",&arr[i]);
    }

    //needs to be casted because it is clib_arr_int
    clib_arr_reverse((clib_arr*)&arr);
    clib_arr brr;
    //not necessary here, but casting is recommended
    clib_arr_copy(&brr,(clib_arr)arr);
    clib_arr_erase(&brr,2,4);
    for(uint64_t i=0;i<clib_arr_len(&brr);i++){
        //needs to be casted because it is void*
        printf("%d ",((int*)brr)[i]);
    }
    printf("\n");
    clib_arr crr;
    clib_flag flag = clib_arr_concat(&crr,(clib_arr*)&arr,&brr);
    if(flag==CLIB_TYPE_INCORRECT){
        printf("error: type incorrect");
    }else{
        for(uint64_t i=0;i<clib_arr_len(&crr);i++){
            printf("%d ",((int*)crr)[i]);
        }
        clib_arr_del(&crr);
    }
    clib_arr_del(&brr);
    clib_arr_del((clib_arr*)&arr);
}