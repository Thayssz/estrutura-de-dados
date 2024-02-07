#include <stdio.h>
#include <stdlib.h>

typedef struct ingresso_{
    float preco;
    char local[50];
    char atracao[50];
}ingresso;

void preenche_ingresso(ingresso * i){
    printf("Digite o preco do ingresso:");
    scanf("%f", &i->preco);

    printf("Digite o local da atracao:");
    scanf(" %[^\n]", i->local);

    printf("Digite a atracao: ");
    scanf(" %[^\n]", i->atracao);

    printf("-----------------------");
    puts("");
}

void imprime_ingresso(const ingresso * i){
    printf("Preco do ingresso: %.2f \n Local da apresentacao: %s \n Atracao: %s\n", i->preco, i->local, i->atracao);
    printf("-----------------------");
    puts("");
}

void novo_preco(ingresso * i, float novo_valor){
    i->preco = novo_valor;
}

void maior_menor_preco(const ingresso ingressos[], int tamanho){
    int maior_preco = 0;
    int menor_preco = 0;

    for (int i = 1; i < tamanho; ++i) {
        if (ingressos[i].preco > ingressos[maior_preco].preco) {
            maior_preco = i;
        }

        else if (ingressos[i].preco < ingressos[menor_preco].preco) {
            menor_preco = i;
        }
    }

    printf("Ingresso com maior valor:\n");
    imprime_ingresso(&ingressos[maior_preco]);

    printf("\nIngresso com menor valor:\n");
    imprime_ingresso(&ingressos[menor_preco]);
}

int main(void){
    float valor;
    ingresso * ingresso1 = malloc(sizeof(ingresso));

    preenche_ingresso(ingresso1);
    printf("Informacoes do ingresso:\n");
    imprime_ingresso(ingresso1);

    printf("Altere o valor de um ingresso:\n");
    printf("Digite o novo valor:");
    scanf("%f", &valor);
    novo_preco(ingresso1, 50.00);
    printf("Informacoes do ingresso apos a alteracao de preco:\n");
    imprime_ingresso(ingresso1);

    ingresso ingressos[3];
    for (int i = 0; i < 3; i++){
        printf("Digite informacao para os ingressos:\n");
        preenche_ingresso(&ingressos[i]);
    }

    printf("Maior e menor preco dos ingressos:\n");
    maior_menor_preco(ingressos, 3);

    free(ingresso1);
    return 0;
}