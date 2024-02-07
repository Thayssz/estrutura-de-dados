#include <stdio.h>
#include <string.h>

typedef struct Pessoa {
    char nome[50];
    int documento;
    int idade;
} pessoa;

void preencherPessoa(pessoa *pessoa) {
    printf("Digite o nome da pessoa: ");
    scanf("%s", pessoa->nome);

    printf("Digite o numero do documento da pessoa: ");
    scanf("%d", &pessoa->documento);

    printf("Digite a idade da pessoa: ");
    scanf("%d", &pessoa->idade);
}

void imprimirPessoa(const pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Documento: %d\n", pessoa->documento);
    printf("Idade: %d\n", pessoa->idade);
}

void atualizarIdade(pessoa *pessoa, int novaIdade) {
    pessoa->idade = novaIdade;
}

void maisVelhaMaisNova(const pessoa pessoas[], int tamanho) {
    int maisVelha = 0, maisNova = 0;

    for (int i = 1; i < tamanho; ++i) {
        if (pessoas[i].idade > pessoas[maisVelha].idade) {
            maisVelha = i;
        }
        if (pessoas[i].idade < pessoas[maisNova].idade) {
            maisNova = i;
        }
    }

    printf("Pessoa mais velha:\n");
    imprimirPessoa(&pessoas[maisVelha]);

    printf("\nPessoa mais nova:\n");
    imprimirPessoa(&pessoas[maisNova]);
}

int main() {

    pessoa pessoa1;
    preencherPessoa(&pessoa1);
    printf("\nInformacoes da pessoa:\n");

    imprimirPessoa(&pessoa1);


    atualizarIdade(&pessoa1, 30);
    printf("\nInformacoes da pessoa apos atualizacao de idade:\n");

    imprimirPessoa(&pessoa1);

    struct Pessoa pessoas[3];
    for (int i = 0; i < 3; ++i) {
        printf("\nDigite informacoes para a pessoa %d:\n", i + 1);
        preencherPessoa(&pessoas[i]);
    }

    printf("\nMais velha e mais nova entre as pessoas:\n");
    maisVelhaMaisNova(pessoas, 3);

    return 0;
}
