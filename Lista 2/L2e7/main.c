#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vet=NULL, min=0,max=0,n;
    printf("Tamanho vetor: ");
    scanf("%i",&n);
    vet=(int*)malloc(n*sizeof(int));
    if(vet==NULL)
        printf("ERRO: MEMORIA INSUFICIENTE");
    for(int i=0;i<n;i++){
        printf("\n[%i] - ",i);
        scanf("%i",&vet[i]);
        if(i==0)
            min=vet[i];
        if(max>=vet[i])
            max=vet[i];
        if(min<=vet[i])
            min=vet[i];
    }
    vet=realloc(vet,n*2*sizeof(int));
    free(vet);
    return 0;
}
/*aloquei dinamicamente um vetor depois preenchi
 o mesmo e peguei o valor maximo e minimo do vetor
 e depois o realoquei com o dobro de seu tamanho*/
