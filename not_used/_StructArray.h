#ifndef _STRUCT_ARRAY_H
#define _STRUCT_ARRAY_H

typedef struct
{
    long long int len;
    long long int * val;
}Array;

Array * _arr_init(long long int len);
void _arr_print(Array * a);
void _arr_del(Array * a);
long long int _arr_isEqual(Array * a, Array * b);
void _arr_swap(Array * a, long long int i1, long long int i2);
void _arr_rearr(Array * a, long long int i1, long long int i2);
void _arr_erase(Array * a, long long int i1, long long int i2);
Array * _arr_substr(Array * a, long long int i1, long long int i2);
long long int _arr_find(Array * a, long long int key, long long int entry);
long long int _arr_count(Array * a, long long int n);
long long int _arr_countArr(Array * a, Array * b);
void _arr_pob(Array * a);
void _arr_pub(Array ** a, long long int n);
void _arr_pof(Array * a);
void _arr_puf(Array ** a, long long int n);
Array * _arr_concat(Array * a, Array * b);
void _arr_ins(Array ** a, long long int n, long long int i);
void _arr_insArr(Array ** a, Array * b, long long int i);
void _arr_replace(Array ** a, long long int n, long long int i1, long long int i2);
void _arr_replaceArr(Array ** a, Array * b, long long int i1, long long int i2);

#include "_StructArray.c"
#endif