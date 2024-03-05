/************************** Tue Mar 05 22:39:34 2024 **************************/
/*                                _      _       __   _        _              */
/*        _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___         */
/*       | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __|        */
/*       | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \        */
/*       |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/        */
/*                        |_|                                                 */
/*                                                                            */
/*                    Created by Vlad Litvinov b23-534                        */
/*                       https://github.com/vSEK1RO                           */
/*                                                                            */
/******************************************************************************/
#ifndef CLIB_TYPES_H
#define CLIB_TYPES_H

#include <inttypes.h>

/*********************************** GENERAL **********************************/

typedef void * clib_item;
typedef void * clib_arr;
typedef void * clib_str;

/************************************ FLAG ************************************/

typedef enum{
    //general
    CLIB_FALSE = 0,
    CLIB_TRUE = 1,
    CLIB_SUCCESS,
    CLIB_UNNAMED,
    CLIB_TYPE_INCORRECT,
    CLIB_TEST_FAILED,
    CLIB_NULL,
    //array
    CLIB_ARR_INDEX,
    CLIB_ARR_MEMORY,
    CLIB_ARR_NULL,
    //string
    
} clib_flag;

#endif