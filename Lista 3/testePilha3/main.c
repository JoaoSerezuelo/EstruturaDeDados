#include <stdio.h>
#include <stdlib.h>
//Simulando recursão com Pilha
//fatorial

//pilha
typedef struct no{
    int valor;
    struct no *proximo;
}No;
No* push(No *pilha, int num){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->valor=num;
        novo->proximo=pilha;
        return novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
    return NULL;
}
No* pop(No **pilha){
    No *remover=NULL;
    if(*pilha){
        remover=*pilha;
        *pilha=remover->proximo;
    }
    else
        printf("Pilha vazia!\n");
    return remover;
}
void imprimir(No *pilha){
    printf("\n\tPILHA\n");
    while(pilha){
        printf("\t%i\n",pilha->valor);
        pilha=pilha->proximo;
    }
    printf("\n");
}

//fatorial
int fatorial(int num){
    No *remover,*pilha=NULL;

    while(num>1){
        pilha=push(pilha,num);
        num--;
    }
    imprimir(pilha);
    while(pilha){
        remover=pop(&pilha);
        num=num*remover->valor;
        free(remover);
        remover=NULL;
    }
    return num;
}
int main()
{
    int valor;
    printf("Digite um numero maior que 0 pra saber o fatorial: ");
    scanf("%i",&valor);
    printf("\tFatorial de %i: %i",valor,fatorial(valor));
    return 0;
}
