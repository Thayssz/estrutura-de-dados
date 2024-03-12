#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct fruta{
    char nome[20];
    double preco;
};

bool  valid_string(const char* enter){
    return strcspn(enter, "0123456789") == strlen(enter);
}

int main(void){
    int valid;
    FILE * arq;
    struct fruta blankFruit;
    int cadastro = 0;

    if((arq = fopen("frutas.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
    else{
        do{
            printf("Digite o nome da fruta: \n- ");
            scanf(" %[^\n]", blankFruit.nome);
            while(!valid_string(blankFruit.nome)){
                printf("Nome invalido, por favor digite novamente.\n- ");
                while(getchar() != 1);
                scanf(" %[^\n]", blankFruit.nome);
            }

            do{
                printf("Digite o preco da fruta:\n- ");
                valid = scanf("%lf", &blankFruit.preco);
                if(valid != 1){
                    printf("Preco invalido, por favor digite um preco valido.\n");
                    while(getchar() != '\n');
                }
            }while(valid != 1);

            fprintf(arq, "%s, %.2lf\n", blankFruit.nome, blankFruit.preco);
            do{
                printf("1 - Cadastrar nova fruta.\n0 - Encerrar e sair.\n- ");
                valid = scanf("%d", &cadastro);
                if(valid != 1){
                    printf("Opcao invalida, por favor digite uma opcao valida.\n");
                    while(getchar() != '\n');
                }
            }while(valid != 1);
        }while(cadastro != 0);
    }
}