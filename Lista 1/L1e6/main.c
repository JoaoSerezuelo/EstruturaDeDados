#include <stdio.h>
#include <stdlib.h>

/*O m�ximo divisor comum dos inteiros x e y � o maior inteiro que
� divis�vel por x e y. Escreva uma fun��o recursiva mdc em C,
que retorna o m�ximo divisor comum de x e y. O mdc de x e y �
definido como segue: se y � igual a 0, ent�o mdc(x,y) � x; caso
contr�rio, mdc(x,y) � mdc (y, x%y), onde % � o operador resto.*/
 int mdc( int x,int y){
     int aux;
     if(y==0)
        return x;
    else{
        aux=mdc(y,x%y);
        return aux;
    }
 }
/*usei a formula fornecida delo enunciado de forma recursiva a at� chegar no caso basse informado pelo mesmo*/

int main (){
    int x,y;
    printf("escreva 2 numeros inteiros para ver seu maximo divisor comum\n 1- ");
    scanf("%i",&x);
    printf("2- ");
    scanf("%i",&y);
    printf("o mdc e: %i",mdc(x,y));
    return 0;
}
