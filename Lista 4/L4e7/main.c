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
        novo->proximo=NULL;//T� INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(fila->primeiro==NULL){//FILA TA VAZIA AINDA
            //posi��es sendo preenchidas com o no novo
            fila->primeiro=novo;
            fila->fim=novo;
        }
        else{//fila n�o t� vazia
            fila->fim->proximo=novo;//a variavel que tava no fim agora aponta p/ nova variavel que t� no fim
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
        fila->primeiro=remover->proximo;//primeiro elemneto da fila � atualizado
        fila->tam--;
    }
    else
        printf("\n\nFila vazia\n");
    return remover;
}
void reverso(Fila *fila){
    if(!fila->primeiro)
        return;//fila vazia
    else{
        No *removido;
        removido=remover_da_fila(&fila);//removendo o primeiro elemento da fila
        reverso(&fila);//chamada recursiva
        inserir_na_fila(&fila,removido->valor);//inserindo o elemento removido no final da fila
        free(removido);//liberando a memoria
    }
}
void imprimir(Fila *fila){
    No *aux=fila->primeiro;
    printf("\n----- FILA ---------\n");
    while(aux){
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
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - reverso\n");
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
        case 4:
            reverso(&fila);
            imprimir(&fila);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
