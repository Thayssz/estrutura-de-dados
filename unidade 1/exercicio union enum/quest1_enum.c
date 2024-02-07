#include <stdio.h>
#include <stdlib.h>

typedef enum genero_{
    masculino, 
    feminino
}genero;

typedef struct pessoa_{
    char nome [20];
    int idade;
    genero sexo;
}pessoa;

void preenche_pessoa(pessoa * pessoa){
    printf("Digite seu nome:");
    scanf(" %[^\n]", pessoa->nome);

    printf("Digite sua idade:");
    scanf("%d", &pessoa->idade);

    printf("Escolha a opcao de genero: \n 0 - masculino \n 1 - feminino\n");
    scanf("%d", &pessoa->sexo);
}

void imprime_pessoa(pessoa * pessoa){
    printf("Nome: %s \n Idade: %d \n Genero: %s", pessoa->nome, pessoa->idade, (pessoa->sexo==masculino)?"MASCULINO":"FEMININO");
}

int main(void){
    pessoa * p1 = malloc(sizeof(pessoa));

    preenche_pessoa(p1);
    imprime_pessoa(p1);

    free(p1);
    return 0;
}