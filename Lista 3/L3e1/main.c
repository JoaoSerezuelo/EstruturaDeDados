#include <stdio.h>
#include <stdlib.h>

//Structs Pessoa
typedef struct{
   int dia, mes, ano;
}Data;
typedef struct{
    char nome[50];
    Data data;
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

void limparBuffer() {
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){}
}

//Funções Pessoa
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%s", p.nome);
    limparBuffer();
    scanf("%d%d%d",&p.data.dia,&p.data.mes,&p.data.ano);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
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
    No *novo2=malloc(sizeof(No));
    if(novo2){
        novo2-> p = ler_pessoa();//ler pessoa
        novo2-> proximo = p->topo;//clona o topo antigo para o proximo da nova stutura que ta no topo
        p->topo = novo2;//topo é atualizado para o endereço da nova estrutura que esta no topo
        p->tam++;//tamanho da pilha é atualizado
    }
    else
        printf("\nErro ao alocar memoria!!!\n");
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
//pop
void pop(Pilha *p){

    int quantidade = 2;

    if(p->topo) {

        while(quantidade !=0) {
            No *remover = p->topo;//remover recebe o topo da pilha
            p->topo = remover->proximo;//topo da pilha recebe o proximo da pilha(posição da estrutura que está embaixo)
            p->tam--;//tamanho da pilha é atualizado
            printf("\nelemento %s removido com sucesso\n", remover->p.nome);
            free(remover);
            quantidade--;
        }
    }
    else
        printf("\nPilha vazia!\n");
}

int main()
{

    Pilha p;//pilha
    int opcao;

    criar_pilha(&p);

    do{
        printf("\n0 - Sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");
        scanf("%d",&opcao);
        fflush(stdin);
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
            default:
                if(opcao!=0)
                    printf("\nOpcao invalida!\n");
        }
    }while(opcao!=0);

    return 0;
}
