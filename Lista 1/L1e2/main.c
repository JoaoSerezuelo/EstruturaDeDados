#include <stdio.h>
#include <stdlib.h>

/*Fa�a uma fun��o recursiva que permita somar os elementos de
um vetor de inteiros.*/

int soma(int v[], int n){
    if(n==0)
        return 0;
    else{
        return v[n-1]+soma(v,n-1);
    }
}
/*soma os n�meros armazenados no vetor do ultimo indice ao primeiro indice desse vetor
quando chega no primeiro indice que � caso base faz com que a recurs�o termine e se resolva o problema*/

int main (){
    int n,i=0;
    printf("Quantos numeros inteiros voce deseja escrever? ");
    scanf("%i",&n);
    int v[n];
    for(i=0;i<n;i++){
        printf("%i -  ",i);
        fflush(stdin);
        scanf("%i",&v[i]);
    }
    printf("a soma desses numeros e: %i",soma(v,n));
    return 0;
}
