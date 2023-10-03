#ifndef ITERABLE_STRING_H
#define ITERABLE_STRING_H

char * str_init(long long int len);
char * str_cast(const char * a);
long long int str_len(char * a);
void str_print(char * a);
void str_del(char * a);
long long int str_isEqual(char * a, char * b);
void str_swap(char * a, long long int i1, long long int i2);
void str_rearr(char * a, long long int i1, long long int i2);
void str_erase(char ** a, long long int i1, long long int i2);
char * str_substr(char * a, long long int i1, long long int i2);
long long int str_find(char * a, char key, long long int entry);
long long int str_count(char * a, char n);
long long int str_countArr(char * a, char * b);
void str_pob(char ** a);
void str_pub(char ** a, char n);
void str_pof(char ** a);
void str_puf(char ** a, char n);
char * str_concat(char * a, char * b);
void str_ins(char ** a, char n, long long int i);
void str_insArr(char ** a, char * b, long long int i);
void str_replace(char ** a, char n, long long int i1, long long int i2);
void str_replaceArr(char ** a, char * b, long long int i1, long long int i2);
void str_reverse(char *a);

#include "iterable.string.c"
#endif