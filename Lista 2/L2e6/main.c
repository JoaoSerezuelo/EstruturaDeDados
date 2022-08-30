#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[10]="abcde";
    char *cptr=NULL;
    cptr=&s[0];
    while(*cptr != '\0')
        cptr++;
    cptr--;
    while(cptr >= s)
    {
        printf(" %c -", *cptr);
        cptr--;
    }
    return 0;
}
/*percori todo esse array até o fim da string que é o \0
depois só fui decrementando o ponteiro e printando a valor da posição de memoria
que ele aponta*/
