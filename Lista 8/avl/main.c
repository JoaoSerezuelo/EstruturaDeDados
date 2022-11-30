#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    short altura;
}No;

//funcao para cirar um novo no
No* novoNo(int x){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = x;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        novo->altura = 0;
    }
    else
        printf("\nERRO ao alocar memoria!\n");
    return novo;
}
//maior subarvore
short maior(short a, short b){
    return (a > b)? a: b;
}
//  Retorna a altura de um no ou -1 caso ele seja null
short alturaDoNo(No *no){
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

//   Calcula e retorna o fator de balanceamento de um no
short fatorDeBalanceamento(No *no){
    if(no)
        return (alturaDoNo(no->esquerdo) - alturaDoNo(no->direito));
    else
        return 0;
}

// rotacoes
// rotcao esquerda
No* rotacaoEsquerda(No *r){//r e o no que foi identificado como desbalanceado para a direita
    No *y, *f;

    y = r->direito;//y e o filho a direita de r
    f = y->esquerdo;//f e o filho a esquerda de y

    y->esquerdo = r;//y passa a ser o filho a esquerda de r
    r->direito = f;//r passa a ser o filho a direita de y

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}
//rotacao direita
No* rotacaoDireita(No *r){//r e o no que foi identificado como desbalanceado para a esquerda    
    No *y, *f;

    y = r->esquerdo;//y e o filho a esquerda de r
    f = y->direito;//f e o filho a direita de y

    y->direito = r;//y passa a ser o filho a direita de r
    r->esquerdo = f;//r passa a ser o filho a esquerda de y

    r->altura = maior(alturaDoNo(r->esquerdo), alturaDoNo(r->direito)) + 1;
    y->altura = maior(alturaDoNo(y->esquerdo), alturaDoNo(y->direito)) + 1;

    return y;
}
//rotacao dupla
//rotacao esquerda direita
No* rotacaoEsquerdaDireita(No *r){//r ta desbalanceado para a direita e seu filho a direita ta desbalanceado para a esquerda
    r->esquerdo = rotacaoEsquerda(r->esquerdo);
    return rotacaoDireita(r);
}
//rotacao direita esquerda
No* rotacaoDireitaEsquerda(No *r){//r ta desbalanceado para a esquerda e seu filho a esquerda ta desbalanceado para a direita
    r->direito = rotacaoDireita(r->direito);
    return rotacaoEsquerda(r);
}
//balanceamento
No* balancear(No *raiz){
    short fb = fatorDeBalanceamento(raiz);

    if(fb < -1 && fatorDeBalanceamento(raiz->direito) <= 0){
        raiz = rotacaoEsquerda(raiz);
        printf("\nRotacao Esquerda\n");
    }
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) >= 0){
        raiz = rotacaoDireita(raiz);
        printf("\nRotacao Direita\n");
    }
    else if(fb > 1 && fatorDeBalanceamento(raiz->esquerdo) < 0){
        raiz = rotacaoEsquerdaDireita(raiz);
        printf("\nRotacao Esquerda Direita\n");
    }
    else if(fb < -1 && fatorDeBalanceamento(raiz->direito) > 0){
        raiz = rotacaoDireitaEsquerda(raiz);
        printf("\nRotacao Direita Esquerda\n");
    }
    return raiz;
}
//insercao
No* inserir(No *raiz, int x){
    if(raiz == NULL)
        return novoNo(x);
    else{
        if(x < raiz->valor)
            raiz->esquerdo = inserir(raiz->esquerdo, x);
        else if(x > raiz->valor)
            raiz->direito = inserir(raiz->direito, x);
        else
            printf("\nInsercao nao realizada!\nO elemento %d a existe!\n", x);
    }
    //atualiza a altura de todos os
    raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

    raiz = balancear(raiz);

    return raiz;
}
//remocao
No* remover(No *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { //procura o valor a ser removido
        if(raiz->valor == chave) {
            // remove nos folhas
            if(raiz->esquerdo == NULL && raiz->direito == NULL) {//se o no a ser removido for folha
                free(raiz);//libera o no
                printf("Elemento folha removido: %d !\n", chave);//informa que o no foi removido
                return NULL;
            }
            else{
                // remover nos que possuem 2 filhos
                if(raiz->esquerdo != NULL && raiz->direito != NULL){
                    //vou trocar o valor do no a ser removido pelo maior valor da subarvore a esquerda
                    //para ele ficar no lugar de um no com um filho ou um no folha
                    No *aux = raiz->esquerdo;//aux e o no a esquerda do no a ser removido
                    while(aux->direito != NULL)
                        aux = aux->direito;//aux vai andando para a direita ate chegar no maior valor da subarvore a esquerda
                    raiz->valor = aux->valor;//o valor do no a ser removido recebe o valor do maior valor da subarvore a esquerda
                    aux->valor = chave;//o valor do maior valor da subarvore a esquerda recebe o valor do no a ser removido
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esquerdo = remover(raiz->esquerdo, chave);//remove o no que tinha o maior valor da subarvore a esquerda
                    return raiz;
                }
                else{
                    // remover nos que possuem apenas 1 filho
                    No *aux;
                    if(raiz->esquerdo != NULL)
                        aux = raiz->esquerdo;
                    else
                        aux = raiz->direito;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->valor)//se a chave for menor que o valor do no atual, vou procurar na subarvore a esquerda
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            else//se a chave for maior que o valor do no atual, vou procurar na subarvore a direita
                raiz->direito = remover(raiz->direito, chave);
        }

        // Recalcula a altura de todos os nos entre a raiz e o no removido
        raiz->altura = maior(alturaDoNo(raiz->esquerdo), alturaDoNo(raiz->direito)) + 1;

        // verifica a necessidade de rebalancear a arvore
        raiz = balancear(raiz);

        return raiz;
    }
}
//impressao
void imprimir(No *raiz, int nivel){
    int i;
    if(raiz){
        imprimir(raiz->direito, nivel + 1);
        printf("\n\n");

        for(i = 0; i < nivel; i++)
            printf("\t");

        printf("%d", raiz->valor);
        imprimir(raiz->esquerdo, nivel + 1);
    }
}

int main(){

    int opcao, valor;
    No *raiz = NULL;

    do{
        printf("\n\n\t0 - Sair\n\t1 - Inserir\n\t2 - Remover\n\t3 - Imprimir\n\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 0:
            printf("Saindo!!!");
            break;
        case 1:
            printf("\tDigite o valor a ser inserido: ");
            scanf("%d", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 2:
            printf("\tDigite o valor a ser removido: ");
            scanf("%d", &valor);
            raiz = remover(raiz, valor);
            break;
        case 3:
            imprimir(raiz, 1);
            break;
        default:
            printf("\nOcao invalida!!!\n");
        }

    }while(opcao != 0);

    return 0;
}
