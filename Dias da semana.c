#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
setlocale(LC_ALL,"portuguese");

int dia;

printf("Digite um n�mero para o dia da semana: ");
scanf("%d",&dia);

switch (dia)
{
case 7:
case 1:
printf("Final de semana.");
    break;
case 2:
case 3:
case 4:
case 5:
case 6:
printf("Dia �til.");
break;
default:
printf("Dia inv�lido.");
    break;
}

return 0;
}