#include <stdio.h>
#include <stdlib.h>
/*Fa�a uma fun��o recursiva que permita inverter um n�mero
inteiro N. Ex: 123 � 321*/
int inverter(int n){
    if(n==0)
        return n;
    else{
        printf("%i",n%10);
        return inverter(n/10);
    }
}
/*a fun��o vai verificar se o n�mero n�o � 0 porque se for acabou o objetivo dela, caso contrario ela vai continuar pegando e
escrevendo o resto da divis�o por 10 desse n�mero e chamando ele nessa mesma fun��o j� dividido por 10*/

int main (){
    int n;
    scanf("%i",&n);
    inverter(n);
    return 0;
}
