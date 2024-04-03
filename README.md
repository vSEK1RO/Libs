<img src="https://i.imgur.com/TGAzySV.png"></img>
`
CLib is a library of polymorphic data structures and functions for working with them, supporting work with generic types, using void pointers and macros for generating statically typed interfaces.
`

To download and build the library, run the following command in the console:
```
git clone https://github.com/vSEK1RO/clib
cd clib
make
```
To check tests run:
```
make test
```
To build and run any examples you should to change their makefile, specifying in the DEPSDIR variable the path where the libraries specified in DEPS are located:
```
make run
```
---

## Schedule

* [array.h:](https://github.com/vSEK1RO/clib/tree/main#Arrays) working with polymorphic dynamic arrays
* [string.h:](https://github.com/vSEK1RO/clib/tree/main#Strings) working with strings (c like with '\0' at the end of string)
* [numsys.h:](https://github.com/vSEK1RO/clib/tree/main#Number_systems) converting numbers to strings with a number system
* [utils.h:](https://github.com/vSEK1RO/clib/tree/main#Utils) functions for working with memory

---

## [Arrays](https://github.com/vSEK1RO/clib/blob/main/src/array.h)

When working with arrays, you can use two approaches: use `polymorphic` functions that are uniquely declared in `array.h` and use void pointers:
```c
#include <clib/array.h>
int main(){
    //equal to void* arr;
    clib_arr arr;
    clib_arr_init(&arr,5,sizeof(YourType));

    //you should remember to clean memory
    clib_arr_del(&arr);
}
```
Or generate using `macros` typed interfaces of the same functions that use `YourType`:
```c
#define ARR_TYPE YourType
#include <clib/array.h>
//ARR_TYPE macros will be undef
int main(){
    //equal to YourType* arr;
    clib_arr_YourType arr;
    
    //will call init
    //and fill array with elements
    clib_arr_cast_YourType(&a,5,(YourType[]){
        1,2,3,4,5
    });
    clib_arr_del_YourType(&a);
}
```
You can include `array.h` several times only if each of them has its own data type in `ARR_TYPE`.

If you use a `macro` implementation, then you can dereference by index as a constant array:
```c
clib_arr_int arr;
clib_arr_init_int(&arr,5);
for(uint64_t i=0;i<clib_arr_len_int(&arr);i++){
    scanf("%d",&arr[i]);
}
```
You can use typed arrays inside polymorphic functions, but often they need to be cast to `clib_arr*`:
```c
//needs to be casted because it is clib_arr_int
clib_arr_reverse((clib_arr*)&arr);
clib_arr brr;
//not necessary here, but casting is recommended
clib_arr_copy(&brr,(clib_arr)arr);
clib_arr_erase(&brr,2,4);
for(uint64_t i=0;i<clib_arr_len(&brr);i++){
    //needs to be casted because it is void*
    printf("%d ",((int*)brr)[i]);
}
printf("\n");
```
When performing operations on `polymorphic` arrays with different types, errors may occur. To track them, check the flags returned by the functions:
```c
clib_arr crr;
clib_flag flag = clib_arr_concat(&crr,(clib_arr*)&arr,&brr);
if(flag==CLIB_TYPE_INCORRECT){
    printf("error: type incorrect");
}else{
    for(uint64_t i=0;i<clib_arr_len(&crr);i++){
        printf("%d ",((int*)crr)[i]);
    }
    clib_arr_del(&crr);
}
```
Never forget to clear your memory:
```c
clib_arr_del(&brr);
clib_arr_del((clib_arr*)&arr);
```
In order to `expand the capabilities` of arrays, you can initialize it using `eInit` and store `eLen` bytes in `eGet`:
```c
#include <clib/array.h>
#include <stdio.h>

char * clib_arr_name(clib_arr * arr){
    return *(char**)clib_arr_eGet(arr,0);
}

int main(){
    clib_arr drr;
    clib_arr_eInit(&drr,0,sizeof(int),sizeof(char*));
    char * s = "arr_name";
    clib_mem_copy(
        clib_arr_eGet(&drr,0),
        &s,
        sizeof(char*)
    );
    printf("%s",clib_arr_name(&drr));
    clib_arr_del(&drr);
}
```

You can study the list of other functions available for arrays in the file [`clib/src/array.h`](https://github.com/vSEK1RO/clib/blob/main/src/array.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)

---

## [Strings](https://github.com/vSEK1RO/clib/blob/main/src/string.h)

The header file is included without additional macros. The string is an array of type char, but does not store its length. The end of a line is uniquely identified by adding a `'\0'` terminating null character. In the length value that we pass to the function `str_init(uint64_t len)` `'\0'` the character does not need to be taken into account:
```c
#include <clib/string.h>
#include <stdio.h>
int main(){
    char * string = str_init(len);
    //will create a char array of (len+1) elements, where (len+1)th is the '\0' character
}
```
if you want to create a string equal to a constant C string, then use the function `str_cast(const char * a)`:
```c
    string = str_cast("123abc");
    printf("%s", string);
    //will output the line 123abc
```
You can study the list of other functions available for strings in the file [`clib/src/string.h`](https://github.com/vSEK1RO/clib/blob/main/src/string.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)

---

## [Number_systems](https://github.com/vSEK1RO/clib/blob/main/src/numsys.h)

Using the functions `numsys_dtoc`, `numsys_ctod`, `numsys_ntos`, `numsys_ston`, you can convert digits to symbols, symbols to digits, numbers to strings, strings to numbers in a specific number system. Examples of use below:
```c
#include <lib/numsys.h>
#include <stdio.h>
int main(){
    printf("%c ", numsys_dtoc(10));
    printf("%ld ", numsys_ctod('F'));
    printf("%s ", numsys_ntos(4095, 16));
    printf("%ld", numsys_ston("-1010",2));
    //will output the line A 15 FFF -10
}
```
Floating point numbers are not supported.

You can study the list of other functions available for strings in the file [`clib/src/numsys.h`](https://github.com/vSEK1RO/clib/blob/main/src/numsys.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)

## [Utils](https://github.com/vSEK1RO/clib/blob/main/src/utils.h)

Using the functions `clib_mem_copy`, `clib_mem_isEqual` you can work with memory

You can study the list of other functions available for strings in the file [`clib/src/utils.h`](https://github.com/vSEK1RO/clib/blob/main/src/utils.h)

[:arrow_up:Shedule](https://github.com/vSEK1RO/clib/tree/main#schedule)