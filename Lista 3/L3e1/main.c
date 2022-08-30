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
    scanf("%49[^\n]%d%d%d",p.nome,&p.data.dia,&p.data.mes,&p.data.ano);
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


