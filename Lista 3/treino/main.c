#include <stdio.h>
#include <stdlib.h>

//Structs Pessoa
typedef struct{
    char nome[50];
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



//Fun  es Pessoa
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]",p.nome);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\n", p.nome);
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
        novo-> p = ler_pessoa();//ler pessoa
        novo-> proximo = p->topo;//clona o topo antigo para o proximo da nova stutura que ta no topo
        p->topo = novo;//topo é atualizado para o endereço da nova estrutura que esta no topo
        p->tam++;//tamanho da pilha é atualizado
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
}
//pop -> desempilhar
No* pop(Pilha *p){
    if(p->topo){
        No *remover = p->topo;//remover recebe o topo da pilha
        p->topo = remover->proximo;//topo da pilha recebe o proximo da pilha(posição da estrutura que está embaixo)
        p->tam--;//tamanho da pilha é atualizado
        return remover;//retorna a estrutura que foi removida
    }
    else
        printf("\nPilha vazia!\n");
    return NULL;
}
//imprimir pilha
void imprimir_pilha(Pilha *p){
    No *aux = p->topo;//aux recebe o topo da pilha
    printf("\n------------ Pilha tam: %i-----------\n",p->tam);
    while(aux){//enquanto aux for diferente de NULL
        imprimir_pessoa(aux->p);//imprime a pessoa que esta sendo apontada por aux
        aux = aux->proximo;//aux vai descendo na pilha
    }
    printf("\n---------- Fim Pilha ----------\n");
}

int main()
{
    No *remover;//remover para recebe o topo da pilha
    Pilha p;//pilha
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
                    imprimir_pessoa(remover->p);//imprime a pessoa que foi removida
                    free(remover);//livra a memoria alocada para a pessoa que foi removida
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
