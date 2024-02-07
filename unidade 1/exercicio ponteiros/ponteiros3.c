#include <stdio.h>

int main(void) {
 int a, b, c, d;
 int *p1;
 int *p2 = &a; //p2 recebe o endereço de a
 int *p3 = &c; // p3 recebe o endereço de c
 p1 = p2; // p1 recebe o endereço que p2 está guardando, no caso o endereço de a
 *p2 = 10; // o conteúdo do endereço que p2 está guadando recebe 10, no caos a variavel a agora tem valor 10
 b = 20; // b recebe 20 como valor
 int **pp; // declaração de um ponteiro de ponteiro
 pp = &p1; // ponteiro pp recebe o endereço do ponteiro p1
 *p3 = **pp; // o conteúdo do endereço que p3 está guardando recebe o conteúdo do conteúdo que pp está guardando, no caso a variável c recebe o valor de a
 int *p4 = &d; // declaração de um novo ponteiro e atribuição do endereço de d a ele
 *p4 = b + (*p1)++; // o conteúdo do endereço que p4 guarda, no caso a variável d, recebe o valor de b mais o conteúdo do endereço que p1 guarda, ficando 20 + 10, em seguinda o conteúdo de p1 é incrementado uma vez, por isso o incremento entra no valor de d, se o incremento fosse feito antes, o valor de d seria 31
 // a = 11; b = 20; c = 10; d = 30;
 printf("%d\t%d\t%d\t%d\n", a, b, c, d);
 return 0;
}