#include <stdio.h>
#include <stdlib.h>

//no
typedef struct no{
    int valor;
    struct no *proximo;
}No;

//inserir no inicio
void inserir_no_inicio(No **lista,int num){
    No *novo=malloc(sizeof(No));
    if(novo){
         novo->valor=num;
         novo->proximo=*lista;
         *lista=novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//inserir no fim
void inserir_no_fim(No **lista,int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;
        //é o primeiro?
         if(*lista==NULL)
            *lista=novo;
         else{
            aux=*lista;
            while(aux->proximo){
                aux=aux->proximo;
            }
            aux->proximo=novo;
         }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux,*novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        //é o primeiro?
        if(*lista==NULL){
            novo->proximo=NULL;
            *lista=novo;
        }
        else{
            aux=*lista;
            while(aux->valor != ant && aux->proximo){
                aux=aux->proximo;
            }
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(No **lista, int num){
    No*novo=malloc(sizeof(No));
    No *aux;
    if(novo){
        novo->valor=num;
        //a lista esta vazia?
        if(*lista==NULL){ //sim
            novo->proximo=NULL;
            *lista=novo
        }//é o menor?
        else if(novo->valor<(*lista)->valor){
            novo->proximo=*lista;
            *lista=novo;
        }
        else{
            aux=*lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux=aux->proximo;
            novo->proximo=aux->proximo;
            aux->proximo=novo;
        }

    }
    else
        printf("ERRO AO ALOCAR MEMORIA!\n");
}
//imprimir lista
void imprimir(No *no){
   printf("\nLista: \n");
   while(no){
       printf("%i\n",no->valor);
       no=no->valor;
   }
   printf("\nFim\n");
}
int main()
{
    int op,valor,anterior;
    No *lista=NULL;
    do{
        printf("\n0 - sair\n1 - inserir inicio\n2 - inserir final\n3 - inserir meio\n4 - imprimir\n5 - inserir ordenado\n");
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
        default:
            if(op!=0)
                printf("Opcao invalida!\n");
        }
    }while(op!=0);
    return 0;
}
