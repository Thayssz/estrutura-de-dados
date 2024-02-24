#include <stdio.h>

int main(void){
    int i;
    int vet[10];
    int menor, maior;
    int comp;
    double soma = 0;
    double media;
    FILE *arq1;
    FILE *arq2;

    if((arq1 = fopen("entrada_q2.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }

    if((arq2 = fopen("saida_q2.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo");
    }
    else{
        while(!feof(arq1)){
            for(i=0; i<10; i++){
                fscanf(arq1, "%d", &vet[i]);
            }
        }
        menor = vet[0];
        maior = vet[0];
        for(i=0; i<10; i++){
            soma += vet[i];
            comp = vet[i];

            if(maior < comp){
                maior = comp;
            }

            if(menor > comp){
                menor = comp;
            }
        }
        media = soma/10;
        fprintf(arq2, "menor elemento: %d\nmaior elemento: %d\nmedia dos elementos: %.6lf", menor, maior, media);
    }
}