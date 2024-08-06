//Medida do tempo de um loop for vazio, com 500.000.000 de iterações
#include <stdio.h>
#include <time.h>

int main() {

time_t start,end;
volatile long unsigned contador;

start = time(NULL);

for(contador = 0; contador < 500000000; contador++); //sem corpo de execução

end = time(NULL);

printf("O loop for usa %f segundos.\n", difftime(end, start));

return 0;

}
