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

void imprimir(Fila fila){
    No *aux=fila->primeiro;
    printf("\n----- FILA ---------\n");
    while(aux)){
        printf("%d | ",aux->valor);
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

int main()
{
    No *removido;
    Fila fila;
    int op,valor;

    criar_fila(&fila);

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
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
            imprimir(&fila);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
