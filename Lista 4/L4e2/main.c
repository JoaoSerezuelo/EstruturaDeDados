#include <stdio.h>
#include <stdlib.h>

//Fila
typedef struct nofila{
    int valor;
    struct nofila *proximo;
}NoFila;
void inserir_na_fila(NoFila **fila, int num){
    NoFila *aux, *novo=malloc(sizeof(NoFila));
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;//T� INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(*fila==NULL)//FILA TA VAZIA AINDA
            *fila=novo;
        else{//fila n�o t� vazia
            //Percorrendo a Fila com ajuda do aux at� o final
            aux=*fila;
            while(aux->proximo)
                aux=aux->proximo;
            aux->proximo=novo;//a ultipa posi��o recebe o novo no que entrou na fila
        }
    }
    else
        printf("\n\nERRO AO ALOCAR MEMORIA\n\n");
}
NoFila* remover_da_fila(NoFila **fila){
    NoFila *remover=NULL;

    if(*fila){
        remover=*fila;//removi o primeiro elmento da fila
        *fila=remover->proximo;//fila recebeu o proximo elemento da fila
    }
    else
        printf("\n\nFila vazia\n");
    return remover;
}
void imprimir(NoFila *fila){
    printf("\n----- FILA ---------\n");
    while(fila){
        printf("%d | ",fila->valor);
        fila=fila->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}
int main()
{
    NoFila *fila=NULL, *removido;
    int op,valor;
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
            imprimir(fila);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
