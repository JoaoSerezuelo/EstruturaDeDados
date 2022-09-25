#include <stdio.h>
#include <stdlib.h>

//pessoa
typedef struct{
    char nome[50];
    int idade;
    int matricula;
}Pessoa;
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e idade e matricula:\n");
    scanf("%s", p.nome);
    scanf("%i",p.idade);
    scanf("%i",p.matricula);
    fflush(stdin);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf(" Nome: %s  idade: %d matricula: %d ", p.nome,3p.idade,p.matricula);
}

//No
typedef struct no{
    Pessoa p;
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
void inserir_na_fila(Fila *fila, Pessoa humano){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->p=humano;
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
        imprimir_pessoa(aux->p);
        printf(" | ");
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}


int main()
{
    No *removido;
    Fila fila;
    int op,valor;
    Pessoa pessoaNova;

    criar_fila(&fila);

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n");
        scanf("%i",&op);
        system("cls");
        switch(op){
        case 1:
            pessoaNova=ler_pessoa();
            inserir_na_fila(&fila,pessoaNova);
            break;
        case 2:
            removido=remover_da_fila(&fila);
            if(removido){
                printf("Removido: ");
                imprimir_pessoa(removido->p);
                printf("\n");
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
