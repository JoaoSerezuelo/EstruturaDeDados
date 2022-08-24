#include <stdio.h>
#include <stdlib.h>

int main()
{
     int x, *p, **q;
     p = &x;
     q = &p;
     x = 10;
     // jeito errado --> printf("\n%d\n", &q); // escreve o endere�o  de X
     printf("\n%d\n", **q); // escreve o conteudo de X
    return 0;

}
