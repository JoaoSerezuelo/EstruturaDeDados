#include <stdio.h>
#include <stdlib.h>
int inverte_vetor(int *v1, int *v2, int n){
    int maior=0,i=n,j=0;
    for(i,j;i>=0;i--,j++){
        if(maior<v1[j])
            maior=v1[j];
        v2[j]=v1[i];
    }
    return maior;
}
int main()
{
    int *v1=NULL, *v2=NULL, n;
    printf("TAMANHO DO VETOR:  ");
    scanf("%i",&n);
    v1=(int*)calloc(n,sizeof(int));
    v2=(int*)calloc(n,sizeof(int));
    if(v1==NULL || v2==NULL)
        printf("ERRO: MEMORIA INSUFICIENTE");
    for(int i=0;i<n;i++){
        printf("Elemento %i: ",i+1);
        scanf("%i",&v1[i]);
    }
    printf("************************************\n");
    printf("o maior numero e: %i\n",inverte_vetor(v1,v2,n-1));
    for(int i=0; i<n;i++)
        printf("\nV2[%i] = %i",i,v2[i]);
    free(v1);
    free(v2);
    v1=NULL;
    v2=NULL;
    return 0;
}
/*Aloquei dinamicamente dois vetores com o mesmo tamanho, depois eu li o
vetor v1 e com auxilio da função inverte_vetor o v2 recebeu o vetor v1
invertido e nessa mesma função e retornei o maior valor de v1*/

