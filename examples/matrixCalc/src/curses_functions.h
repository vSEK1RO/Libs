#ifndef CURSES_FUNCTIONS_H
#define CURSES_FUNCTIONS_H

#include <curses.h>
#include <clib/array.h>
#include <clib/string.h>
#include <clib/utils.h>

#include "field_int.h"
#include "field_double.h"

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
clib_flag menu_type_double(clib_arr * vars)
{
    mtrx_field_double_init((mtrx_field*)*vars);
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
        menu_type_double
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

    mtrx_field * field=malloc(sizeof(mtrx_field));
    clib_mem_copy(field,((mtrx_field*)type_vars),sizeof(mtrx_field));
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

    uint64_t h=0,w=0;
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
    if(w==0 || h==0){
        noecho();
        curs_set(0);
        return CLIB_TRUE;
    }
    win = menu_win("Scan menu");
    mtrx m;
    mtrx_eInit(&m,h,w,field->size,sizeof(pchar),field);
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
            move(16+i,47+j*5);
            mtrx_fGet(&m)->scan(mtrx_get(&m,i,j));
        }
    }
    noecho();
    curs_set(0);
    
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
int64_t menu_choose(clib_arr * vars)
{
    if(clib_arr_len(vars)==0)return -1;
    WINDOW * menu = init_win(
        "Menu",
        stdscr,
        getmaxy(stdscr)-12,
        40,
        12,
        43,
        COLOR_PAIR(COLOR_BLUE_BG)
    );
    clib_arr_pchar strs;
    clib_arr_init_pchar(&strs,clib_arr_len(vars));
    for(uint64_t i=0;i<clib_arr_len(vars);i++){
        clib_mem_copy(strs+i,mtrx_eGet((mtrx*)clib_arr_get(vars,i),0),sizeof(pchar));   
    }
    wattron(menu,COLOR_PAIR(COLOR_WHITE_BG));
    mvwprintw(menu,2,4,"Choose matrix:");
    wattroff(menu,COLOR_PAIR(COLOR_WHITE_BG));
    chtype input;
    int64_t iter=0;
    int64_t iterl=(int64_t)clib_arr_len_pchar(&strs);
    print_menu(&strs,menu,COLOR_CYAN_BG,"-> ",iter);
    wrefresh(menu);
    while((input=wgetch(menu))){
        switch(input){
            case 'w':
                iter--;
                if(iter<0){
                    iter=iterl-1;
                }
                break;
            case 's':
                iter++;
                if(iter>=iterl){
                    iter=0;
                }
                break;
            case 10:
                goto end;
        }
        print_menu(&strs,menu,COLOR_CYAN_BG,"-> ",iter);
        wrefresh(menu);
    }
    end:
    wclear(menu);
    wrefresh(menu);
    delwin(menu);
    clib_arr_del_pchar(&strs);
    return iter;
}
clib_flag menu_print(clib_arr * vars)
{
    int64_t id = menu_choose(vars);
    WINDOW * win = menu_win("Print menu");
    if(id==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx m = *(mtrx*)clib_arr_get(vars,id);
        mtrx_field field = *mtrx_fGet(&m);
        mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m,0));
        for(uint64_t i=0;i<mtrx_height(&m);i++){
            for(uint64_t j=0;j<mtrx_width(&m);j++){
                move(16+i,47+j*5);
                field.print(mtrx_get(&m,i,j));
            }
        }
        wrefresh(win);
        getch();
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_del(clib_arr * vars)
{
    int64_t id = menu_choose(vars);
    WINDOW * win = menu_win("Del menu");
    if(id==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx * m = (mtrx*)clib_arr_get(vars,id);
        mtrx_field * field = mtrx_fGet(m);
        char * s = *(char**)mtrx_eGet(m,0);
        free(field);
        free(s);
        mtrx_del(m);
        clib_arr_erase(vars,id,id+1);
        mvwprintw(win,2,4,"Matrix was deleted!");
        wrefresh(win);
        getch();
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_add(clib_arr * vars){
    int64_t id1 = menu_choose(vars);
    char ** str1;
    if(id1!=-1){
        str1 = mtrx_eGet(clib_arr_get(vars,id1),0);
        str_insStr(str1,"(*) ",0);
    }
    int64_t id2 = menu_choose(vars);
    if(id1!=-1){
        str_erase(str1,0,4);
    }
    WINDOW * win = menu_win("Add menu");
    if(id1==-1 || id2==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx m1 = *(mtrx*)clib_arr_get(vars,id1);
        mtrx m2 = *(mtrx*)clib_arr_get(vars,id2);
        mtrx m;
        clib_flag flag = mtrx_add(&m,&m1,&m2);
        if(flag!=CLIB_SUCCESS){
            mvwprintw(win,2,4,"Incorrect types!");
            wrefresh(win);
            getch();
        }else{
            clib_arr_pub(vars,&m);
            char * s = str_cast("_add_");
            str_insStr(&s,*(char**)mtrx_eGet(&m1,0),0);
            str_insStr(&s,*(char**)mtrx_eGet(&m2,0),str_len(s));
            clib_mem_copy(mtrx_eGet(&m,0),&s,sizeof(char*));
            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m,0));
            mtrx_field field = *mtrx_fGet(&m);
            for(uint64_t i=0;i<mtrx_height(&m);i++){
                for(uint64_t j=0;j<mtrx_width(&m);j++){
                    move(16+i,47+j*5);
                    field.print(mtrx_get(&m,i,j));
                }
            }
            wrefresh(win);
            getch();
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_mut(clib_arr * vars){
    int64_t id1 = menu_choose(vars);
    char ** str1;
    if(id1!=-1){
        str1 = mtrx_eGet(clib_arr_get(vars,id1),0);
        str_insStr(str1,"(*) ",0);
    }
    int64_t id2 = menu_choose(vars);
    if(id1!=-1){
        str_erase(str1,0,4);
    }
    WINDOW * win = menu_win("Mut menu");
    if(id1==-1 || id2==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx m1 = *(mtrx*)clib_arr_get(vars,id1);
        mtrx m2 = *(mtrx*)clib_arr_get(vars,id2);
        mtrx m;
        clib_flag flag = mtrx_mut(&m,&m1,&m2);
        if(flag!=CLIB_SUCCESS){
            mvwprintw(win,2,4,"Incorrect types!");
            wrefresh(win);
            getch();
        }else{
            clib_arr_pub(vars,&m);
            char * s = str_cast("_mut_");
            str_insStr(&s,*(char**)mtrx_eGet(&m1,0),0);
            str_insStr(&s,*(char**)mtrx_eGet(&m2,0),str_len(s));
            clib_mem_copy(mtrx_eGet(&m,0),&s,sizeof(char*));
            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m,0));
            mtrx_field field = *mtrx_fGet(&m);
            for(uint64_t i=0;i<mtrx_height(&m);i++){
                for(uint64_t j=0;j<mtrx_width(&m);j++){
                    move(16+i,47+j*5);
                    field.print(mtrx_get(&m,i,j));
                }
            }
            wrefresh(win);
            getch();
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_transp(clib_arr * vars){
    int64_t id1 = menu_choose(vars);
    WINDOW * win = menu_win("Transp menu");
    if(id1==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx m1 = *(mtrx*)clib_arr_get(vars,id1);
        mtrx m;
        clib_flag flag = mtrx_transp(&m,&m1);
        if(flag!=CLIB_SUCCESS){
            mvwprintw(win,2,4,"Incorrect types!");
            wrefresh(win);
            getch();
        }else{
            clib_arr_pub(vars,&m);
            char * s = str_cast("_transp");
            str_insStr(&s,*(char**)mtrx_eGet(&m1,0),0);
            clib_mem_copy(mtrx_eGet(&m,0),&s,sizeof(char*));
            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m,0));
            mtrx_field field = *mtrx_fGet(&m);
            for(uint64_t i=0;i<mtrx_height(&m);i++){
                for(uint64_t j=0;j<mtrx_width(&m);j++){
                    move(16+i,47+j*5);
                    field.print(mtrx_get(&m,i,j));
                }
            }
            wrefresh(win);
            getch();
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_split(clib_arr * vars){
    int64_t id = menu_choose(vars);
    WINDOW * win = menu_win("Split menu");
    if(id==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        echo();
        curs_set(1);
        wattron(win,COLOR_PAIR(COLOR_WHITE_BG));
        mvwprintw(win,2,4,"Enter column to split:");
        wattroff(win,COLOR_PAIR(COLOR_WHITE_BG));
        wrefresh(win);
        uint64_t column;
        mvwscanw(win,4,4,"%lu",&column);
        wclear(win);
        wrefresh(win);
        echo();
        curs_set(0);
        delwin(win);

        win = menu_win("Split menu");

        mtrx m = *(mtrx*)clib_arr_get(vars,id);
        mtrx m1, m2;
        clib_flag flag = mtrx_splitByColumn(&m1,&m2,&m,column);
        if(flag!=CLIB_SUCCESS){
            mvwprintw(win,2,4,"Incorrect types!");
            wrefresh(win);
            getch();
        }else{
            clib_arr_pub(vars,&m1);
            char * s1 = str_cast("_split_1");
            str_insStr(&s1,*(char**)mtrx_eGet(&m,0),0);
            clib_mem_copy(mtrx_eGet(&m1,0),&s1,sizeof(char*));

            clib_arr_pub(vars,&m2);
            char * s2 = str_cast("_split_2");
            str_insStr(&s2,*(char**)mtrx_eGet(&m,0),0);
            clib_mem_copy(mtrx_eGet(&m2,0),&s2,sizeof(char*));

            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m1,0));
            mtrx_field field1 = *mtrx_fGet(&m1);
            for(uint64_t i=0;i<mtrx_height(&m1);i++){
                for(uint64_t j=0;j<mtrx_width(&m1);j++){
                    move(16+i,47+j*5);
                    field1.print(mtrx_get(&m1,i,j));
                }
            }
            wrefresh(win);
            getch();

            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m2,0));
            mtrx_field field2 = *mtrx_fGet(&m2);
            for(uint64_t i=0;i<mtrx_height(&m2);i++){
                for(uint64_t j=0;j<mtrx_width(&m2);j++){
                    move(16+i,47+j*5);
                    field2.print(mtrx_get(&m2,i,j));
                }
            }
            wrefresh(win);
            getch();
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}
clib_flag menu_concat(clib_arr * vars){
    int64_t id1 = menu_choose(vars);
    char ** str1;
    if(id1!=-1){
        str1 = mtrx_eGet(clib_arr_get(vars,id1),0);
        str_insStr(str1,"(*) ",0);
    }
    int64_t id2 = menu_choose(vars);
    if(id1!=-1){
        str_erase(str1,0,4);
    }
    WINDOW * win = menu_win("Concat menu");
    if(id1==-1 || id2==-1){
        mvwprintw(win,2,4,"No matrixies!");
        wrefresh(win);
        getch();
    }else{
        mtrx m1 = *(mtrx*)clib_arr_get(vars,id1);
        mtrx m2 = *(mtrx*)clib_arr_get(vars,id2);
        mtrx m;
        clib_flag flag = mtrx_concat(&m,&m1,&m2);
        if(flag!=CLIB_SUCCESS){
            mvwprintw(win,2,4,"Incorrect types!");
            wrefresh(win);
            getch();
        }else{
            clib_arr_pub(vars,&m);
            char * s = str_cast("_concat_");
            str_insStr(&s,*(char**)mtrx_eGet(&m1,0),0);
            str_insStr(&s,*(char**)mtrx_eGet(&m2,0),str_len(s));
            clib_mem_copy(mtrx_eGet(&m,0),&s,sizeof(char*));
            mvwprintw(win,2,4,"%s:",*(char**)mtrx_eGet(&m,0));
            mtrx_field field = *mtrx_fGet(&m);
            for(uint64_t i=0;i<mtrx_height(&m);i++){
                for(uint64_t j=0;j<mtrx_width(&m);j++){
                    move(16+i,47+j*5);
                    field.print(mtrx_get(&m,i,j));
                }
            }
            wrefresh(win);
            getch();
        }
    }
    wclear(win);
    wrefresh(win);
    delwin(win);
    return CLIB_TRUE;
}



#endif