#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct aluno{
    char nome[20];
    double notas[3];
};

bool valid_string(const char* enter) {
    return strcspn(enter, "0123456789") == strlen(enter);
}

int main(void){
    struct aluno blankAluno;
    FILE *arq;
    int n;
    int valid;

    if((arq = fopen("lista_alunos.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }

    do{
        printf("Digite a quantidade de alunos a ser registrada:\n- ");
        valid = scanf("%d", &n);

        if(valid != 1){
            printf("Numero invalido, por favor digite um numero inteiro.\n");
            while(getchar() != '\n');
        }
    }while(valid != 1);
    

    for(int i=0; i<n; i++){
        printf("Digite o nome do aluno %d:\n- ", i+1);
        scanf(" %[^\n]", blankAluno.nome);
        while(!valid_string(blankAluno.nome)){
            printf("Nome invalido, por favor digite novamente\n- ");
            while(getchar() != '\n');
            scanf(" %[^\n]", blankAluno.nome);
        }
        for(int j=0; j<3; j++){
            do{
                printf("Digite a nota %d do aluno:\n- ", j+1);
                valid = scanf("%lf", &blankAluno.notas[j]);

                if(valid != 1){
                    printf("Nota invalida, por favor digite novamente.\n- ");
                    while(getchar() != '\n');
                }
            }while(valid != 1);
        }

        fprintf(arq, "Aluno:%s\nNotas: %.1lf\t%.1lf\t%.1lf\n\n", blankAluno.nome, blankAluno.notas[0], blankAluno.notas[1], blankAluno.notas[2]);
        printf("\n");
    }
}