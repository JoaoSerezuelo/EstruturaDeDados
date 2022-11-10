#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct{
    char nome[50];
    char codigo[50];
}Aviao;
//No
typedef struct no{
    Aviao av;;
    struct no *proximo;
}No;
//Fila
typedef struct{
    No *primeiro;
    No *fim;
    int tam;
}Fila;

//aviao
Aviao ler_av(){
    Aviao a;
    printf("Digite a companhia area e o codigo do aviao: ");
    setbuf(stdin,NULL);
    scanf("%s",a.nome);
    setbuf(stdin,NULL);
    scanf("%s",a.codigo);
}
void imprimir_aviao(Aviao av){
    printf("Companhia area: %s  codigo aviao: %s",av.nome,av.codigo);
}
//FILa
void criar_fila(Fila *fila){
    fila->primeiro=NULL;
    fila->fim=NULL;
    fila->tam=0;
}
void inserir_na_fila(Fila *fila, Aviao av){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->av=av;
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
void imprimir(Fila *fila){
    No *aux=fila->primeiro;
    printf("\n----- FILA ---------\n");
    while(aux){
        imprimir_aviao(aux->av);
        printf("\n");
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

int main()
{
    No *removido;
    Fila fila;
    int op;
    Aviao av;

    criar_fila(&fila);
    setlocale(LC_ALL,"");
    do{
        printf("\n0 - Sair\n1 - adicionar aviao a fila de espera\n2 - autorizar decolagem\n3 - Imprimir todos os avioes\n4 - avioes esperando\n5 - caracteristicas do primeiro aviao\n");
        scanf("%i",&op);
        system("cls");
        switch(op){
        case 1:
            av=ler_av();
            inserir_na_fila(&fila,av);
            break;
        case 2:
            removido=remover_da_fila(&fila);
            if(removido){
                printf("aviao que decolou: \n");
                imprimir_aviao(removido->av);
                printf("\n");
                free(removido);
                removido=NULL;
            }
            break;
        case 3:
            imprimir(&fila);
            break;
        case 4:
            printf("avioes esperando: %i\n",fila.tam);
            break;
        case 5:
            printf("informacoes primeiro aviao: ");
            imprimir_aviao(fila.primeiro->av);
            break;
        default:
            if(op!=0)
                printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
