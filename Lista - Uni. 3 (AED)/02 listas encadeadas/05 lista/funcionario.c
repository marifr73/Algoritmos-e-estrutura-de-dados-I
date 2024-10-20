#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionario.h"

struct listaFunc{
    char depto;
    int mat;     
    char nome[81];
    float salario;
    ListaFunc *prox; 
};

ListaFunc* lstfunc_cria(void) {
    return NULL;
}

void lstfunc_libera(ListaFunc* l) {
    while (l != NULL) {
        ListaFunc* temp = l->prox;
        free(l);
        l = temp;
    }
}

ListaFunc* lstfunc_insere(ListaFunc* l, char depto, int mat, const char* nome, float salario) {
    ListaFunc* novo = (ListaFunc*)malloc(sizeof(ListaFunc));
    novo->depto = depto;
    novo->mat = mat;
    strncpy(novo->nome, nome, 80);
    novo->nome[80] = '\0';
    novo->salario = salario;
    novo->prox = l;
    return novo;
}

float lstfunc_folha_pagto(ListaFunc* l, char depto) {
    float total = 0.0;
    ListaFunc* p = l;
    while (p != NULL) {
        printf("Comparando %c com %c\n", p->depto, depto);
        if (p->depto == depto) {
            total += p->salario;
        }
        p = p->prox;
    }
    return total;
}

void lstfunc_imprime(ListaFunc* l) {
    ListaFunc* p = l;
    while (p != NULL) {
        printf("Depto: %c, Mat: %d, Nome: %s, Salario: %.2f\n", p->depto, p->mat, p->nome, p->salario);
        p = p->prox;
    }
}