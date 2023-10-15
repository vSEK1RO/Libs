#ifndef _ITERABLE_MATRIX_H
#define _ITERABLE_MATRIX_H

long long int ** mtrx_init(long long int height, long long int width);
long long int mtrx_width(long long int ** a);
long long int mtrx_height(long long int ** a);
void mtrx_print(long long int ** a);
void mtrx_del(long long int ** a);
long long int mtrx_isEqual(long long int ** a, long long int ** b);
long long int ** mtrx_substr(long long int ** a, long long int x1, long long int y1, long long int x2, long long int y2);
void mtrx_replace(long long int ** a, long long int ** b, long long int x, long long int y);
void mtrx_rotateCW(long long int *** a);
void mtrx_rotateACW(long long int *** a);
void mtrx_reverseVer(long long int ** a);
void mtrx_reverseHor(long long int ** a);
void mtrx_swapCol(long long int ** a, long long int x1, long long int x2);
void mtrx_swapRow(long long int ** a, long long int y1, long long int y2);
void mtrx_insCol(long long int *** a, long long int * b, long long int x);
void mtrx_insRow(long long int *** a, long long int * b, long long int y);
void mtrx_delCol(long long int *** a, long long int * b, long long int x);
void mtrx_delRow(long long int *** a, long long int * b, long long int y);
void mtrx_rearrCol(long long int *** a, long long int * b, long long int x);
void mtrx_rearrRow(long long int *** a, long long int * b, long long int y);

#include "_matrix.c"
#endif