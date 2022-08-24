#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    typedef struct
    {
        int codigo;
        char nome[30];
        float preco;
    } produto;

    produto *p;
    int i, n, codigo;
    bool boleano=false;

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &n);

    p = (produto*) malloc(n * sizeof(produto));//alocação de memória para o vetor de produtos
    if(p == NULL)
    {
        printf("Memoria insuficiente");//se não houver memória suficiente, o programa é encerrado
    }
    //cadastro dos produtos
    for (i = 0; i < n; i++)
    {
        printf("*******************************\n");
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &p[i].codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", p[i].nome);
        printf("Digite o preco do produto: ");
        scanf("%f", &p[i].preco);
    }
    system("cls");
    //lista de produtos cadastrados
    printf("\nLista de produtos cadastrados:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nCodigo: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
    }
    printf("********************************************************\n");
    //busca do produto
    printf("\nDigite o codigo do produto que deseja consultar: ");
    scanf("%d", &codigo);
    for (i = 0; i < n; i++)
    {
        if (p[i].codigo == codigo)
        {
            printf("\nPreco do produto: %.2f\n", p[i].preco);
            boleano = true;
        }
    }
    if( boleano == false)
        printf("\nProduto nao encontrado\n");
    free(p);
    return 0;
}
/*aloque memória para o vetor de produtos  (struct), ai realizei o cadastro
deles e depois listei os mesmos e depois realizei a consulta de um
produto especifico que o usuario escolheu*/
