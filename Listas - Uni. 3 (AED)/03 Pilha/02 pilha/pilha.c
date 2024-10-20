#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct pilha {
    float valor;
    struct pilha* prox;
};

Pilha* pilha_cria(void) {
    return NULL;
}

void pilha_push(Pilha** p, float v) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    novo->valor = v;
    novo->prox = *p;
    *p = novo;
}

float pilha_pop(Pilha** p) {
    if (*p == NULL) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    Pilha* t = *p;
    float v = t->valor;
    *p = t->prox;
    free(t);
    return v;
}

int pilha_vazia(Pilha* p) {
    return (p == NULL);
}

void pilha_libera(Pilha* p) {
    Pilha* q = p;
    while (q != NULL) {
        Pilha* t = q->prox;
        free(q);
        q = t;
    }
}

void pilha_imprime(Pilha* p) {
    Pilha* atual = p;
    printf("Pilha: ");
    while (atual != NULL) {
        printf("%.2f -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

float topo(Pilha** p) {
    if (pilha_vazia(*p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    float v = pilha_pop(p);
    pilha_push(p, v);
    return v;
}

void concatena_pilhas(Pilha** p1, Pilha** p2) {
    Pilha* temp = pilha_cria();
    
    while (!pilha_vazia(*p2)) {
        pilha_push(&temp, pilha_pop(p2));
    }
    
    while (!pilha_vazia(temp)) {
        pilha_push(p1, pilha_pop(&temp));
    }
    
    pilha_libera(temp);
}