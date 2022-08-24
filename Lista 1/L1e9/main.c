#include <stdio.h>
#include <stdlib.h>
/*A fun��o fatorial duplo � definida como o produto de todos os
n�meros naturais �mpares de 1 at� algum n�mero natural �mpar
N. Assim, o fatorial duplo de 5 � 5!! = 1 * 3 * 5 = 15 Fa�a uma
fun��o recursiva que receba um n�mero inteiro positivo impar N
e retorne o fatorial duplo desse n�mero.*/

int fatd (int n){
    if(n==-1)
        return 1;
    if(n%2!=0)
        return n*fatd(n-2);
}
/*defini um caso base (-1) que retornava 1 para n�o alterar a multiplica��o fatorial
dupla e defini um IF, se o numero fosse impar multiplicava pelo proprio numero, fiz esse processo
at� chegar no caso base*/

int main(){
    int n;
    do{
        printf("inforne um numero inteiro positivo impar: ");
        scanf("%i",&n);
    }while(n%2==0);
    printf("o fatorial duplo de %i e: %i",n,fatd(n));
    return 0;
}
