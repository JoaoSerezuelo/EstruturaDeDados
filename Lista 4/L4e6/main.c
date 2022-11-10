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
void inserir_ordenado(No **fila, int num){
    No *aux, *novo=malloc(sizeof(No));
    aux=*fila;
    if(novo){
        novo->valor=num;
        novo->proximo=NULL;//TA INSERINDO NO FINAL POR ISSO PROXIMO VAI SER SEMPRE NULO
        if(*fila==NULL)//FILA TA VAZIA AINDA
            *fila=novo;
        else{//fila nAo tA vazia
            //E prioridade?
            if((*fila)->valor>num){//primeira prioridade
                novo->proximo= *fila;
                *fila=novo;
            }
            else{//jA tem outras prioridades
                while(aux->proximo && aux->proximo->valor<num)
                    aux=aux->proximo;
                novo->proximo=aux->proximo;
                aux->proximo=novo;
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
void fila_pricipal_ordenado(No **fila, No **fila2, No **fila3){
    int i;
    No *removido;
    for(i=0;i<3;i++){
        removido=remover_da_fila(&fila2);//removendo da fila 2
        inserir_na_fila(&fila,removido->valor);//inserindo na fila principal
        free(removido);//liberando o no removido
    }
    for(i=0;i<3;i++){
        removido=remover_da_fila(&fila3);//removendo da fila 3
        inserir_ordenado(&fila,removido->valor);//inserindo na fila principal
        free(removido);//liberando o no removido
    }
}
int main()
{
    No *fila=NULL, *removido;
    No *fila2=NULL, *fila3=NULL;
    int valor,i;
    for(i=0;i<6;i++){
        inserir_na_fila(&fila2,i);
        i++;
        inserir_na_fila(&fila3,i);
    }
    printf("Fila 1:\n");
    imprimir(fila2);
    printf("Fila 2:\n");
    imprimir(fila3);
    printf("nova fila: \n");
    fila_pricipal_ordenado(&fila,&fila2,&fila3);
    imprimir(fila);
    return 0;
}
