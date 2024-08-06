//exemplo de uso das fun��es time(), asctime() e localtime()
#include <stdio.h>
#include <time.h>
#define LEN 150
int main () {
	
char buf[LEN];
time_t curtime;
struct tm *loc_time;
//obt�m hora corrente do sistema
curtime = time (NULL);
//converte para a hora local
loc_time = localtime (&curtime);
//mostra hora e data no formato-padr�o
printf("%s", asctime (loc_time));
strftime (buf, LEN, "Hoje � %A, %b %d.\n", loc_time);
fputs (buf, stdout);
strftime (buf, LEN, "A hora � %I:%M:%S %p.\n", loc_time);
fputs (buf, stdout);
return 0;
}
