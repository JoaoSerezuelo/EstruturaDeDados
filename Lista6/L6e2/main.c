#include <stdio.h>
#include <stdlib.h>

//lista duplamente encadeada
typedef struct no{
    int valor;
    struct no *proximo;
    struct no *anterior;
}No;

// procedimento para inserir no in�cio
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;// atribui o valor ao no
        novo->proximo = *lista;// aponta para o primeiro no
        novo->anterior= NULL;// aponta para NULL pq o anterior do primeiro no e null
        if(*lista){// se a lista nao estiver vazia
            (*lista)->anterior = novo;// o anterior do antigo primeiro no aponta para o novo no
        }
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;// atribui o valor ao no
        novo->proximo = NULL;// aponta para NULL pq o proximo do ultimo no e null

        // � o primeiro?
        if(*lista == NULL){//sim
            *lista = novo;// o primeiro no aponta para o novo no
            novo->anterior=NULL;// o anterior do novo no aponta para NULL pq o anterior do primeiro no e null
        }
        else{//nao
            aux = *lista;// aux aponta para o primeiro no
            while(aux->proximo)// enquanto o proximo do aux nao for NULL
                aux = aux->proximo;// aux aponta para o proximo no
            aux->proximo = novo;// o proximo do ultimo no aponta para o novo no
            novo->anterior=aux;// o anterior do novo no aponta para o ultimo no
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;// atribui o valor ao no
        // � o primeiro?
        if(*lista == NULL){//sim
            novo->proximo = NULL;// aponta para NULL pq o proximo do ultimo no e null
            novo->anterior=NULL;// aponta para NULL pq o anterior do primeiro no e null
            *lista = novo;// o primeiro no aponta para o novo no
        }
        else{//nao
            aux = *lista;// aux aponta para o primeiro no
            while(aux->valor != ant && aux->proximo)// enquanto o valor do aux for diferente do valor do no anterior e o proximo do aux nao for NULL
                aux = aux->proximo;// aux aponta para o proximo no
            novo->proximo = aux->proximo;// o proximo do novo no aponta para o proximo do no anterior
            aux->proximo->anterior=novo;// o anterior do proximo do no anterior aponta para o novo no
            novo->anterior=aux;// o anterior do novo no aponta para o no anterior
            aux->proximo = novo;// o proximo do no anterior aponta para o novo no
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;// atribui o valor ao no
        // a lista est� vazia?
        if(*lista == NULL){//sim
            novo->proximo = NULL;// aponta para NULL pq o proximo do ultimo no e null
            novo->anterior=NULL;// aponta para NULL pq o anterior do primeiro no e null
            *lista = novo;// o primeiro no aponta para o novo no
        } // � o menor?
        else if(novo->valor < (*lista)->valor){//sim
            novo->proximo = *lista;// o proximo do novo no aponta para o primeiro no
            (*lista)->anterior=novo;// o anterior do primeiro no aponta para o novo no
            *lista = novo;// o primeiro no aponta para o novo no
        }
        else{
            aux = *lista;// aux aponta para o primeiro no
            while(aux->proximo && novo->valor > aux->proximo->valor)// enquanto o proximo do aux nao for NULL e o valor do novo no for maior que o valor do proximo do aux
                aux = aux->proximo;// aux aponta para o proximo no
            novo->proximo = aux->proximo;// o proximo do novo no aponta para o proximo do aux
            if(aux->proximo)// se o proximo do aux nao for NULL
                aux->proximo->anterior=novo;// o anterior do proximo do aux aponta para o novo no
            novo->anterior=aux;// o anterior do novo no aponta para o aux
            aux->proximo = novo;// o proximo do aux aponta para o novo no
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){// se a lista nao estiver vazia
        if((*lista)->valor == num){// se o primeiro no for o no a ser removido
            remover = *lista;// remover aponta para o primeiro no
            *lista = remover->proximo;// o primeiro no aponta para o proximo do no a ser removido
            if(*lista)// se o primeiro no nao for NULL
                (*lista)->anterior=NULL;// o anterior do primeiro no aponta para NULL
        }
        else{// se o primeiro no nao for o no a ser removido
            aux = *lista;// aux aponta para o primeiro no
            while(aux->proximo && aux->proximo->valor != num)// enquanto o proximo do aux nao for NULL e o valor do proximo do aux for diferente do valor do no a ser removido
                aux = aux->proximo;// aux aponta para o proximo no
            if(aux->proximo){// se o proximo do aux nao for NULL
                remover = aux->proximo;// remover aponta para o proximo do aux
                aux->proximo = remover->proximo;// o proximo do aux aponta para o proximo do no a ser removido
                if(aux->proximo)// se o proximo do aux nao for NULL
                    aux->proximo->anterior=aux;// o anterior do proximo do aux aponta para o aux

            }
        }
    }
    return remover;
}

No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;// aux aponta para o primeiro no
    while(aux && aux->valor != num)// enquanto aux nao for NULL e o valor do aux for diferente do valor do no a ser buscado
        aux = aux->proximo;// aux aponta para o proximo no
    if(aux)// se aux nao for NULL
        no = aux;// no aponta para o aux
    return no;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){// enquanto no nao for NULL
        printf("%d ", no->valor);// imprime o valor do no
        no = no->proximo;// no aponta para o proximo no
    }
    printf("\n\n");
}

No* ultimo(No **lista){
    No *aux=*lista;// aux aponta para o primeiro no
    while(aux->proximo){// enquanto o proximo do aux nao for NULL
        aux=aux->proximo;// passa para o proximo no
    }
    return aux;
}
void imprimir_contrario(No *no){

    printf("\n\tLista: ");
    while(no){// enquanto no nao for NULL
        printf("%d ", no->valor);// imprime o valor do no
        no = no->anterior;// no aponta para o anterior no
    }
    printf("\n\n");
}
int main(){

    int opcao, valor, anterior;// variaveis para armazenar a opcao do menu, o valor a ser inserido e o valor anterior ao valor a ser inserido
    No *removido, *lista = NULL;// ponteiro para o no removido e ponteiro para o primeiro no da lista

    do{
        printf("\n\t0 - Sair\n\t1 - Inserir Inicio\n\t2 - inserir Final\n\t3 - Inserir Meio\n\t4 - Inserir Ordenado\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n8 - imprimir ao contrario\n");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:// inserir no inicio
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:// inserir no final
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:// inserir no meio
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:// inserir ordenado
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:// remover
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:// imprimir
            imprimir(lista);
            break;
        case 7:// buscar
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
        case 8:// imprimir ao contrario
            imprimir_contrario(ultimo(&lista));
            break;
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}
