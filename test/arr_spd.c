#include <clib/array.h>
#include <stdio.h>
#include <time.h>

#define LOG 0
#define MIL (uint64_t)1e4
#define start_clk() \
    clock_t start_time, end_time;\
    double eltime;\
    start_time = clock();
#define stop_clk() \
    end_time = clock();\
    eltime = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000;

double arr_erase_back()
{   
    clib_arr arr;
    clib_arr_init(&arr,MIL,sizeof(int));
    start_clk();
    while(clib_arr_len(&arr)!=0){
        clib_arr_erase(&arr,clib_arr_len(&arr)-1,clib_arr_len(&arr));
        #if LOG==1
            printf("%ld\t%ld\n",clib_arr_len(&arr),clib_arr_mLen(&arr));
        #endif
    }
    stop_clk();
    return eltime;
}
double arr_erase_front()
{   
    clib_arr arr;
    clib_arr_init(&arr,MIL,sizeof(int));
    start_clk();
    while(clib_arr_len(&arr)!=0){
        clib_arr_erase(&arr,0,1);
        #if LOG==1
            printf("%ld\t%ld\n",clib_arr_len(&arr),clib_arr_mLen(&arr));
        #endif
    }
    stop_clk();
    return eltime;
}
void logger(char * s, double t)
{
    printf("\033[42m%lu OPS\033[m\t%s\t%lf\n",MIL,s,t);
}
int main()
{
    logger("\033[2marr_spd:\033[m\tarr_erase_back()",arr_erase_back());
    logger("\033[2marr_spd:\033[m\tarr_erase_front()",arr_erase_front());
    return 0;
}