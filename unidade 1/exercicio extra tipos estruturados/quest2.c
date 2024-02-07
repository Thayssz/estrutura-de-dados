#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_NOME 80

typedef struct {
    int matricula;
    char nome[MAX_NOME];
    char turma;
    float notas[3];
    float media;
} Aluno;

void inicializa_alunos(Aluno** alunos, int n) {
    for (int i = 0; i < n; i++) {
        alunos[i] = NULL;
    }
}

void matricula(int n, Aluno** alunos) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] == NULL) {
            alunos[i] = (Aluno*)malloc(sizeof(Aluno));

            printf("Digite os dados do aluno:\n");
            printf("Matrícula: ");
            scanf("%d", &(alunos[i]->matricula));
            printf("Nome: ");
            getchar();
            fgets(alunos[i]->nome, MAX_NOME, stdin);
            printf("Turma: ");
            scanf(" %c", &(alunos[i]->turma));

            for (int j = 0; j < 3; j++) {
                printf("Nota %d: ", j + 1);
                scanf("%f", &(alunos[i]->notas[j]));
            }
            alunos[i]->media = 0.0;

            printf("Aluno matriculado com sucesso!\n");
            return;
        }
    }
    printf("Não há vagas disponíveis.\n");
}

void lanca_notas(int n, Aluno** alunos) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL) {

            float soma = 0.0;
            for (int j = 0; j < 3; j++) {
                soma += alunos[i]->notas[j];
            }
            alunos[i]->media = soma / 3.0;
        }
    }
    printf("Notas lançadas e médias calculadas.\n");
}

void imprime_tudo(int n, Aluno** alunos) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL) {
            printf("Matrícula: %d\n", alunos[i]->matricula);
            printf("Nome: %s", alunos[i]->nome);
            printf("Turma: %c\n", alunos[i]->turma);
            printf("Notas: %.2f, %.2f, %.2f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
            printf("Média: %.2f\n", alunos[i]->media);
            printf("\n");
        }
    }
}

void imprime_turma(int n, Aluno** alunos, char turma) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->turma == turma) {
            printf("Matrícula: %d\n", alunos[i]->matricula);
            printf("Nome: %s", alunos[i]->nome);
            printf("Turma: %c\n", alunos[i]->turma);
            printf("Notas: %.2f, %.2f, %.2f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
            printf("Média: %.2f\n", alunos[i]->media);
            printf("\n");
        }
    }
}

void imprime_turma_aprovados(int n, Aluno** alunos, char turma) {
    for (int i = 0; i < n; i++) {
        if (alunos[i] != NULL && alunos[i]->turma == turma && alunos[i]->media >= 7.0) {
            printf("Matrícula: %d\n", alunos[i]->matricula);
            printf("Nome: %s", alunos[i]->nome);
            printf("Turma: %c\n", alunos[i]->turma);
            printf("Notas: %.2f, %.2f, %.2f\n", alunos[i]->notas[0], alunos[i]->notas[1], alunos[i]->notas[2]);
            printf("Média: %.2f\n", alunos[i]->media);
            printf("\n");
        }
    }
}

int main() {
    Aluno* alunos[MAX_ALUNOS];
    inicializa_alunos(alunos, MAX_ALUNOS);

    int opcao;
    char turma;

    do {
        printf("Menu:\n");
        printf("1. Matricular aluno\n");
        printf("2. Lançar notas\n");
        printf("3. Imprimir todos os alunos\n");
        printf("4. Imprimir alunos de uma turma\n");
        printf("5. Imprimir alunos aprovados de uma turma\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                matricula(MAX_ALUNOS, alunos);
                break;
            case 2:
                lanca_notas(MAX_ALUNOS, alunos);
                break;
            case 3:
                imprime_tudo(MAX_ALUNOS, alunos);
                break;
            case 4:
                printf("Digite a turma: ");
                scanf(" %c", &turma);
                imprime_turma(MAX_ALUNOS, alunos, turma);
                break;
            case 5:
                printf("Digite a turma: ");
                scanf(" %c", &turma);
                imprime_turma_aprovados(MAX_ALUNOS, alunos, turma);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    for (int i = 0; i < MAX_ALUNOS; i++) {
        free(alunos[i]);
    }

    return 0;
}
