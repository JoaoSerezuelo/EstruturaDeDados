#include <stdio.h>
#include <stdlib.h>

//Fila
typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserir_na_fila(No **fila, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;//TÁ INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(*fila==NULL)//FILA TA VAZIA AINDA
            *fila=novo;
        else{//fila não tá vazia
            //Percorrendo a Fila com ajuda do aux até o final
            aux=*fila;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;//a ultipa posição recebe o novo no que entrou na fila
        }
    }
    else
        printf("\n\nERRO AO ALOCAR MEMORIA\n\n");
}

void inserir_com_prioridade(No **fila, int num){
    No *aux, *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;//TÁ INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(*fila==NULL)//FILA TA VAZIA AINDA
            *fila=novo;
        else{//fila não tá vazia
            //é prioridade?
            if(num>59){
                //é a primeira prioridade?
                if((*fila)->valor<60){//primeira prioridade
                    novo->proximo= *fila;
                    *fila=novo;
                }
                else{//já tem outras prioridades
                    aux=*fila;
                    while(aux->proximo && aux->proximo->valor>59)
                        aux=aux->proximo;
                    novo->proximo=aux->proximo;
                    aux->proximo=novo;
                }
            }else{
                aux=*fila;
                while(aux->proximo)
                    aux=aux->proximo;
                aux->proximo=novo;//a ultipa posição recebe o novo no que entrou na fila
            }

        }
    }
    else
        printf("\n\nERRO AO ALOCAR MEMORIA\n\n");
}

No* remover_da_fila(No **fila){
    No *remover=NULL;

    if(*fila){
        remover=*fila;//removi o primeiro elmento da fila
        *fila=remover->proximo;//fila recebeu o proximo elemento da fila
    }
    else
        printf("\n\nFila vazia\n");
    return remover;
}

void imprimir(No *fila){
    printf("\n----- FILA ---------\n");
    while(fila){
        printf("%d | ",fila->valor);
        fila=fila->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

int main()
{
    No *fila=NULL, *removido;
    int op,valor;
    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - inserir com prioridade\n");
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
            imprimir(fila);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%i",&valor);
            inserir_com_prioridade(&fila,valor);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}

