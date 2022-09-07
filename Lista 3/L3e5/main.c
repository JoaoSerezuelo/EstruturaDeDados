#include <stdio.h>
#include <stdlib.h>
#include <locale.h>//acentuar

typedef struct{
    float numero;
    char operacao;
}Conta;
//No
typedef struct no{
    Conta x;
    struct no *proximo;
}No;
//Pilha
typedef struct {
    No *topo;
}Pilha;

//Leitura conta
Conta calculadora(){
    Conta c;
    printf("\nOperações e seus códigos\n+ | SOMA\n- | SUBTRACAO\n* | MULTIPLICACAO\n/ | DIVISAO\n");
    printf("Operação escolhida: ");
    scanf("%c",&c.operacao);
    printf("Número:  ");
    scanf("%f",&c.numero);
    return c;
}
void imprimir_conta(Conta c){
    printf(" %c  %f ",c.operacao,c.numero);
}

//Pilha
//criando
void criar_pilha(Pilha *p){
    p->topo=NULL;
}
//push
void push(Pilha *p){
    No *novo=malloc(sizeof(No));
    if(novo){
        novo->x=calculadora();
        novo->proximo=p->topo;
        p->topo=novo;
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
}
//pop
No* pop(Pilha *p){
    if(p->topo){
        No *remover=p->topo;
        p->topo=remover->proximo;
        return remover;
    }
    else
        printf("\nPILHA VAZIA!\n");
    return NULL;
}

/*Percori a Pilha toda atraves de um No auxiliar e fui fazendo as operações
com os seus respectivos números que foram inseridos pelo usuario*/
float resultado_conta(Pilha *p){
    No *aux=p->topo;
    printf("0 ");
    float resultado=0.0;
    while(aux){
        imprimir_conta(aux->x);
        if(aux->x.operacao=='+')
            resultado=resultado+aux->x.numero;
        if(aux->x.operacao=='-')
            resultado=resultado-aux->x.numero;
        if(aux->x.operacao=='*')
            resultado=resultado*aux->x.numero;
        if(aux->x.operacao=='/')
            resultado=resultado/aux->x.numero;
        aux=aux->proximo;
    }
    return resultado;
}

int main()
{
    setlocale(LC_ALL,"");//acentuação
    No *remover;
    Pilha p;
    float resultado=0.0;
    int opcao;
    criar_pilha(&p);

    do{
        printf("1 - adicionar operação\n2- resultado\n");
        scanf("%d",&opcao);
        system("cls");
        getchar();
        switch(opcao){
            case 1:
                push(&p);
                system("cls");
                break;
            case 2:
                resultado=resultado_conta(&p);
                break;
            default:
                    printf("\nOpção inválida!\n");
        }
    }while(opcao!=2);
    printf("\nRESULTADO = %f",resultado);
    //livrar memoria
    while(p.topo){
        remover=pop(&p);
        free(remover);
        remover=NULL;
    }
    return 0;
}
/*fui empilhando as operações e numeros que o usuario queria enquanto ele desejase
empilhar (adicionar operação) depois quando ele deseja-se solicitar o resultado
fui percorendo toda a pilha do topopara a base atraves de um No auxiliar e retornei
o resultado*/
