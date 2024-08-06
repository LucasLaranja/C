#include <time.h>
#include <stdio.h>

int main() {

time_t minha_hora;
minha_hora = time(NULL);

printf(ctime(&minha_hora));

return 0;

}
