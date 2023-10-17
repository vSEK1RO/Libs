<img src="https://i.imgur.com/TGAzySV.png"></img>
`
CLib is a library of standard data structures and functions for working with them, supporting work with generic types, which I wrote to practice my C coding skills.
`

To download the library, run the following command in the console:
```
git clone https://github.com/vSEK1RO/clib
```

## Schedule

* [array.h:](https://github.com/vSEK1RO/clib/tree/main#Arrays) working with arrays
* [ptrarr.h:](https://github.com/vSEK1RO/clib/tree/main#Pointer_arrays) working with pointer arrays
* [string.h:](https://github.com/vSEK1RO/clib/tree/main#Strings) working with strings (c like with '\0' at the end of string)

## [Arrays](https://github.com/vSEK1RO/clib/blob/main/src/array.h)

The following syntax is used to work with arrays:
```c
#define ARR_TYPE YourType
#include "clib/src/array.h"
```
Where instead of `YourType` you should write the data type that should be stored in the array. 
If you do not create a macro, then by default an array with `int` will be created. You can connect `array.h` several times only if each of them has its own data type in `ARR_TYPE`.

An array is a pointer to the data type that you specified in ARR_TYPE; the syntax used for declaration is:
```c
YourType * array = arr_init_YourType(len);
```
The length in the array has a `uint64_t` data type and is stored in the -1 pointer counting from the beginning of the array. Since the array can contain different data types other than `uint64_t`, it is necessary to shift to `uint64_t`, and not to the `ARR_TYPE` data type pointer:
```c
uint64_t arrayLen;
arrayLen = ((uint64_t *)array)[-1];
//to avoid writing such a long expression, use the function
arrayLen = arr_len_YourType(a);
```
To free up memory use the following function:
```c
arr_del_YourType(array);
```

You can study the list of other functions available for arrays in the file [`clib/src/array.h`](https://github.com/vSEK1RO/clib/blob/main/src/array.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)

## [Pointer_arrays](https://github.com/vSEK1RO/clib/blob/main/src/ptrarr.h)

Including the header file is identical to `array.h`, only instead of the `ARR_TYPE` macro you must create the `PTRARR_TYPE` macro:
```c
#define PTRARR_TYPE YourType
#include "clib/src/ptrarr.h"
int main(){
  YourType ** ptrarr = ptrarr_init_YourType(len);
}
```
The functions are the same as for arrays, but you cannot use `count, countArr, find, findArr` and search `min, max`.

Using an array of pointers and regular array, you can create and use two-dimensional arrays. Here's an example code that creates a two-dimensional array filled from 0 to 99:
```c
#include <stdio.h>
#define PTRARR_TYPE int
#include "clib/src/ptrarr.h"
#define ARR_TYPE int
#include "clib/src/array.h"
int main(){
  int ** a = ptrarr_init_int(10);
  for(int i=0;i<ptrarr_len_int(a);i++){
    a[i] = arr_init_int(10);
    printf("\n");
    for(int j=0;j<arr_len_int(a[i]);j++){
      a[i][j] = (i*10+j);
      printf("%d ", a[i][j]);
    }
  }
}
```
You can study the list of other functions available for pointer arrays in the file [`clib/src/ptrarr.h`](https://github.com/vSEK1RO/clib/blob/main/src/ptrarr.h)

## [Strings](https://github.com/vSEK1RO/clib/blob/main/src/string.h)

The header file is included without additional macros. The string is an array of type char, but does not store its length. The end of a line is uniquely identified by adding a `'\0'` terminating null character. In the length value that we pass to the function `str_init(uint64_t len)` `'\0'` the character does not need to be taken into account:
```c
#include "clib/src/string.h"
int main(){
  char * string = str_init(len);
  //will create a char array of (len+1) elements, where (len+1)th is the '\0' character
  ...
}
```
if you want to create a string equal to a constant C string, then use the function `str_cast(const char * a)`:
```c
  ...
  string = str_cast("123abc");
  printf("%s", string);
  //will output the line 123abc
```
You can study the list of other functions available for strings in the file [`clib/src/string.h`](https://github.com/vSEK1RO/clib/blob/main/src/string.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)
