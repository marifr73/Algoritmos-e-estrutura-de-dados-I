#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conta_bancaria.h"

struct contabancaria {
    char titular[20];
    int numero;
    double saldo;
};

Contabancaria* criar_conta(char *titular, int numero, double saldo) {
    Contabancaria *conta = (Contabancaria*) malloc(sizeof(Contabancaria));
    if (conta == NULL) {
        printf("Memória insuficiente!");
        exit(1);
    }

    strcpy(conta->titular, titular);
    conta->numero = numero;
    conta->saldo = saldo;
    return conta;
}

void deposita(Contabancaria *conta, double novo_saldo) {
    if (novo_saldo <= 0) {
        printf("\nNão é possível depositar valores negativos ou nulos!\n");
    } else {
        conta->saldo += novo_saldo;
        printf("\nValor depositado com sucesso!\nNovo saldo: %.2lf\n", conta->saldo);
    }
}

void saca(Contabancaria *conta, double valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("\nSaque realizado com sucesso!\nNovo saldo: %.2lf\n", conta->saldo);
    } else {
        printf("\nSaldo insuficiente!\n");
    }
}

void transfere(Contabancaria *conta_origem, Contabancaria *conta_destino, double valor) {
    if (conta_origem->saldo >= valor) {
        conta_origem->saldo -= valor;
        conta_destino->saldo += valor;
        printf("\nTransferência realizada com sucesso!\nNovo saldo da conta de origem: %.2lf\nNovo saldo da conta de destino: %.2lf\n", conta_origem->saldo, conta_destino->saldo);
    } else {
        printf("\nSaldo insuficiente para realizar a transferência!\n");
    }
}

double Saldo(Contabancaria *conta) {
    printf("Saldo: %.2lf\n", conta->saldo);
    return conta->saldo;
}

void Excluir_conta(Contabancaria *conta) {
    free(conta);
}