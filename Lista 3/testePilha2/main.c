#include <stdio.h>
#include <stdlib.h>

//Structs Pessoa
typedef struct{
   int dia, mes, ano;
}Data;
typedef struct{
    char nome[50];
    Data data;
}Pessoa;

//struct No
typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

//struct pilha
typedef struct {
    No *topo;
    int tam;
}Pilha;



//Funções Pessoa
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d",p.nome,&p.data.dia,&p.data.mes,&p.data.ano);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}

//Pilha

//criando pilha
void criar_pilha(Pilha *p){
    p->topo=NULL;
    p->tam =0;
}
//push -> empilhar
void push(Pilha *p){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo-> p = ler_pessoa();
        novo-> proximo = p->topo;
        p->topo = novo;
        p->tam++;
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
}
//pop -> desempilhar
No* pop(Pilha *p){
    if(p->topo){
        No *remover = p->topo;
        p->topo = remover->proximo;
        p->tam--;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}
//imprimir pilha
void imprimir_pilha(Pilha *p){
    No *aux = p->topo;
    printf("\n------------ Pilha tam: %i-----------\n",p->tam);
    while(aux){
        imprimir_pessoa(aux->p);
        aux = aux->proximo;
    }
    printf("\n---------- Fim Pilha ----------\n");
}

int main()
{
    No *remover;
    Pilha p;
    int opcao;

    criar_pilha(&p);

    do{
        printf("\n0 - Sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                push(&p);
                break;
            case 2:
                remover=pop(&p);
                if(remover){
                    printf("\n\nElemento removido com sucesso!\n");
                    imprimir_pessoa(remover->p);
                    free(remover);
                    remover=NULL;
                }else
                    printf("\nSem no a remover.\n");
                break;
            case 3:
                imprimir_pilha(&p);
                break;
            default:
                if(opcao!=0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;
}
