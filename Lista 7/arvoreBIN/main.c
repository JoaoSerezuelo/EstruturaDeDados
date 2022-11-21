#include <stdio.h>
#include <stdlib.h>
//Arvore binaria
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

 NoArv* inserir_versao1(NoArv *raiz, int num){
    if(raiz==NULL){
        NoArv *aux=malloc(sizeof(NoArv));//como so vou trabalhar com arvores pequenas nao vou verificar se foi alocado
        aux->valor=num;
        aux->direita=NULL;
        aux->esquerda=NULL;
        return aux;
    }else{
        if(num<raiz->valor){
            raiz->esquerda=inserir_versao1(raiz->esquerda,num);
        }
        else{
            raiz->direita=inserir_versao1(raiz->direita,num);
        }
        return raiz;
    }
 }

int main()
{
    NoArv *raiz=NULL;

    return 0;
}
