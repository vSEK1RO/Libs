#ifndef STRUCT_ARRAY_H
#define STRUCT_ARRAY_H

typedef struct
{
    long long int len;
    long long int * val;
}Array;

Array * arr_init(long long int len);
void arr_print(Array * a);
void arr_del(Array * a);
long long int arr_isEqual(Array * a, Array * b);
void arr_swap(Array * a, long long int i1, long long int i2);
void arr_rearr(Array * a, long long int i1, long long int i2);
void arr_erase(Array * a, long long int i1, long long int i2);
Array * arr_substr(Array * a, long long int i1, long long int i2);
long long int arr_find(Array * a, long long int key, long long int entry);
long long int arr_count(Array * a, long long int n);
long long int arr_countArr(Array * a, Array * b);
void arr_pob(Array * a);
void arr_pub(Array ** a, long long int n);
void arr_pof(Array * a);
void arr_puf(Array ** a, long long int n);
Array * arr_concat(Array * a, Array * b);
void arr_ins(Array ** a, long long int n, long long int i);
void arr_insArr(Array ** a, Array * b, long long int i);
void arr_replace(Array ** a, long long int n, long long int i1, long long int i2);
void arr_replaceArr(Array ** a, Array * b, long long int i1, long long int i2);

#include "StructArray.c"
#endif