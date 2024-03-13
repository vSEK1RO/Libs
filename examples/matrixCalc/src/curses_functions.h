#ifndef CURSES_FUNCTIONS_H
#define CURSES_FUNCTIONS_H

#include <PDCurses/curses.h>
#include <clib/array.h>
#include <clib/string.h>
#include "field_int.h"
#include "field_float.h"

#define menu_win(name)\
    init_win(name,stdscr,getmaxy(stdscr)-12,40,12,43,COLOR_PAIR(COLOR_BLUE_BG));

clib_flag menu_exit(
    __attribute__((unused)) clib_arr * vars
){
    return CLIB_FALSE;
}
clib_flag menu_type_int(clib_arr * vars)
{
    mtrx_field_int_init((mtrx_field*)*vars);
    return CLIB_FALSE;
}
clib_flag menu_type_float(clib_arr * vars)
{
    mtrx_field_int_init((mtrx_field*)*vars);
    return CLIB_FALSE;
}
clib_flag menu_scan(clib_arr * vars)
{
    //mtrx type
    clib_arr_pchar type_strs;
    clib_arr_cast_pchar(&type_strs,2,(pchar[]){
        "Int",
        "Float"
    });
    
    clib_arr_pfn type_fns;
    clib_arr_cast_pfn(&type_fns,2,(pfn[]){
        menu_type_int,
        menu_type_float
    });

    clib_arr type_vars;
    clib_arr_init(&type_vars,1,sizeof(mtrx_field));

    WINDOW * type_menu = init_menu(
        "Choose matrix's type:",
        &type_strs,
        &type_fns,
        &type_vars,
        stdscr,
        COLOR_CYAN_BG,
        "-> ",
        43
    );

    mtrx_field field;
    clib_mem_copy(&field,((mtrx_field*)type_vars),sizeof(mtrx_field));

    clib_arr_del(&type_vars);
    clib_arr_del_pfn(&type_fns);
    clib_arr_del_pchar(&type_strs);

    wclear(type_menu);
    wrefresh(type_menu);
    delwin(type_menu);

    //mtrx hw
    WINDOW * win;
    win = menu_win("Scan menu");
    
    wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(win,2,4,"Enter matrix's height:");
    wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
    wrefresh(win);

    uint64_t h,w;
    echo();
    curs_set(1);
    mvwscanw(win,4,4,"%lu",&h);
    wclear(win);
    wrefresh(win);
    delwin(win);

    win = menu_win("Scan menu");
    
    wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(win,2,4,"Enter matrix's width:");
    wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
    wrefresh(win);
    
    mvwscanw(win,4,4,"%lu",&w);
    wclear(win);
    wrefresh(win);
    delwin(win);

    //mtrx init
    win = menu_win("Scan menu");
    mtrx m;
    mtrx_eInit(&m,h,w,field.size,sizeof(pchar),&field);
    clib_arr_pub(vars,&m);

    wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(win,2,4,"Enter matrix's name:");
    wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
    wrefresh(win);

    char * s = str_init(256);
    clib_mem_copy(mtrx_eGet(&m,0),&s,sizeof(char**));
    mvwscanw(win,4,4,"%s",s);
    wclear(win);
    wrefresh(win);
    delwin(win);

    //mtrx elements
    win = menu_win("Scan menu");
    wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(win,2,4,"Enter matrix's elements:");
    wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
    wrefresh(win);
    for(uint64_t i=0;i<mtrx_height(&m);i++){
        for(uint64_t j=0;j<mtrx_width(&m);j++){
            wmove(win,4+i,4+j*4);
            wscanw(win,field.type,mtrx_get(&m,i,j));
        }
    }
    noecho();
    curs_set(0);
    
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}

#endif