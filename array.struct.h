#ifndef ARRAY_STRUCT_H
#define ARRAY_STRUCT_H

auto * arr_init(long long int len);
void arr_print(auto * a);
void arr_del(auto * a);
auto arr_isEqual(auto * a, auto * b);
void arr_swap(auto * a, auto i1, auto i2);
void arr_rearr(auto * a, auto i1, auto i2);
void arr_erase(auto * a, auto i1, auto i2);
auto * arr_substr(auto * a, auto i1, auto i2);
auto arr_find(auto * a, auto key, auto entry);
auto arr_count(auto * a, auto n);
auto arr_countArr(auto * a, auto * b);
void arr_pob(auto * a);
void arr_pub(auto ** a, auto n);
void arr_pof(auto * a);
void arr_puf(auto ** a, auto n);
auto * arr_concat(auto * a, auto * b);
void arr_ins(auto ** a, auto n, auto i);
void arr_insArr(auto ** a, auto * b, auto i);
void arr_replace(auto ** a, auto n, auto i1, auto i2);
void arr_replaceArr(auto ** a, auto * b, auto i1, auto i2);

#include "array.struct.c"
#endif