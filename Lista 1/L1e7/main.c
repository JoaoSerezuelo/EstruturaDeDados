#include <stdio.h>
#include <stdlib.h>
/*Escreva uma fun��o recursiva que determine quantas vezes um
d�gito K ocorre em um n�mero natural N. Por exemplo, o d�gito
2 ocorre 3 vezes em 762021192.*/

int ocorrencia (int k, int n){
    int i=0;
    if(n==0){
        return 0;
    }
    else{
        if(n%10==k){
            i++;
        }
        return i+ocorrencia(k,n/10);
    }
}
/*dividi o numero por 10 sucessivamente at� ele zerar e chegar no caso base
e durante essa divis�o eu pegava o reto e chegava se esse n�mero era igual
ao numero k se sim adicionava um a um contador caso contrario nada acontecia*/

int main (){
    int k,n;
    printf("escreva um numero de 0 a 9:  ");
    scanf("%i",&k);
    printf("escreva um numero natural:  ");
    scanf("%i",&n);
    printf("o digito %i ocorre %i vezes em %i\n",k,ocorrencia(k,n),n);
    return 0;
}
