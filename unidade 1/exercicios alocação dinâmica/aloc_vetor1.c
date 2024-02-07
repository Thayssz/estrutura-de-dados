#include <stdio.h>
#include <stdlib.h>

int main(void){
    int n, i, j;
    int soma_fem = 0;
    int soma_masc = 0;

    printf("Digite a quantidade de pessoas entrevistadas:\n");
    scanf("%d", &n);

    char *sexo = (char*)calloc(n, sizeof(char));
    int *opiniao = (int*)calloc(n, sizeof(int));

    if (sexo == NULL){
        printf("ERRO DE ALOCAÇÃO DE MEMORIA\n");
        exit(1);
    }

    if (opiniao == NULL){
        printf("ERRO DE ALOCAÇÃO DE MEMORIA\n");
        exit(1);
    }

    for(i = 0; i < n; i++){
        printf("Qual o seu sexo: M(masculino) F(feminino):\n");
        scanf(" %c", &sexo[i]);

        printf("Qual a sua opiniao: 0(gostou) 1(nao gostou):\n");
        scanf("%d", &opiniao[i]);
    }

    for(j = 0; j < n; j++){
        if((sexo[j] == 'F') && (opiniao[j] == 0)){
            soma_fem++;
        }
        else if((sexo[j] == 'M') && (opiniao[j] == 1)){
            soma_masc++;
        }
    }

    soma_fem = ((soma_fem * 100.0f) / n);
    soma_masc = ((soma_masc * 100.0f) / n);

    printf("%d %% mulheres gostaram e %d %% homens nao gostaram", soma_fem, soma_masc);

    free(sexo);
    free(opiniao);
}