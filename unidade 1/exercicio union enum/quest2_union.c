#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union tipo_{
    char alimento[20];
    char bebida[20];
    char eletronico[20];
}tipo;

typedef struct produto_{
    char nome[20];
    float preco;
    tipo tipo;
}produto;

int main(void){
    produto produto1;
    int opcao;

    printf("Digite o nome do produto:");
    scanf("%[^\n]", produto1.nome);

    printf("Digite o preço do produto: ");
    scanf("%f", &produto1.preco);

    printf("Digite o tipo do produto: \n 0 - Alimento \n 1 - Bebida \n 3 - Eletronico");
    scanf("%d", &opcao);

    if(opcao==0){
        strcpy(produto1.tipo.alimento, "ALIMENTO");
    }
    else if(opcao==1){
        strcpy(produto1.tipo.bebida, "BEBIDA");
    }
    else if(opcao==2){
        strcpy(produto1.tipo.eletronico, "ELETRONICO");
    }

    printf("Nome do produto: %s \n Preco do produto: %.2f\n", produto1.nome, produto1.preco);

    if(opcao==0){
        printf("Tipo do produto: %s", produto1.tipo.alimento);
    }
    else if(opcao==1){
        printf("Tipo do produto: %s", produto1.tipo.bebida);
    }
    else if(opcao==2){
        printf("Tipo do produto: %s", produto1.tipo.eletronico);
    }

    return 0;
}