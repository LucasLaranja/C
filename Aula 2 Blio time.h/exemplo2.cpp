//acessar o n�mero de horas desde a zero hora de 1o de janeiro de 1970.

#include <stdio.h>
#include <time.h>

int main (){

time_t seg;

seg = time (NULL);
printf("O n�mero de horas desde 1o de janeiro de 1970 � %d\n", seg / 3600);

return 0;
}
