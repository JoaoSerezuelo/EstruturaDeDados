#include <stdio.h>
#include <stdlib.h>
//Arvore binaria
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;

 void inserir_versao2(NoArv **raiz, int num){
    if(*raiz==NULL){//primeiro no
        *raiz=malloc(sizeof(NoArv));
        (*raiz)->valor=num;
        (*raiz)->direita=NULL;
        (*raiz)->esquerda=NULL;
    }
    else{
        if(num<(*raiz)->valor){
            inserir_versao2(&((*raiz)->esquerda),num);
        }
        else
            inserir_versao2(&((*raiz)->direita),num);
    }
 }
//tipos impressao
/*exemplo arvore:
        50
    25      100
       30
*/
void PreOrdem(NoArv *raiz){//Pre Ordenado ex:50 25 30 100
    if(raiz){
        printf("%d | ",raiz->valor);
        PreOrdem(raiz->esquerda);
        PreOrdem(raiz->direita);
    }
}

void EmOrdem(NoArv *raiz){//Em ordem ex:25  30 50 100
    if(raiz){
        EmOrdem(raiz->esquerda);
        printf("%d | ",raiz->valor);
        EmOrdem(raiz->direita);
    }
}
int main()
{
    NoArv *raiz=NULL;
    int valor=10;
    inserir_versao2(&raiz,valor);
    return 0;
}
