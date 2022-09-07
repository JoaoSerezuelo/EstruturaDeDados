#include <stdio.h>
#include <stdlib.h>

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

//Fun��es Pessoa
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%s", p.nome);
    fflush(stdin);
    scanf("%d%d%d",&p.data.dia,&p.data.mes,&p.data.ano);
    fflush(stdin);
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
        p->topo = novo;//topo � atualizado para o endere�o da nova estrutura que esta no topo
        p->tam++;//tamanho da pilha � atualizado
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
void popn(Pilha *p, int quantidade){

    while(quantidade != 0) {
        No *remover = p->topo;//remover recebe o topo da pilha
        p->topo = remover->proximo;//topo da pilha recebe o proximo da pilha(posi��o da estrutura que est� embaixo)
        p->tam--;//tamanho da pilha � atualizado
        printf("elemento %s removido com sucesso\n", remover->p.nome);
        free(remover);
        quantidade--;
    }
}


int main()
{
    Pilha p;//pilha
    int opcao,quantidade;

    criar_pilha(&p);

    do{
        printf("\n0 - Sair\n1 - empilhar\n2 - desempilhar\n3 - imprimir\n");
        scanf("%d",&opcao);
        fflush(stdin);
        system("cls");
        switch(opcao){
            case 1:
                push(&p);
                break;
            case 2:
                printf("numero de elementos que deseja desempilhar: ");
                scanf("%i",&quantidade);
                if(quantidade<=p.tam)
                    popn(&p,quantidade);
                else
                    printf("quantidade inserida maior do que a de numeros empilhados\n");
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
//fiz a mesma ideia do exercicio 1 s� que agora alteei a
//fun��o pop para tirar n numeros escolhidos pelo usuario
