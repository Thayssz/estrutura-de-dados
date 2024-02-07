#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union genero_{
    char masculino[20];
    char feminino[20];
}genero; 

typedef struct pessoa_{
    char nome[20];
    int idade;
    genero sexo;
}pessoa;

int main(void){
    pessoa p1;
    int opcao;

    printf("Digite seu nome:");
    scanf("%[^\n]", p1.nome);

    printf("Digite sua idade:");
    scanf("%d", &p1.idade);

    printf("Escolha a opcao de genero: \n 0 - masculino \n 1 - feminino\n");
    scanf("%d", &opcao);

    if(opcao==0){
        strcpy(p1.sexo.masculino, "MASCULINO");
    }
    else if(opcao==1){
        strcpy(p1.sexo.feminino, "FEMININO");
    }
   
    printf("Nome: %s \t Idade: %d \t Genero: %s", p1.nome, p1.idade, opcao==0?"MASCULINO":"FEMININO");

    return 0;
}