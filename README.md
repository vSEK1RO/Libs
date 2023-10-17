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
You can study the list of other functions available for arrays in the file [`src/array.h`](https://github.com/vSEK1RO/clib/blob/main/src/array.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)
## Strings
[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)
