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
#ifndef NUMSYS_H
#define NUMSYS_H

#include <math.h>
#include <inttypes.h>

#include <clib/string.h>

char numsys_dtoc(int64_t digit);
int64_t numsys_ctod(char digit);
char * numsys_ntos(int64_t num, uint8_t base);
int64_t numsys_ston(char * str, uint8_t base);

#endif