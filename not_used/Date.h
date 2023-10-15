#ifndef DATE_STRUCT_H
#define DATE_STRUCT_H

typedef struct{
    int dayCount;
    int day;
    int month;
    int year;
}Date;

void setDate(Date * date, int day_t, int month_t, int year_t);
int getMonthDays(Date * date);
void solveDayCount(Date * date);

#include "Date.c"
#endif