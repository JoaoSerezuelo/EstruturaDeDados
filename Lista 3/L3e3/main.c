#include <stdio.h>
#include <stdlib.h>


//Pilha
typedef struct no{
    int x;
    struct no *proximo;
}No;
typedef struct{
    No *topo;
    int tam;
}Pilha;
void imprimir_numero(No *n){
    printf("%i\n",n->x);
}
void criar_pilha(Pilha *p){
    p->topo=NULL;
    p->tam=0;
}
void push(Pilha *p){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->proximo=p->topo;//clona o topo antigo para o proximo da nova stutura que ta no topo
        novo->x=p->tam+1;//x recebe tamnho mais um
        p->topo=novo;//topo é atualizado para o endereço da nova estrutura que esta no topo
        p->tam++;//tamanho é atualizado
    }
    else
        printf("\nERRO AO ALOCAR MEMORIA!!!\n");
}
void pop(Pilha *p){
    if(p->topo){
        No *remover=p->topo;
        p->topo=remover->proximo;//topo recebe o proximo da pilha
        p->tam--;
        imprimir_numero(&remover->x);
        free(remover);
        remover=NULL;
    }
    else
        printf("\nPilha vazia\n");
}
void imprimir_pilha(Pilha *p){
    No *aux=p->topo;
    if(aux){
        printf("\n--- Pilha ---\n");
        while(aux){
            imprimir_numero(&aux->x);
            aux=aux->proximo;
        }
        printf("\n--- FIM PILHA ---\n");
    }
    else
        printf("\nPilha vazia\n");
}
Pilha copia_pilha(Pilha *p, Pilha *p2){ //ta errado
    Pilha *pilhaAux; //ajudar no processo
    criar_pilha(&pilhaAux);
    No *no=p->topo;
    //preenchendo a pilhaAux
    while(no){
        push(&pilhaAux);
        no=no->proximo;
    }
    while(pilhaAux->topo){
        No *noaux=pilhaAux->topo;
        push(&p2);
        pop(&pilhaAux);
    }
    free(pilhaAux);
    return *p2;
}
int main()
{
    Pilha p;//pilha 1
    Pilha p2;//pilha 2
    int opcao;
    criar_pilha(&p);
    criar_pilha(&p2);
    do{
        printf("\n0 - Sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n4 - copiar pilha\n");
        scanf("%d",&opcao);
        fflush(stdin);
        system("cls");
        switch(opcao){
            case 1:
                push(&p);
                break;
            case 2:
                pop(&p);
                break;
            case 3:
                imprimir_pilha(&p);
                break;
            case 4:
                p2=copia_pilha(&p,&p2);
                printf("Pilha Original\n");
                imprimir_pilha(&p);
                printf("Pilha Copia\n");
                imprimir_pilha(&p2);
                break;
            default:
                if(opcao!=0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;
}
