#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

#define MAX 100

struct fila_vetor {
    int n;
    int inicio;
    float vet[MAX];
};

FilaVetor* fila_vetor_cria(void) {
    FilaVetor* f = (FilaVetor*)malloc(sizeof(FilaVetor));
    f->n = 0;
    f->inicio = 0;
    return f;
}

void fila_vetor_insere(FilaVetor* f, float v) {
    if (f->n == MAX) {
        printf("Capacidade da fila estourou\n");
        exit(1);
    }
    int fim = (f->inicio + f->n) % MAX;
    f->vet[fim] = v;
    f->n++;
}

float fila_vetor_retira(FilaVetor* f) {
    if (fila_vetor_vazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    }
    float v = f->vet[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->n--;
    return v;
}

int fila_vetor_vazia(FilaVetor* f) {
    return (f->n == 0);
}

void fila_vetor_imprime(FilaVetor* f) {
    for (int i = 0; i < f->n; i++) {
        int index = (f->inicio + i) % MAX;
        printf("%.2f -> ", f->vet[index]);
    }
    printf("NULL\n");
}

void fila_vetor_libera(FilaVetor* f) {
    free(f);
}