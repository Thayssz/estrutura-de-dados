#include <stdio.h>
#include <stdlib.h>

#define ALUNOS 10

void resultado(char *gabarito, char **alunos, int total_quest){
    float nota = 0;
    float acertos = 0;
    float aprovados = 0;

    printf("Nota dos alunos:\n");
    for (int i = 0; i < ALUNOS; i++){
        nota = 0;
        acertos = 0;
        for (int j = 0; j < total_quest; j++){
            if (alunos[i][j] == gabarito[j]){
                acertos++;
            }
        }

        nota = acertos / total_quest * 10;
        printf("Aluno %d:  %.2f\n", i + 1, nota);

        if (nota >= 6.0){
            aprovados++;
        }
    }

    float porcentagem_aprovados = (aprovados / ALUNOS) * 100;
    printf("Porcentagem de aprovados: %.2f %%", porcentagem_aprovados);
}

int main(void){

    int total_quest;

    printf("Insira o total de questoes: ");
    scanf("%d", &total_quest);

    char *gabarito = (char *)malloc(total_quest * sizeof(char));
    char **alunos = (char **)malloc(10 * sizeof(char *));

    for (int i = 0; i < 10; i++){
        alunos[i] = (char *)malloc(total_quest * sizeof(char));
        if (alunos[i] == NULL){
            printf("ERRO DE ALOCAÇÃO DE MEMORIA\n");
            exit(1);
        }
    }

    if (gabarito == NULL){
        printf("ERRO DE ALOCAÇÃO DE MEMORIA\n");
        exit(1);
    }

    printf("Gabarito da prova:\n");

    for (int i = 0; i < total_quest; i++){

        printf("Insira o gabarito da questao %d: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    printf("\n");

    for (int i = 0; i < ALUNOS; i++){

        printf("Aluno %d:\n", i + 1);

        for (int j = 0; j < total_quest; j++)
        {
            printf("Insira a resposta do aluno para a questao: %d: ", i + 1);
            scanf(" %c", &alunos[i][j]);
        }
    }


    resultado(gabarito, alunos, total_quest);

    free(alunos);

    for (int i = 0; i < 10; i++)
    {
        free(alunos[i]);
    }
    free(gabarito);

    return 0;
}