void setDate(Date * date, int day_t, int month_t, int year_t)
{
    date->day=day_t;
    date->month=month_t;
    date->year=year_t;
}

int getMonthDays(Date * date)
{
    switch(date->month){
        case 1:return 31;
        case 2:return (date->year%4==0?29:28);
        case 3:return 31;
        case 4:return 30;
        case 5:return 31;
        case 6:return 30;
        case 7:return 31;
        case 8:return 31;
        case 9:return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default:return 0;
    }
}

void solveDayCount(Date * date)
{
    date->dayCount=0;
    Date buff;
    setDate(&buff,0,0,date->year);
    date->dayCount+=(date->day-1);
    for(int i=1;i<date->month;i++){
        setDate(&buff,0,i,date->year);
        date->dayCount+=getMonthDays(&buff);
    }
    date->dayCount+=(date->year-1)*365+(date->year-1)/4;
    if(date->dayCount>=577735)date->dayCount-=+(date->year-1)/100-(date->year-1)/400-2;
}