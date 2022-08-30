#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int codigo;
	char nome[30];
	float preco;
} produto;

int quantidadeProduto; // ja que todas funcoes terao acesso;

produto *criarProduto() {

	produto *p = (produto*) malloc(quantidadeProduto * sizeof(produto));

	if(!p) {
		printf("erro de alocacao de memoria!");
		return NULL;
	}

	else {
		return p;
	}
}

void cadastrarProduto(produto *p) {

	for (int i = 0; i < quantidadeProduto; i++) {
        printf("*******************************\n");
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &p[i].codigo);
        printf("Digite o nome do produto: ");
        scanf("%s", p[i].nome);
        printf("Digite o preco do produto: ");
        scanf("%f", &p[i].preco);
    }

	system("cls||clear");
}

void listarProdutos(produto *p) {

	printf("\nLista de produtos cadastrados:\n");

    for (int i = 0; i < quantidadeProduto; i++) {
        printf("\nCodigo: %d\n", p[i].codigo);
        printf("Nome: %s\n", p[i].nome);
    }

    printf("********************************************************\n");
}

void encontrarProduto(produto *p) {

	bool encontrou;
	int codigo;

	printf("\nDigite o codigo do produto que deseja consultar: ");

    scanf("%d", &codigo);

    for (int i = 0; i < quantidadeProduto; i++) {
        if (p[i].codigo == codigo) {
            printf("\nPreco do produto: %.2f\n", p[i].preco);
            encontrou = true;
        }
    }

    if( encontrou == false)
        printf("\nProduto nao encontrado\n");
}

int main() {

    printf("Quantos produtos deseja cadastrar? ");
    scanf("%d", &quantidadeProduto);

    produto *p = criarProduto();
	cadastrarProduto(p);
	listarProdutos(p);
	encontrarProduto(p);
   
    free(p);
    return 0;
}
/*aloque memória para o vetor de produtos  (struct), ai realizei o cadastro
deles e depois listei os mesmos e depois realizei a consulta de um
produto especifico que o usuario escolheu*/
