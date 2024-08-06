#include <stdio.h>
//Protótipo de função
int max (int num1, int num2);
int main () {
int a = 100;
int b = 200;
int ret;
//chamando uma função para obter o valor máximo
ret = max (a, b);
printf ("O valor máximo é:% d \n", ret);
return 0;
}
//função que retorna valor máximo
int max (int num1, int num2) {
int resultado;
if (num1> num2)
resultado = num1;
else
resultado = num2;
return resultado;
}
