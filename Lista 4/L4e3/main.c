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

Pilha *criarPilha() {
    Pilha *pilha = (Pilha*)malloc(sizeof(Pilha));
    if(!pilha) {
        printf("Erro de alocacao de memoria");
        return NULL;
    }

    return pilha;
}

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
    pilha->tam = 0;
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
void imprimir_fila(Fila *fila){
    No *aux=NULL;
    aux=fila->primeiro;
    printf("\n----- FILA ---------\n");
    while(aux){
        printf("%d | ",aux->valor);
        aux=aux->proximo;
    }
    printf("\n----- FIM FILA -----\n");
}

void liberarPilha(Pilha *pilha) {
    No *no = pilha->topo;
    if(!no) {
        printf("Pilha vazia");
        return;
    }

    while(no->proximo) {
        pop(pilha);
        no = no->proximo;
    }

    free(pilha);
}

//iverte fila usando pilha
void inverte(Fila *fila) {

    Pilha *pilha = criarPilha();
    inicializar(pilha);

    No *no = fila->primeiro;//no recebe o primeiro elemento da fila

    while(no) {//enquanto no for diferente de nulo
        push(pilha, no->valor);//empilha o valor do no
        no = no->proximo;//no recebe o proximo elemento da fila
        remover_da_fila(fila);//remove o primeiro elemento da fila
    }

    no = pilha->topo;

    while(no) {
        inserir_na_fila(fila, no->valor);//insere o valor do no na fila
        no = no->proximo;//no recebe o proximo elemento da pilha
    }

    liberarPilha(pilha);
}

int main() {
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
