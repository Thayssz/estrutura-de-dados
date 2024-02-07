#include <stdio.h>
#include <string.h>

typedef struct _funcionario {
    char nome[50];
    float salario;
    int identificador;
    char cargo[50];
} funcionario;

void preencherFuncionario(funcionario *funcionario) {
    printf("Digite o nome do funcionario: ");
    scanf("%s", funcionario->nome);

    printf("Digite o salario do funcionario: ");
    scanf("%f", &funcionario->salario);

    printf("Digite o identificador do funcionario: ");
    scanf("%d", &funcionario->identificador);

    printf("Digite o cargo do funcionario: ");
    scanf("%s", funcionario->cargo);
}

void imprimirFuncionario(const funcionario *funcionario) {
    printf("Nome: %s\n", funcionario->nome);
    printf("Salario: %.2f\n", funcionario->salario);
    printf("Identificador: %d\n", funcionario->identificador);
    printf("Cargo: %s\n", funcionario->cargo);
}

void alterarSalario(funcionario *funcionario, float novoSalario) {
    funcionario->salario = novoSalario;
}

void maiorMenorSalario(const funcionario funcionarios[], int tamanho) {
    int maiorSalario = 0, menorSalario = 0;

    for (int i = 1; i < tamanho; ++i) {
        if (funcionarios[i].salario > funcionarios[maiorSalario].salario) {
            maiorSalario = i;
        }
        if (funcionarios[i].salario < funcionarios[menorSalario].salario) {
            menorSalario = i;
        }
    }

    printf("Funcionario com maior salario:\n");
    imprimirFuncionario(&funcionarios[maiorSalario]);

    printf("\nFuncionario com menor salario:\n");
    imprimirFuncionario(&funcionarios[menorSalario]);
}

int main(void) {

    funcionario funcionario1;

    preencherFuncionario(&funcionario1);
    printf("\nInformacoes do funcionario:\n");

    imprimirFuncionario(&funcionario1);

    alterarSalario(&funcionario1, 3000.0);
    printf("\nInformacoes do funcionario apos alteracao de salario:\n");
    imprimirFuncionario(&funcionario1);

    funcionario funcionarios[3];
    for (int i = 0; i < 3; ++i) {
        printf("\nDigite informacoes para o funcionario %d:\n", i + 1);
        preencherFuncionario(&funcionarios[i]);
    }

    printf("\nMaior e menor salario entre os funcionarios:\n");
    maiorMenorSalario(funcionarios, 3);

    return 0;
}
