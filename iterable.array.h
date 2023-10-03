#ifndef ITERABLE_ARRAY_H
#define ITERABLE_ARRAY_H

long long int * arr_init(long long int len);
void arr_print(long long int * a);
void arr_del(long long int * a);
long long int arr_isEqual(long long int * a, long long int * b);
void arr_swap(long long int * a, long long int i1, long long int i2);
void arr_rearr(long long int * a, long long int i1, long long int i2);
void arr_erase(long long int ** a, long long int i1, long long int i2);
long long int * arr_substr(long long int * a, long long int i1, long long int i2);
long long int arr_find(long long int * a, long long int key, long long int entry);
long long int arr_count(long long int * a, long long int n);
long long int arr_countArr(long long int * a, long long int * b);
void arr_pob(long long int ** a);
void arr_pub(long long int ** a, long long int n);
void arr_pof(long long int ** a);
void arr_puf(long long int ** a, long long int n);
long long int * arr_concat(long long int * a, long long int * b);
void arr_ins(long long int ** a, long long int n, long long int i);
void arr_insArr(long long int ** a, long long int * b, long long int i);
void arr_replace(long long int ** a, long long int n, long long int i1, long long int i2);
void arr_replaceArr(long long int ** a, long long int * b, long long int i1, long long int i2);
void arr_reverse(long long int *a);

#include "iterable.array.c"
#endif