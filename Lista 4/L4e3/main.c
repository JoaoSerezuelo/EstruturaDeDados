#include <stdio.h>
#include <stdlib.h>

//No
typedef struct no{
    int valor;
    struct no *proximo;
}No;
//Fila
typedef struct{
    No *primeiro;
    No *fim;
    int tam;
}Fila;
//pilha
typedef struct{
    No *topo;
    int tam;
}Pilha;

//pilha funcoes
void criar_pilha(Pilha *p){
    p->topo=NULL;
    p->tam=0;
}
void push(Pilha *p,int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=p->topo;
        p->topo=novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
}
No* pop(Pilha *p){
    if(p->topo){
        No *remover=p->topo;
        p->topo=remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}
//Fila funcoes
void criar_fila(Fila *fila){
    fila->primeiro=NULL;
    fila->fim=NULL;
    fila->tam=0;
}
void inserir_na_fila(Fila *fila, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;//TÁ INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(fila->primeiro==NULL){//FILA TA VAZIA AINDA
            //posições sendo preenchidas com o no novo
            fila->primeiro=novo;
            fila->fim=novo;
        }
        else{//fila não tá vazia
            fila->fim->proximo=novo;//a variavel que tava no fim agora aponta p/ nova variavel que tá no fim
            fila->fim=novo;//fim da fila recebe o novo no;
        }
        fila->tam++;
    }
    else
        printf("\n\nERRO AO ALOCAR MEMORIA\n\n");
}
No* remover_da_fila(Fila *fila){
    No *remover=NULL;

    if(fila->primeiro){
        remover=fila->primeiro;//removi o primeiro elmento da fila
        fila->primeiro=remover->proximo;//primeiro elemneto da fila é atualizado
        fila->tam--;
    }
    else
        printf("\n\nFila vazia\n");
    return remover;
}
void imprimir_fila(Fila fila){
    No *aux=NULL;
    aux=fila->primeiro;
    printf("\n----- FILA ---------\n");
    while(aux){
        printf("%d | ",aux->valor);
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

//iverte fila usando pilha
void inverte(Fila *fila){
    Pilha p;
    No *removido;
    int aux;
    criar_pilha(&p);
    //esvazio a fila e preencho a pila
    while(fila){
        removido=remover_da_fila(&fila);
        aux=removido->valor;
        free(removido);
        push(&p,aux);
    }
    //esvazio a pilha e preencho a fila
    while(p){
        removido=pop(&p);
        aux=removido->valor;
        free(removido);
        inserir_na_fila(&fila,aux);
    }
}
int main()
{
    No *removido;
    Fila fila;
    int op,valor;

    criar_fila(&fila);

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - iverter fila");
        scanf("%i",&op);
        system("cls");
        switch(op){
        case 1:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            inserir_na_fila(&fila,valor);
            break;
        case 2:
            removido=remover_da_fila(&fila);
            if(removido){
                printf("Removido: %i\n",removido->valor);
                free(removido);
                removido=NULL;
            }
            break;
        case 3:
            imprimir_fila(&fila);
            break;
        case 4:
            inverte(&fila);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
