#include <stdio.h>
#include <stdlib.h>
//ESTRUTURA NO
typedef struct no{
    int valor;
    struct no *esquerda, *direita;
    short altura;//short pq vou trabalhar com arvores pequenas se for muito grande trocar para int
}No;
//FUNCAO PARA Criar um NO
No* criarNo(int valor){
    No *novo=(No*)malloc(sizeof(No));
    if(novo==NULL)
        printf("Erro ao alocar memoria");
    else{
        novo->valor=valor;
        novo->esquerda=NULL;
        novo->direita=NULL;
        novo->altura=0;
    }
    return novo;
}
//maior sub arvore
short maior (short a, short b){
    return (a>b)?a:b;
}
//altura do no
short alturaNo(No *raiz){
    if(raiz==NULL)
        return -1;//altura da folha
    else
        return raiz->altura;
}
//Fator de balanceamento
short fatorBalanceamento(No *raiz){
    if(raiz==NULL)
        return 0;
    else
        return (alturaNo(raiz->esquerda)-alturaNo(raiz->direita));//valores 0,1,-1 significa que esta balanceado
}
//rortacao a esquerda
No* rotacaoEsquerda(No *r){//r e o no que foi indentificado como desbalanceado para a direita
    No *y,*f;

    y=r->direita;//y recebe o filho a direita de r
    f=y->esquerda;//f recebe o filho a esquerda de y

    y->esquerda=r;//y recebe r como filho a esquerda
    r->direita=f;//r recebe f como filho a direita

    r->altura=maior(alturaNo(r->esquerda),alturaNo(r->direita))+1;//atualiza a altura de r
    y->altura=maior(alturaNo(y->esquerda),alturaNo(y->direita))+1;//atualiza a altura de y
    return y;
}
//rotacao a direita
No* rotacaoDireita(No *r){//r e o no que foi indentificado como desbalanceado para a esquerda
    No *y,*f;

    y=r->esquerda;//y recebe o filho a esquerda de r
    f=y->direita;//f recebe o filho a direita de y

    y->direita=r;//y recebe r como filho a direita
    r->esquerda=f;//r recebe f como filho a esquerda

    r->altura=maior(alturaNo(r->esquerda),alturaNo(r->direita))+1;//atualiza a altura de r
    y->altura=maior(alturaNo(y->esquerda),alturaNo(y->direita))+1;//atualiza a altura de y
    return y;
}
//rotacao dupla
//rotacao direita esquerda
No* rotacaoDireitaEsquerda(No *r){//r ta desbalanceado para a direita mas nao completamenta 
    r->direita=rotacaoDireita(r->direita);//rotacao a direita
    return rotacaoEsquerda(r);//rotacao a esquerda
}
//rotacao esquerda direita
No* rotacaoEsquerdaDireita(No *r){//r ta desbalanceado para a esquerda mas nao completamenta 
    r->esquerda=rotacaoEsquerda(r->esquerda);//rotacao a esquerda
    return rotacaoDireita(r);//rotacao a direita
}
//inserir
No* inserir(No *raiz, int x){
    if(raiz==NULL)
        return criarNo(x);
    else{
        if(x<raiz->valor)
            raiz->esquerda=inserir(raiz->esquerda,x);
        else if (x>raiz->valor)
            raiz->direita=inserir(raiz->direita,x);
        else
            printf("Valor ja existe");
    }
    //atualiza a altura
    raiz->altura=maior(alturaNo(raiz->esquerda),alturaNo(raiz->direita))+1;
    //verifica se esta desbalanceado
    raiz=balancear(raiz);
    return raiz;
}
//balancear
//realiza o balanceamento da arvore apos uma insercao ou remocao
No* balancear(No *raiz){
    short fb=fatorBalanceamento(raiz);
    //rotacao a esquerda
    if(fb<-1 && fatorBalanceamento(raiz->direita<=0))
        raiz=rotacaoEsquerda(raiz);
    //rotacao a direita
    else if(fb>1 && fatorBalanceamento(raiz->esquerda>=0))
        raiz=rotacaoDireita(raiz);
    //rotacao dupla a esquerda
    else if(fb>1 && fatorBalanceamento(raiz->esquerda<0))
        raiz=rotacaoEsquerdaDireita(raiz);
    //rotacao dupla a direita
    else if(fb<-1 && fatorBalanceamento(raiz->direita>0))
        raiz=rotacaoDireitaEsquerda(raiz);
    return raiz;
}
//remover
No* remover(No *raiz, int chave){
    if(raiz==NULL){
        printf("Valor nao existe");
        return raiz;
    }else{//procura o valor
        if(raiz->valor==chave){
            //remove nos folhas
            if(raiz->esquerda==NULL && raiz->direita==NULL){
                free(raiz);
                printf("Valor removido");
                return NULL;
            }
            else{
                //remove nos com 2 filhos
                if(raiz->esquerda!=NULL && raiz->direita==NULL){
                    //vou trocar o valor a ser removido de lugar para ele virar um no com um filho ou sem filho
                    No *aux=raiz->esquerda;
                    while (aux->direita!=NULL)
                        aux=aux->direita;
                    raiz->valor=aux->valor;
                    aux->valor=chave;
                    printf("valor trocado");
                    raiz->esquerda=remover(raiz->esquerda,chave);
                    return raiz;
                }
                else{//remove nos com 1 filho
                    No *aux;
                    if(raiz->esquerda!=NULL)
                        aux=raiz->esquerda;
                    else
                        aux=raiz->direita;
                    free(raiz);
                    printf("Valor removido");
                    return aux;
                }
            }
        }else{
            if(chave<raiz->valor)
                raiz->esquerda=remover(raiz->esquerda,chave);
            else
                raiz->direita=remover(raiz->direita,chave);
        }
        //atualiza a altura
        raiz->altura=maior(alturaNo(raiz->esquerda),alturaNo(raiz->direita))+1;
        //verifica se esta desbalanceado
        raiz=balancear(raiz);
        return raiz;
    }

}
int main()
{

    return 0;
}
