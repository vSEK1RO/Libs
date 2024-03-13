#ifndef CURSES_MENU_H
#define CURSES_MENU_H

#include <PDCurses/curses.h>
#include <clib/string.h>
#include <clib/array.h>
#include "curses_colors.h"

void init_stdscr()
{
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}
WINDOW * init_win(char * title, WINDOW * p, int h, int w, int y, int x, chtype color)
{
    init_colors();
    WINDOW * win = subwin(p,h,w,y,x);
    box(win,ACS_VLINE|color,ACS_HLINE|color);
    wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(win,0,(w-str_len(title))/2,title);
    wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
    wrefresh(p);
    wrefresh(win);
    return win;
}
WINDOW * init_title(WINDOW * p)
{
    WINDOW * title = init_win("Title",p,10,80,1,3,COLOR_PAIR(COLOR_BLACK_BG));
    mvwprintw(title,2,2,"                                _      _       __   _        _              ");
    mvwprintw(title,3,2,"        _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___         ");
    mvwprintw(title,4,2,"       | '_ ` _ \\  / _ \\| '_ \\ | '_ \\ | |    / /   | | / __|| |/ __|        ");
    mvwprintw(title,5,2,"       | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\\__ \\        ");
    mvwprintw(title,6,2,"       |_| |_| |_| \\___|| .__/ |_| |_||_|  /_/     |_| \\___||_||___/        ");
    mvwprintw(title,7,2,"                        |_|                                                 ");
    wrefresh(title);
    return title;
}
void print_menu(clib_arr_pchar * a, WINDOW * win, chtype color, char * pick, uint64_t iter)
{
    for(uint64_t i=0;i<clib_arr_len_pchar(a);i++){
        if(i!=iter){
            char * space = str_init(0);
            for(uint64_t j=0;j<str_len(pick);j++){
                str_pub(&space,' ');
            }
            char * buff = str_concat(space,(*a)[i]);
            mvwprintw(win,4+i,4,buff);
            str_del(buff);
            str_del(space);
        }else{
            wattron(win,COLOR_PAIR(color));
            char * buff = str_concat(pick,(*a)[i]);
            mvwprintw(win,4+i,4,buff);
            str_del(buff);
            wattroff(win,COLOR_PAIR(color));
        }
    }
}
WINDOW * init_menu(
    char * title,
    clib_arr_pchar * strs,
    clib_arr_pfn * fns,
    clib_arr * vars,
    WINDOW * p,
    chtype color,
    char * pick,
    int x   
){
    WINDOW * menu = init_win(
        "Menu",
        p,
        getmaxy(p)-12,
        40,
        12,
        x,
        COLOR_PAIR(COLOR_BLUE_BG)
    );
    wattron(menu,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(menu,2,4,title);
    wattroff(menu,COLOR_PAIR(COLOR_WHITE_BG));
    chtype input;
    int64_t iter=0;
    int64_t iterl=(int64_t)clib_arr_len_pchar(strs);
    print_menu(strs,menu,color,pick,iter);
    wrefresh(menu);
    while((input=wgetch(menu))){
        switch(input){
            case KEY_UP:
                iter--;
                if(iter<0){
                    iter=iterl-1;
                }
                break;
            case KEY_DOWN:
                iter++;
                if(iter>=iterl){
                    iter=0;
                }
                break;
            case 10:
                print_menu(strs,menu,COLOR_WHITE_FG,pick,iter);
                box(menu,ACS_VLINE|COLOR_PAIR(COLOR_WHITE_FG),ACS_HLINE|COLOR_PAIR(COLOR_WHITE_FG));
                wrefresh(menu);
                if((*fns)[iter](vars)!=CLIB_TRUE){
                    return menu;
                }
                box(menu,ACS_VLINE|COLOR_PAIR(COLOR_BLUE_BG),ACS_HLINE|COLOR_PAIR(COLOR_BLUE_BG));
                wattron(menu,COLOR_PAIR(COLOR_WHITE_BG));
                mvwprintw(menu,0,(40-str_len("Menu"))/2,"Menu");
                wattroff(menu,COLOR_PAIR(COLOR_WHITE_BG));
                break;
        }
        print_menu(strs,menu,color,pick,iter);
        wrefresh(menu);
    }
    return menu;
}

#endif