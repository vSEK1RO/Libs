/************************** Tue Mar 12 19:45:59 2024 **************************/
//#include "include/clib/title.h"
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
//#endclude "include/clib/title.h"
/********************************** INCLUDES **********************************/

#include <PDCurses/curses.h>
typedef char * pchar;
#define ARR_TYPE pchar
#include <clib/array.h>
typedef clib_flag (*pfn)(clib_arr * vars);
#define ARR_TYPE pfn
#include <clib/array.h>
#include "curses_menu.h"
#include "curses_colors.h"
#include "curses_functions.h"
#include "matrix.h"

/********************************* CODE START *********************************/

int main()
{
    init_stdscr();
    WINDOW * title = init_title(stdscr);

    clib_arr_pchar strs;
    clib_arr_cast_pchar(&strs,9,(pchar[]){
        "Scan matrix",
        "Print matrix",
        "Del matrix",
        "Add matrixies",
        "Mut matrixies",
        "Transpose matrix",
        "Split matrix",
        "Concat matrixies",
        "Exit"
    });

    clib_arr_pfn fns;
    clib_arr_cast_pfn(&fns,9,(pfn[]){
        menu_scan,
        menu_print,
        menu_del,
        menu_add,
        menu_mut,
        menu_transp,
        menu_split,
        menu_concat,
        menu_exit
    });

    clib_arr vars;
    clib_arr_init(&vars,0,sizeof(mtrx));

    WINDOW * menu = init_menu(
        "Choose action:",
        &strs,
        &fns,
        &vars,
        stdscr,
        COLOR_CYAN_BG,
        "-> ",
        3
    );

    clib_arr_del((clib_arr*)&strs);
    clib_arr_del((clib_arr*)&fns);
    for(uint64_t i=0;i<clib_arr_len(&vars);i++){
        mtrx * m = (mtrx*)clib_arr_get(&vars,i);
        mtrx_field * field = mtrx_fGet(m);
        free(field);
        mtrx_del(m);
    }
    clib_arr_del(&vars);
    delwin(title);
    delwin(menu);
    endwin();
    return 0;
}

/********************************** CODE END **********************************/