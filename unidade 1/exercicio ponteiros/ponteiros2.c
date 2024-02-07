#include <stdio.h>

int main(void) {
    int x, *p;
    x = 100;
    p = &x;
    printf("Valor de p = %p Valor de *p = %d", p, *p);
}
// a. ADVERTENCIA, AINDA QUE O CÓDIGO NÃO ESTEJA EM CONFORMIDADE, O COMPILADOR AINDA TENTA GERAR O ARQUIVO EXECUTAVEL
// b. PORQUE NÃO É POSSÍVEL ATRIBUIR UMA VARIÁVEL INTEIRA A UM PONTEIRO PARA INTEIRO
// c. NÃO
// d. CÓDIGO MODIFICADO ACIMA 
// e. SIM, A EXECUÇÃO FOI BEM SUCEDIDA