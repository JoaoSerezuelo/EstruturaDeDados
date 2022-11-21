#include <stdio.h>
#include <stdlib.h>
//Arvore binaria
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;
//inserir(&raiz,valor)
 void inserir(NoArv **raiz, int num){
    if(*raiz==NULL){//se a raiz for nula
        *raiz=malloc(sizeof(NoArv));//aloca memoria
        (*raiz)->valor=num;//atribui o valor
        (*raiz)->direita=NULL;//atribui NULL para a direita
        (*raiz)->esquerda=NULL;//atribui NULL para a esquerda
    }
    else{
        if(num<(*raiz)->valor){//se o valor for menor que o valor da raiz
            inserir(&((*raiz)->esquerda),num);//caminha para a esquerda
        }
        else//se o valor for maior que o valor da raiz
            inserir(&((*raiz)->direita),num);//caminha para a direita
    }
 }
//inserir2(&raiz,valor)
void inserir2(NoArv **raiz, int num){//versao eficiente
    NoArv *aux=*raiz;
    while(aux){//enquanto aux for diferente de NULL
        if(num<aux->valor)//se o valor for menor que o valor da raiz
            raiz=&aux->esquerda;//caminha para a esquerda
        else//se o valor for maior que o valor da raiz
            raiz=&aux->direita;//caminha para a direita
        aux=*raiz;//aux recebe o valor de raiz
    }
    aux=malloc(sizeof(NoArv));
    aux->valor=num;
    aux->esquerda=NULL;
    aux->direita=NULL;
    *raiz=aux;
}
//tipos impressao
/*exemplo arvore:
        50
    25      100
       30
*/
//PreOrdem(raiz)
void PreOrdem(NoArv *raiz){//Pre Ordenado ex:50 25 30 100
    if(raiz){//se raiz for diferente de NULL
        printf("%d | ",raiz->valor);//imprime o valor da raiz
        PreOrdem(raiz->esquerda);//caminha para a esquerda
        PreOrdem(raiz->direita);//caminha para a direita
    }
}
//EmOrdem(raiz)
void EmOrdem(NoArv *raiz){//Em ordem ex:25  30 50 100
    if(raiz){
        EmOrdem(raiz->esquerda);//caminha para a esquerda
        printf("%d | ",raiz->valor);//imprime o valor da raiz
        EmOrdem(raiz->direita);//caminha para a direita
    }
}
//PosOrdem(raiz)
void PosOrdem(NoArv *raiz){//Pos ordem ex:30 25 100 50
    if(raiz){
        PosOrdem(raiz->esquerda);//caminha para a esquerda
        PosOrdem(raiz->direita);//caminha para a direita
        printf("%d | ",raiz->valor);//imprime o valor da raiz
    }
}
//busca
//buscar_v1(raiz,valor)
NoArv* buscar_v1(NoArv *raiz, int num){//recursiva
    if(raiz){//se raiz for diferente de NULL
        if(num==raiz->valor)//se o valor for igual ao valor da raiz
            return raiz;//retorna a raiz
        else if(num<raiz->valor)//se o valor for menor que o valor da raiz
            return buscar_v1(raiz->esquerda,num);//caminha para a esquerda
        else//se o valor for maior que o valor da raiz
            return buscar_v1(raiz->esquerda,num);//caminha para a direita
    }
    else//se raiz for NULL
        return NULL;
}
int main()
{
    NoArv *raiz=NULL;
    NoArv busca;//se busca for igual a null nao foi encontrado
    int valor=10;
    inserir(&raiz,valor);
    inserir2(&raiz,valor);
    return 0;
}
