#include <stdio.h>
#include <stdlib.h>

typedef enum meses_{
    janeiro=1,
    fevereiro,
    marco,
    abril,
    maio,
    junho,
    julho,
    agosto,
    setembro,
    outubro,
    novembro,
    dezembro
}mes;

typedef struct data_{
    int dia;
    mes mes;
    int ano;
}data;

void preenche_data(data * data){
    printf("Digite o dia:");
    scanf("%d", &data->dia);

    printf("Digite o mes usando dois digitos:");
    scanf("%d", &data->mes);

    printf("Digite o ano:");
    scanf("%d", &data->ano);
}

void imprime_data(data * data){
    printf("%d/%02d/%d", data->dia, data->mes, data->ano);
}

int main(void){
    data * num = malloc(sizeof(data));

    preenche_data(num);
    imprime_data(num);

    free(num);
    return 0;
}
