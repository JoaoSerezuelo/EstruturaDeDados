#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct{
   int dia, mes, ano;
}Data;
typedef struct{
    char nome[50];
    Data data;
}Pessoa;
typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

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

//push -> empilha
No* push(No *topo){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo-> p = ler_pessoa();
        novo-> proximo = topo;
        return novo;
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
    return NULL;
}

//pop -> desempilha
No* pop(No **topo){
    if(*topo != NULL){
        No *remover = *topo;
        *topo = remover->proximo;
        return remover;
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}

//imprimir pilha
void imprimir_pilha(No *topo){
    printf("\n------------ Pilha -----------\n");
    while(topo){
        imprimir_pessoa(topo->p);
        topo = topo->proximo;
    }
    printf("\n---------- Fim Pilha ----------\n");
}

int main()
{
    No *remover, *topo=NULL;
    int opcao;

    do{
        printf("\n0 - Sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");
        scanf("%d",&opcao);
        getchar();
        switch(opcao){
            case 1:
                topo=push(topo);
                break;
            case 2:
                remover=pop(&topo);
                if(remover){
                    printf("\n\nElemento removido com sucesso!\n");
                    imprimir_pessoa(remover->p);
                }else
                    printf("\nSem no a remover.\n");
                break;
            case 3:
                imprimir_pilha(topo);
                break;
            default:
                if(opcao!=0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;
}
