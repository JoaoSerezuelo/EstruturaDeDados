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
         novo->valor=num;
         novo->proximo=lista->inicio;
         lista->inicio=novo;
         lista->tam++;
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//inserir no fim
void inserir_no_fim(Lista *lista,int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        //é o primeiro?
         if(lista->inicio==NULL)
            lista->inicio=novo;
         else{
            aux=lista->inicio;
            while(aux->proximo){
                aux=aux->proximo;
            }
            aux->proximo=novo;
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
        novo->valor=num;
        //é o primeiro?
        if(lista->inicio==NULL){
            novo->proximo=NULL;
            lista->inicio=novo;
        }
        else{
            aux=lista->inicio;
            while(aux->valor != ant && aux->proximo){
                aux=aux->proximo;
            }
            novo->proximo=aux->proximo;
            aux->proximo=novo;
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
        novo->valor=num;
        if(lista->inicio==NULL){
            novo->proximo=NULL;
            lista->inicio=novo;
        }
        else if(novo->valor < lista->inicio->valor){
            novo->proximo=lista->inicio;
            lista->inicio=novo;
        }
        else{
            aux=lista->inicio;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux=aux->proximo;
            novo->proximo=aux->proximo;
            aux->proximo=novo;
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
    if(lista->inicio){
        if(lista->inicio->valor==num){
            remover=lista->inicio;
            lista->inicio=remover->proximo;
            lista->tam--;
        }
        else{
            aux=lista->inicio;
            while(aux->proximo && aux->proximo->valor!=num)
                aux=aux->proximo;
            if(aux->proximo){
                remover=aux->proximo;
                aux->proximo=remover->proximo;
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
