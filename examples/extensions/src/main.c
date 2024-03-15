#include <clib/array.h>
#include <stdio.h>

char * clib_arr_name(clib_arr * arr){
    return *(char**)clib_arr_eGet(arr,0);
}

int main(){
    clib_arr drr;
    clib_arr_eInit(&drr,0,sizeof(int),sizeof(char*));
    char * s = "arr_name";
    clib_mem_copy(
        clib_arr_eGet(&drr,0),
        &s,
        sizeof(char*)
    );
    printf("%s",clib_arr_name(&drr));
    clib_arr_del(&drr);
}