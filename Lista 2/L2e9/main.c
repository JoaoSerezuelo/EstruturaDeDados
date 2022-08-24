#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **p;
    int m,n,i,j;
    printf("Numeros de linha: ");
    scanf("%i",&m);
    printf("Numeros de colunas: ");
    scanf("%i",&n);
    p=(int**)malloc(m*sizeof(int));
    printf("Linha x Coluna\n");
    for(i=0;i<m;i++){
        p[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            p[i][j]=1+i;
            printf("%i x %i =  %i\n",i+1,j+1,p[i][j]);
        }
    }
    for(i=0;i<m;i++)
        free(p[i]);
    free(p);
    return 0;
}
/*aloquei dinamicamente a quantidade de linhas que o usuario queria
e depois aloquei a quantidade de colunas (fiz isso alocando em cada linha
uma coluna de acordo com a quantidade informada). Depois preenchi a matri usando
a formula 1+i, e para liberar a memoria alocada liberei primeiro as colunas deois as linhas*/
