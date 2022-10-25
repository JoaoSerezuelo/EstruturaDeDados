#include <stdio.h>
#include <stdlib.h>

//no
typedef struct no{
    int valor;
    struct no *proximo;
}No;
//Lista
typedef struct{
    No *inicio;
    int tam;
}Lista;
void criar_lista(Lista *lista){
    lista->inicio=NULL;
    lista->tam=0;
}

//inserir no inicio
void inserir_no_inicio(Lista *lista,int num){
    No *novo=malloc(sizeof(No));
    if(novo){
         novo->valor=num;//valor do novo nó recebe o valor passado por parametro
         novo->proximo=lista->inicio;//o proximo do novo nó recebe que etsva no inicio da lista
         lista->inicio=novo;//o inicio da lista recebe o novo nó
         lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//inserir no fim
void inserir_no_fim(Lista *lista,int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;//valor do novo nó recebe o valor passado por parametro
        novo->proximo=NULL;//o proximo do novo nó recebe NULL
        //� o primeiro?
         if(lista->inicio==NULL)//se a lista tiver vazia
            lista->inicio=novo;//o inicio da lista recebe o novo nó
         else{//se a lista nao tiver vazia
            aux=lista->inicio;//aux recebe o inicio da lista
            while(aux->proximo){//percorre a lista ate o ultimo nó
                aux=aux->proximo;//aux recebe o proximo de aux 
            }
            aux->proximo=novo;//o proximo do ultimo nó recebe o novo nó
         }
         lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//inserir no meio
void inserir_no_meio(Lista *lista, int num, int ant){
    No *aux,*novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;//valor do novo nó recebe o valor passado por parametro
        //� o primeiro?
        if(lista->inicio==NULL){//se a lista tiver vazia
            novo->proximo=NULL;//o proximo do novo nó recebe NULL
            lista->inicio=novo;//o inicio da lista recebe o novo nó
        }
        else{//se a lista nao tiver vazia
            aux=lista->inicio;//aux recebe o inicio da lista
            while(aux->valor != ant && aux->proximo){//percorre a lista ate o ultimo nó ou ate achar o valor anterior
                aux=aux->proximo;//aux recebe o proximo de aux
            }
            novo->proximo=aux->proximo;//o proximo do novo nó recebe o proximo de aux
            aux->proximo=novo;//o proximo de aux recebe o novo nó
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(Lista *lista,int num){
    No *novo=malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->valor=num;//valor do novo nó recebe o valor passado por parametro
        if(lista->inicio==NULL){//se a lista tiver vazia
            novo->proximo=NULL;//o proximo do novo nó recebe NULL
            lista->inicio=novo;//o inicio da lista recebe o novo nó
        }
        else if(novo->valor < lista->inicio->valor){//se o valor do novo nó for menor que o valor do primeiro nó
            novo->proximo=lista->inicio;//o proximo do novo nó recebe o inicio da lista
            lista->inicio=novo;//o inicio da lista recebe o novo nó
        }
        else{
            aux=lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)//percorre a lista ate o ultimo nó ou ate achar um valor maior que o valor do novo nó
                aux=aux->proximo;
            novo->proximo=aux->proximo;//o proximo do novo nó recebe o proximo de aux
            aux->proximo=novo;//o proximo de aux recebe o novo nó
        }
        lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n ");
}
//remover
No* remover(Lista *lista, int num){
    No *remover=NULL;
    No *aux;
    if(lista->inicio){//se a lista nao estiver vazia
        if(lista->inicio->valor==num){//se o valor do primeiro nó for igual ao valor passado por parametro
            remover=lista->inicio;//o nó a ser removido recebe o inicio da lista
            lista->inicio=remover->proximo;//o inicio da lista recebe o proximo do nó a ser removido
            lista->tam--;//diminui o tamanho da lista
        }
        else{
            aux=lista->inicio;//aux recebe o inicio da lista 
            while(aux->proximo && aux->proximo->valor!=num)//percorre a lista ate o ultimo nó ou ate achar o valor passado por parametro
                aux=aux->proximo;//aux recebe o proximo de aux
            if(aux->proximo){//se o proximo de aux nao for NULL
                remover=aux->proximo;//o nó a ser removido recebe o proximo de aux
                aux->proximo=remover->proximo;//o proximo de aux recebe o proximo do nó a ser removido
                lista->tam--;
            }
        }
    }
    return remover;
}
//imprimir lista
void imprimir(Lista lista){
    No *no=lista.inicio;
    printf("\nLista tamanho(%i): \n",lista.tam);
    while(no){
       printf("%i\n",no->valor);
       no=no->valor;
    }
    printf("\nFim\n");
}
int main()
{
    int op,valor,anterior;
    Lista lista;
    No *removido=NULL;
    criar_lista(&lista);
    do{
        printf("\n0 - sair\n1 - inserir inicio\n2 - inserir final\n3 - inserir meio\n4 - imprimir\n5 - inserir ordenado\n6 - remover\n");
        scanf("%i",&op);
        switch(op){
        case 1:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            inserir_no_inicio(&lista,valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            inserir_no_fim(&lista,valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%i%i",&valor,&anterior);
            inserir_no_meio(&lista,valor,anterior);
            break;
        case 4:
            imprimir(lista);
            break;
        case 5:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            inserir_ordenado(&lista,valor);
            break;
        case 6:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            removido=remover(&lista,valor);
            if(removido){
                printf("Elemento removido: %i\n",removido->valor);
                free(removido);
            }
            else{
                printf("Elemento inesistente\n");
            }
            break;
        default:
            if(op!=0)
                printf("Opcao invalida!\n");
        }
    }while(op!=0);
    return 0;
}
