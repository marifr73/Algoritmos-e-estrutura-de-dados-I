#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no {
    float info;
    No* prox;
};

struct fila_lista {
    No* inicio;
    No* fim;
};

FilaLista* fila_lista_cria(void) {
    FilaLista* f = (FilaLista*)malloc(sizeof(FilaLista));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void fila_lista_insere(FilaLista* f, float v) {
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

float fila_lista_retira(FilaLista* f) {
    if (fila_lista_vazia(f)) {
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

int fila_lista_vazia(FilaLista* f) {
    return (f->inicio == NULL);
}

void fila_lista_imprime(FilaLista* f) {
    No* p = f->inicio;
    while (p != NULL) {
        printf("%.2f -> ", p->info);
        p = p->prox;
    }
    printf("NULL\n");
}

void fila_lista_libera(FilaLista* f) {
    No* p = f->inicio;
    while (p != NULL) {
        No* t = p->prox;
        free(p);
        p = t;
    }
    free(f);
}
