//Alterar o valor do fuso horário para a hora de Brasília
#include <stdio.h>
#include <time.h>

#define BRA (-3)

int main ()
{

time_t Tempo;
struct tm *ptr_ts;
time ( &Tempo );

ptr_ts = gmtime ( &Tempo );
printf ("Hora de Brasilia: %2d:%02d\n",

ptr_ts->tm_hour+BRA, ptr_ts->tm_min);
return 0;

}
