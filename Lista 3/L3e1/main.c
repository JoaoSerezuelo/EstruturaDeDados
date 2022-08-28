#include <stdio.h>
#include <stdlib.h>

//Structs
typedef struct{
   int dia, mes, ano;
}Data;
typedef struct{
    char nome[50];
    Data data;
}Pessoa;
typedef struct no{
    Pessoa p;
    struct no *proximo;
}No;

//Funções Pessoa
Pessoa ler_pessoa(){
    Pessoa p;
    printf("\nDigite nome e data de nascimento dd mm aaaa:\n");
    scanf("%49[^\n]%d%d%d",p.nome,&p.data.dia,&p.data.mes,&p.data.ano);
    return p;
}
void imprimir_pessoa(Pessoa p){
    printf("\nNome: %s\nData: %2d/%2d/%4d\n", p.nome, p.data.dia, p.data.mes, p.data.ano);
}


int main()
{
    No *topo=NULL;
    int opcao;

    do{
        //printf()
    }while(opcao!=1);

    return 0;
}
