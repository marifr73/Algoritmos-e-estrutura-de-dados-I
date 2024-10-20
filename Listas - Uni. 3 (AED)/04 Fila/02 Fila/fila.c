#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no {
    float info;
    No* prox;
};

struct fila {
    No* inicio;
    No* fim;
};

Fila* fila_cria(void) {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void fila_insere(Fila* f, float v) {
    No* n = (No*)malloc(sizeof(No));
    n->info = v;
    n->prox = NULL;
    if (f->fim != NULL) {
        f->fim->prox = n;
    } else {
        f->inicio = n;
    }
    f->fim = n;
}

float fila_retira(Fila* f) {
    if (fila_vazia(f)) {
        printf("Fila vazia\n");
        exit(1);
    }
    No* t = f->inicio;
    float v = t->info;
    f->inicio = t->prox;
    if (f->inicio == NULL) {
        f->fim = NULL;
    }
    free(t);
    return v;
}

int fila_vazia(Fila* f) {
    return (f->inicio == NULL);
}

void fila_imprime(Fila* f) {
    No* p = f->inicio;
    while (p != NULL) {
        printf("%.2f -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

void fila_libera(Fila* f) {
    struct no* p = f->inicio;
    while (p != NULL) {
        struct no* t = p->prox;
        free(p);
        p = t;
    }
    free(f);
}

void combina_filas(Fila* f_res, Fila* f1, Fila* f2) {
    while (!fila_vazia(f1) || !fila_vazia(f2)) {
        if (!fila_vazia(f1)) {
            fila_insere(f_res, fila_retira(f1));
        }
        if (!fila_vazia(f2)) {
            fila_insere(f_res, fila_retira(f2));
        }
    }
}