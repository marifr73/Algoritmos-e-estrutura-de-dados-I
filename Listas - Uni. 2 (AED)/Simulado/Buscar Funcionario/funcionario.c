#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#include "funcionario.h"

struct funcionario{
    char nome[20];
    int id;
    float salario;
};

Funcionario **alocaFuncionario(int initialSize) {
    Funcionario **novo = (Funcionario **)malloc(sizeof(Funcionario *) * initialSize);
    if (novo == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return novo;
}

Funcionario **adicionaFuncionario(Funcionario **funcionario, char *nome, int id, float salario, int *qnt, int *capacidade) {
    if (*qnt >= *capacidade) {
        *capacidade *= 2;
        funcionario = (Funcionario **)realloc(funcionario, sizeof(Funcionario *) * (*capacidade));
        if (funcionario == NULL) {
            printf("Erro ao realocar memória!\n");
            exit(1);
        }
    }
    funcionario[*qnt] = (Funcionario *)malloc(sizeof(Funcionario));
    if (funcionario[*qnt] == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(funcionario[*qnt]->nome, nome);
    funcionario[*qnt]->id = id;
    funcionario[*qnt]->salario = salario;
    (*qnt)++;
    return funcionario;
}



Funcionario **removeFuncionario(Funcionario **funcionario, int id, int *qnt){
    int i;
    for (i = 0; i < (*qnt); i++){
        if (funcionario[i]->id == id){
            free(funcionario[i]);
            break;
        }
    }

    if (i < (*qnt)) {
        for (int j = i; j < (*qnt) - 1; j++){
            funcionario[j] = funcionario[j + 1];
        }
        (*qnt)--;
    }

    return funcionario;
}

Funcionario *buscaFuncionario(Funcionario **funcionario, int id, int qnt) {
    for (int i = 0; i < qnt; i++) {
        if (funcionario[i]->id == id) {
            return funcionario[i];
        }
    }
    return NULL;
}

void listarFuncionarios(Funcionario **funcionario, int qnt){
    for (int i = 0; i < qnt; i++){
            printf("Nome: %s\nId: %i\nsalario: %f", funcionario[i]->nome, funcionario[i]->id, funcionario[i]->salario);
    }
}

void libera_funcionario(Funcionario **funcionario, int qnt){
    for (int i = 0; i < qnt; i++){
        free(funcionario[i]);
    }
    free(funcionario);
}