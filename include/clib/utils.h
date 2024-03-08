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
#ifndef CLIB_UTILS_H
#define CLIB_UTILS_H

#include <inttypes.h>
#include <stdlib.h>

#include <clib/types.h>

clib_flag clib_mem_copy(void * dest, void * src, uint64_t size);
clib_flag clib_mem_IsEqual(void * dest, void * src, uint64_t size);

#endif