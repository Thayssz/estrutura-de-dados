#include <stdio.h>

int main(void){
    int x, y, *p;

    y = 0;
    p = &y;
    x = *p;
    // x = 0. y = 0. p = endereço de y.
    x = 4;
    (*p)++; // o conteúdo do endereço que p guarda, que no caso é y, é incrementado uma vez, ficando com o valor atual de 1
    --x; // x que atualmente tem o valor 4, é decrementado uma vez, ficando com o valor atual 3
    (*p) += x; // o conteúdo do endereço que p guarda, no caso y, é incrementado com o valor atual de x, que é 3, assim ficando 1 + 3, resultando no valor final de y = 4, e x = 3, o ponteiro p, por sua vez, segue guardando o endereço da variável y. 

    printf("x = %d.\n", x);
    printf("y = %d. Endereco de y: %p\n", y, &y);
    printf("p = %p. *p = %d", p, *p);
}