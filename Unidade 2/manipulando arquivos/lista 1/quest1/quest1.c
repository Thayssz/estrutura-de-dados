#include <stdio.h>

int main(void){
    double nota1, nota2, nota3;
    double media;
    char name[100];
    char tam[100];
    FILE *arq1;
    FILE *arq2;

    if((arq2 = fopen("saida_q1.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }

    if((arq1 = fopen("entrada_q1.txt", "r")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
    else{
        while((fgets(tam, 100, arq1)) != NULL){
            sscanf(tam, "%15[^\t]\t%lf\t%lf\t%lf", name, &nota1, &nota2, &nota3);
            media = (nota1 + nota2 + nota3)/3;

            fprintf(arq2, "%s\t %.1lf\t %s\n", name, media, (media >=7)?"Aprovado":"Reprovado");
        }
        fclose(arq1);
        fclose(arq2);
    }
    return 0;
}