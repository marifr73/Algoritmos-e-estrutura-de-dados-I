#include <stdio.h>
#include <stdlib.h>

typedef struct funcionario {
    char nome[20], cargo[20];
    float salario;
    int id;
} Funcionario;

void limpar_buffer() {
    int i;
    for (i = 0; (i = getchar()) != '\n' && i != EOF;) {
    }
}
//EOF verifica se a leitura chegou ao fim do arquivo ou entrada, garantindo que o loop termine corretamente.

//Função pra preencher as informações do funcionario
void preencha(Funcionario *servidor) {
    printf("Informe Cargo: \t");
    limpar_buffer();
    scanf(" %[^\n]", servidor->cargo);

    printf("Informe Identificador: \t");
    scanf("%d", &servidor->id);

    printf("Informe o seu nome: \t");
    limpar_buffer();
    scanf(" %[^\n]", servidor->nome);

    printf("Informe Salario: \t");
    scanf("%f", &servidor->salario);
}

//Função para imprimir as informações do funcionario
void imprima(Funcionario *servidor) {
    printf("O seu Cargo e: [%s]\n", servidor->cargo);
    printf("O Identificador informado e: [%d]\n", servidor->id);
    printf("O nome informado e: [%s]\n", servidor->nome);
    printf("O salario informado e: [%.2f]\n", servidor->salario);
}

//Funçao para altera o salario
void alterar_salario(Funcionario *servidor, float novo_s) {
    servidor->salario = novo_s;
}

//Função para receber o novo salário atraves do ID do funcionario
void novo_salario(Funcionario *funcionario, int n) {
    int id_salario, i;
    float novo_s;
    printf("\nInforme o ID do funcionario que deseja alterar o salario: ");
    scanf("%d", &id_salario);
    printf("\nInforme o novo salario: ");
    scanf("%f", &novo_s);

    for (i = 0; i < n; i++) {
        if (funcionario[i].id == id_salario) {
            alterar_salario(&funcionario[i], novo_s);
            printf("\nNovo salario atualizado para o funcionario com ID %d.\n", id_salario);
            imprima(&funcionario[i]);
            break;
        }
    }
}

//Funçao pra identificar o funcionario com maior e menor salario
void maior_menor_s(Funcionario *servidores, int tamanho) {
    if (tamanho <= 0) {
        printf("Nenhum funcionário encontrado.\n");
        return;
    }

    Funcionario *maior_s = &servidores[0];
    Funcionario *menor_s = &servidores[0];

    int i;
    for (i = 1; i < tamanho; i++) {
        if (servidores[i].salario > maior_s->salario) {
            maior_s = &servidores[i];
        }
        if (servidores[i].salario < menor_s->salario) {
            menor_s = &servidores[i];
        }
    }

    printf("\n\nFuncionario com maior salario:\n");
    printf("Cargo: [%s], Salario: [%.2f]\n", maior_s->cargo, maior_s->salario);

    printf("\nFuncionario com menor salario:\n");
    printf("Cargo: [%s], Salario: [%.2f]\n", menor_s->cargo, menor_s->salario);
}

int main() {
    int n, i;
    //Informar quantidade de funcionario
    printf("Informe o numero de funcionarios: ");
    scanf("%d", &n);

    Funcionario *funcionario = (Funcionario*) malloc(n * sizeof(Funcionario));
    if (funcionario == NULL) {
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("\nPreenchendo dados do %dº funcionario:\n", i + 1);
        preencha(&funcionario[i]);
    }

    for (i = 0; i < n; i++) {
        printf("\nDados do %dº funcionario:\n", i + 1);
        imprima(&funcionario[i]);
    }

    maior_menor_s(funcionario, n);
    novo_salario(funcionario, n);
    
    free(funcionario);

    return 0;
}