#include <PDCurses/curses.h>
typedef char * pchar;
#define ARR_TYPE pchar
#include <clib/array.h>
typedef void (*pfn)(WINDOW * win);
#define ARR_TYPE pfn
#include <clib/array.h>
#include "curses_menu.h"
#include "curses_colors.h"

int main()
{
    init_stdscr();
    WINDOW * title = init_title(stdscr);

    clib_arr_pchar strs;
    clib_arr_cast_pchar(&strs,6,(pchar[]){
        "Scan matrix",
        "Print matrix",
        "Add matrixies",
        "Mut matrixies",
        "Transpose matrix",
        "Exit"
    });

    clib_arr_pfn fns;
    clib_arr_cast_pfn(&fns,6,(pfn[]){

    });

    WINDOW * menu = init_menu(
        "Chose action:",
        &strs,
        &fns,
        stdscr,
        COLOR_CYAN_BG,
        "-> ",
        3
    );

    delwin(title);
    delwin(menu);
    endwin();
    return 0;
}