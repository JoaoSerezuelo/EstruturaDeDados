#include <stdio.h>
#include <stdlib.h>
/*Crie um programa em C, que contenha uma fun��o recursiva
que receba dois inteiros positivos k e n e calcule k^n. Utilize
apenas multiplica��es. O programa principal deve solicitar ao
usu�rio os valores de k e n e imprimir o resultado da chamada
da fun��o.*/

int pot(int k,int n){
    if(n==0)
        return 1;
    else
        return k*pot(k,n-1);
}
/*chamo a fun��o nela mesma multiplicando k por k, n vezes. vou diminuindo esse n que foi escolhido pelo usuario
em uma unidade at� ele ser igual a zero, que � quando eu chego meu caso base e multiplico tudo por 1 para acabar
a recursividade*/

int main(){
    int k,n;
    printf("base: ");
    scanf("%i",&k);
    printf("expoente: ");
    scanf("%i",&n);
    printf("resultado da potencia: %i",pot(k,n));
    return 0;
}
