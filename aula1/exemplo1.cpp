#include <stdio.h>
//Prot�tipo de fun��o
int max (int num1, int num2);
int main () {
int a = 100;
int b = 200;
int ret;
//chamando uma fun��o para obter o valor m�ximo
ret = max (a, b);
printf ("O valor m�ximo �:% d \n", ret);
return 0;
}
//fun��o que retorna valor m�ximo
int max (int num1, int num2) {
int resultado;
if (num1> num2)
resultado = num1;
else
resultado = num2;
return resultado;
}
