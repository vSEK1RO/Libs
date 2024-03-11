#ifndef CURSES_FUNCTIONS_H
#define CURSES_FUNCTIONS_H

#include <PDCurses/curses.h>
#include <clib/array.h>

void menu_scan(clib_arr * vars){
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
        vars,
        stdscr,
        COLOR_CYAN_BG,
        "-> ",
        43
    );

    wclear(menu);
    wrefresh(menu);
    delwin(menu);
}

#endif