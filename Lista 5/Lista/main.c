#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;

//inserir no inicio
void inserir_no_inicio(No **lista,int numero){
    No *novo=malloc(sizeof(No));
    if(novo){
         novo->valor=num;
         novo->proximo=*lista;
         *lista=novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
