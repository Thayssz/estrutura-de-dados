#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct dados{
    int id;
    char nome[50];
    double salario;
};

bool valid_string(const char* enter) {
    return strcspn(enter, "0123456789") == strlen(enter);
}

int main(void){
    int op = 1;
    int valid;
    FILE *lista;
    
    struct dados funcionario;

    if((lista = fopen("funcionarios.txt", "w")) == NULL){
        printf("Erro ao abrir arquivo.\n");
    }
    else{
        while(op != 0){
            do{
                printf("Digite um id de funcionario:\n- ");
                valid = scanf("%d", &funcionario.id);

                if(valid != 1){
                    printf("Codigo invalido, por favor digite um numero inteiro.\n");
                    while(getchar() != '\n');
                }
            } while(valid != 1);
            
            printf("Digite o nome do funcionario:\n- ");
            scanf(" %[^\n]", funcionario.nome);
            while(!valid_string(funcionario.nome)){
                printf("Nome invalido, por favor digite o nome novamente.\n- ");
                while(getchar() != '\n');
                scanf(" %[^\n]", funcionario.nome);
            }
            
            do{
                printf("Digite o salario do funcionario:\n- ");
                valid = scanf("%lf", &funcionario.salario);

                if(valid != 1){
                    printf("Salario invalido, por favor digite novamente.\n- ");
                    while(getchar() != '\n');
                }
            }while(valid != 1);
            

            fprintf(lista, "Nome: %s\nId: %d\nSalario: %.2lf\n\n", funcionario.nome, funcionario.id, funcionario.salario);

            printf("1 para cadastrar outro funcionario ou 0 para encerrar: ");
            scanf("%d", &op);
            while((op != 1) && (op != 0)){
                printf("Opcao invalida, por favor digite uma opcao valida\n");
                printf("1 para cadastrar outro usuario\n0 para encerrar: ");
                scanf("%d", &op);
            }
        }
    }
}