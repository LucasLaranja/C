#include <time.h>
#include <stdio.h>

int main(void){

struct tm str_time;
time_t hora_do_dia;
str_time.tm_year = 2019-1900;
str_time.tm_mon = 7;
str_time.tm_mday = 24;
str_time.tm_hour = 10;
str_time.tm_min = 3;
str_time.tm_sec = 5;
str_time.tm_isdst = 0;
hora_do_dia = mktime(&str_time);
printf(ctime(&hora_do_dia));
return 0;
}
