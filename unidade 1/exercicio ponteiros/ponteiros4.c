#include <stdio.h>
#include <math.h>

void calcula_hexagono(float l, float *area, float *perimetro){
    *area = (3 *pow(l,2) * sqrt(3))/2;
    *perimetro = 6 * l;

}

int main(void){
    float area, perimetro, lado;
    printf("DIGITE O VALOR DO LADO DO HEXAGONO: ");
    scanf("%f", &lado);

    calcula_hexagono(lado, &area, &perimetro);

    printf("A AREA DO HEXAGONO E: %.2f\n", area);
    printf("O PERIMETRO DO HEXAGONO E: %.2f\n", perimetro);
}