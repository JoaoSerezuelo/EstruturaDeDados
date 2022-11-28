#include <stdio.h>
#include <stdlib.h>
//Arvore binaria
typedef struct no{
    int valor;
    struct no *direita, *esquerda;
}NoArv;
//inserir(&raiz,valor)
 void inserir(NoArv **raiz, int num){//versao recursiva e menos eficiente
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
//buscar_v2(raiz,valor)
NoArv* buscar_v2(NoArv *raiz, int num){//mais eficiente
    while(raiz){
        if(num<raiz->valor)//se o valor for menor que o valor da raiz
            raiz=raiz->esquerda;//caminha para a esquerda
        else if(num>raiz->valor)//se o valor for maior que o valor da raiz
            raiz=raiz->direita;//caminha para a direita
        else//se o valor for igual ao valor da raiz
            return raiz;//retorna a raiz
    }
    return NULL;
}
//quantidade de Nos -
//quantidadeNos(raiz);
int quantidadeNos(NoArv *raiz){
    if(raiz==NULL)//se raiz for nula
        return 0;//retorna 0
    else//se raiz for diferente de nula
        return 1+quantidadeNos(raiz->esquerda)+quantidadeNos(raiz->direita);//vai contar a quantidade de nos da esquerda e da direita com recursividade
    //podia usar ternariio
    //return(raiz==null)?0:1+quantidadeNos(raiz->esquerda)+quantidadeNos(raiz->direita);
}
//quantidade de folhas
int quantidadeFolhas(NoArv *raiz){
    if(raiz==NULL)//se raiz for nula
        return 0;//retorna 0 para a soma
    else if(raiz->esquerda==NULL && raiz->direita==NULL)//e uma folha
        return 1;//retorna 1 para a soma
    else
        return quantidadeFolhas(raiz->esquerda)+quantidadeFolhas(raiz->direita);//soma com recursividade
}
//altura
int altuara(NoArv *raiz){
   if(raiz==NULL)
        return -1;
   else{
        int esq=altuara(raiz->esquerda);
        int dir=altuara(raiz->direita);
        if(esq>dir)
            return esq+1;
        else
            return dir+1;
   }
}
//remocao
NoArv* remover(NoArv *raiz, int chave){
    if(raiz==NULL){
        printf("valor nao encontrado!\n");
        return NULL;
    }
    else{//procura no a ser removido
        if(raiz->valor==chave){
            //remove nos folhas
            if(raiz->esquerda==NULL && raiz->direita==NULL){
                free(raiz);
                printf("Elemento folha removido: %d!\n",chave);
                return NULL;
            }
            else{
                //remove nos que possuem um 1 ou 2 filhos
            }
        }
        else{
            if(chave<raiz->valor)
                raiz->esquerda=remover(raiz->esquerda,chave);
            else
                raiz->direita=remover(raiz->direita,chave);
            return raiz;
        }
    }
}

int main()
{
    NoArv *raiz=NULL;
    NoArv *busca;//se busca for igual a null nao foi encontrado
    int valor, op;
    //fazer interativa
    do{
        printf("\n0 - sair\n1 - inserir\n2 - PreOrdem\n3 - EmOrdem\n4 - PosOrdem\n5 - buscar\n6 - qtd nos\n7 - qtd folhas\n8 - altura\n9 - remover\n");
        scanf("%d",&op);
        switch(op){
            case 1:
                printf("Digite um valor: ");
                scanf("%d",&valor);
                inserir2(&raiz,valor);
                break;
            case 2:
                printf("pre ordem: ");
                PreOrdem(raiz);
                printf("\n");
                break;
            case 3:
                printf("Em ordem: ");
                EmOrdem(raiz);
                printf("\n");
                break;
            case 4:
                printf("pos ordem: ");
                PosOrdem(raiz);
                printf("\n");
                break;
            case 5:
                printf("digite valor a ser procurado: ");
                scanf("%d",&valor);
                busca=buscar_v2(raiz,valor);
                if(busca)
                    printf("valor encontrado: %d\n",busca->valor);
                else
                    printf("valor n�o encontrado\n");
                break;
            case 6:
                printf("qtd de nos: %d\n",quantidadeNos(raiz));
                break;
            case 7:
                printf("qtd folhas: %d\n",quantidadeFolhas(raiz));
                break;
            case 8:
                printf("altura arvore: %d\n",altuara(raiz));
                break;

            case 9:
                printf("Elemento arvore: ");
                EmOrdem(raiz);
                printf("\nDigite o valor a ser removido: ");
                scanf("%d",&valor);
                raiz=remover(raiz,valor);
                break;
            default:
                if(op!=0)
                    printf("op invalida\n");
        }

    }while(op!=0);
    return 0;
}
