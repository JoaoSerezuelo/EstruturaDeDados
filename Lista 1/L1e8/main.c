#include <stdio.h>
#include <stdlib.h>
/*Fa�a uma fun��o recursiva que receba um n�mero inteiro
positivo par N e imprima todos os n�meros pares de 0 at� N em
ordem decrescente.*/

void par (int n){
    if(n>=0){
        printf(" %i |",n);
        par(n-2);
    }
}
/*peguei o numero par (fiz uma checagem na fun��o main) e foi tirando
de 2 em 2 at� chegar a zero quando eu parava de fazer esse processo,
no meio do processo eu escrevia os numeros*/

int main (){
    int n;
    do{
        printf("escreva um numero par: ");
        scanf("%i",&n);
        if(n%2!=0){
            printf("so e aceito numero par\n");
        }
        if(n<0){
            n=n*-1;
        }
    }while(n%2!=0);
    printf("\n");
    par(n);
    return 0;
}
