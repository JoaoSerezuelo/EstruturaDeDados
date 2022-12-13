#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//arvore k-d
  

int main()
{
    char comando[200];
    int tamanho;
    printf("Bem vindo ao J seu gerenciador de arquivos\n");
    printf("comandos acabam com ;\n");
    printf("\n Escreva 'help;' para obter uma lista de comandos. Escreva 'clear;' para limpar a tela.\n");
    do{
        printf("J> ");
        setbuf(stdin, NULL);//limpa o buffer do teclado
        scanf("%c", &comando);
        tamanho = strlen(comando);
        strlwr(comando);//transforma a string em minuscula
    }while (comando != 'exit;');
    return 0;
}
