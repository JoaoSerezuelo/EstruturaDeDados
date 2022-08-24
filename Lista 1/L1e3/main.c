#include <stdio.h>
#include <stdlib.h>
/*Crie uma função recursiva que receba um número inteiro
positivo N e calcule o somatório dos números de 1 a N.*/
int somatorio (int n){
    if(n==1)
        return 1;
    else
        return n+somatorio(n-1);
}
/*somei todos os numeros de 1 até n, comecando pelo n e chamando novamente a função sucessivamente
 até chegar no caso base 1 que retorna 1 para soma e acaba aí o problema*/
int main()
{
    int n;
    printf("Escolha um numero: ");
    scanf("%i",&n);
    if(n<0)
        n=n*-1;
    somatorio(n);
    printf("O somatorio de 1 ate %i e igual a: %i",n,somatorio(n));
    return 0;
}
