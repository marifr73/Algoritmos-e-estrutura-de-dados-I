#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "funcionario.h"

int main() {
    int capacidade = 10;
    Funcionario **funcionario = alocaFuncionario(capacidade);
    int qnt = 0;
    int id;
    char nome[50];
    float salario;
    int opcao;
    Funcionario *f;

    do {
        printf("\n-------------------------\n");
        printf("[1] - Adicionar funcionario\n");
        printf("[2] - Buscar funcionario\n");
        printf("[3] - Remover funcionario\n");
        printf("[4] - Listar funcionarios\n");
        printf("[5] - Sair\n");
        printf("\n-------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        system("clear");

        switch (opcao) {
            case 1:
                printf("Digite o nome do funcionario: ");
                scanf(" %[^\n]", nome);
                printf("Digite o ID: ");
                scanf("%d", &id);
                printf("Digite o salario: ");
                scanf("%f", &salario);
                funcionario = adicionaFuncionario(funcionario, nome, id, salario, &qnt);
                printf("Funcionario cadastrado com sucesso!\n");
                break;

            case 2:
                printf("Digite o ID do funcionario: ");
                scanf("%d", &id);
                f = buscaFuncionario(funcionario, id, qnt);

                if (f != NULL) {
                    printf("Funcionario encontrado!\nNome: %s\nID: %d\nSalario: %.2f\n", f->nome, f->id, f->salario);
                } else {
                    printf("Funcionario nao encontrado!\n");
                }
            break;

            case 3:
                printf("Digite o ID do funcionario que deseja remover: ");
                scanf("%d", &id);
                funcionario = removeFuncionario(funcionario, id, &qnt);
            break;

            case 4:
                listarFuncionarios(funcionario, qnt);
            break;

            case 5:
                printf("Saindo...\n");
                libera_funcionario(funcionario, qnt);
            break;

            default:
                printf("Opcao invalida!\n");
            break;
        }

    } while (opcao != 5);

    return 0;
}