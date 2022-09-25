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
    printf("\nDigite nome: ");
    scanf("%s", p.nome);
    printf("idade: ");
    scanf("%i",&p.idade);
    printf("matricula: ");
    scanf("%i",&p.matricula);
    fflush(stdin);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf(" Nome: %s  idade: %d matricula: %d ", p.nome,p.idade,p.matricula);
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
    int x=1;
    printf("\n----- FILA (Tamnho: %i) ---------\n",fila->tam);
    while(aux){
        printf("\n");
        printf("************ %i *****************\n",x);
        imprimir_pessoa(aux->p);
        printf("\n");
        x++;
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

void separa(Fila *f1,Fila *f2,int matricula){
    No *aux=f1->primeiro;
    No *aux2=f1->primeiro;
    int x=1,i=0;

    //rodei a fila 1 até achar a matricula que vai separar a fila
    while(aux){
        if(aux->p.matricula==matricula){
            break;
        }
        x++;
        aux=aux->proximo;
    }

    x=f1->tam-x;
    i=x;

    //preenchi a fila 2 a partir da matricula que separou as filas
    do{
        inserir_na_fila(f2,aux->p);
        aux=aux->proximo;
        x--;
    }while(x!=0);

    //imprimindo as filas
    printf("\nFila 1: ");
    printf("\n----- FILA (Tamnho: %i) ---------\n",i);
    i=1;
    while(aux2){
        printf("\n");
        printf("************ %i *****************\n",i);
        imprimir_pessoa(aux2->p);
        printf("\n");
        i++;
        aux2=aux2->proximo;
    }
    printf("\n----- FIM FILA -----\n");
    printf("\nFila 2: ");
    imprimir(f2);
}

int main()
{
    No *removido;
    Fila fila, fila2;
    int op,matricula,tamanho;
    Pessoa pessoaNova;

    criar_fila(&fila);
    criar_fila(&fila2);

    do{
        printf("\n0 - Sair\n1 - Inserir\n2 - Remover\n3 - Imprimir\n4 - separar fila\n");
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
            case 4:
                printf("\nNumero da matricula que vai dividir as filas: ");
                scanf("%i",&matricula);
                separa(&fila,&fila2,matricula);
                tamanho=fila2.tam;
                while(tamanho!=0){
                    removido=remover_da_fila(&fila2);
                    free(removido);
                    tamanho--;
                    removido=NULL;
                }
                break;
            default:
                if(op!=0)
                    printf("\nOpcao invalida\n");
        }
    }while(op!=0);
    return 0;
}
