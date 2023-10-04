#ifndef ITERABLE_ARRAY_PTR_H
#define ITERABLE_ARRAY_PTR_H

long long int ** arr_ptr_init(long long int len);
long long int arr_ptr_len(long long int ** a);
void arr_ptr_del(long long int ** a);
void arr_ptr_swap(long long int ** a, long long int i1, long long int i2);
void arr_ptr_rearr(long long int ** a, long long int i1, long long int i2);
void arr_ptr_erase(long long int *** a, long long int i1, long long int i2);
long long int ** arr_ptr_substr(long long int ** a, long long int i1, long long int i2);
void arr_ptr_pob(long long int *** a);
void arr_ptr_pub(long long int *** a, long long int * n);
void arr_ptr_pof(long long int *** a);
void arr_ptr_puf(long long int *** a, long long int * n);
long long int ** arr_ptr_concat(long long int ** a, long long int ** b);
void arr_ptr_ins(long long int *** a, long long int * n, long long int i);
void arr_ptr_insArr(long long int *** a, long long int ** b, long long int i);
void arr_ptr_replace(long long int *** a, long long int * n, long long int i1, long long int i2);
void arr_ptr_replaceArr(long long int *** a, long long int ** b, long long int i1, long long int i2);
void arr_ptr_reverse(long long int ** a);

#include "array.ptr.c"
#endif