#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor = NULL;
    int n;
    printf("Escreva o tamanho de um vetor: ");
    scanf("%i",&n);
    vetor=calloc(n,sizeof(int));
    if(vetor==NULL)
        printf("Errro na alocação de memoria");
    free(vetor);
    return 0;
}
/*CRIEI UM VETOR COM ALOCAÇÃO DINAMICA ATRAVES DA FUNÇÃO CALLOC
QUE VAI CRIAR UM VETOR DE TAMNHO N e vai inicializa-lo em todos os bits
com 0*/
