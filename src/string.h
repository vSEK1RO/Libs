#ifndef ITERABLE_STRING_H
#define ITERABLE_STRING_H

#include <inttypes.h>
#include <stdlib.h>

char * str_init(uint64_t len);
char * str_cast(const char * a);
uint64_t str_len(char * a);
void str_del(char * a);
void str_copy(char ** a, char * b);
uint8_t str_isEqual(char * a, char * b);
void str_swap(char * a, uint64_t i1, uint64_t i2);
void str_rearr(char * a, uint64_t i1, uint64_t i2);
void str_erase(char ** a, uint64_t i1, uint64_t i2);
char * str_substr(char * a, uint64_t i1, uint64_t i2);
uint64_t str_find(char * a, char key, uint64_t entry);
uint64_t str_findStr(char * a, char * b, uint64_t entry);
uint64_t str_count(char * a, char n);
uint64_t str_countStr(char * a, char * b);
void str_pob(char ** a);
void str_pub(char ** a, char n);
void str_pof(char ** a);
void str_puf(char ** a, char n);
char * str_concat(char * a, char * b);
void str_ins(char ** a, char n, uint64_t i);
void str_insStr(char ** a, char * b, uint64_t i);
void str_repl(char ** a, char n, uint64_t i1, uint64_t i2);
void str_replStr(char ** a, char * b, uint64_t i1, uint64_t i2);
void str_reverse(char * a);

#endif