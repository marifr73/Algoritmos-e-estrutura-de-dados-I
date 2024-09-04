#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

struct no {
    int valor;
    No* prox;
};

No* inserir_no_inicio(No* lista, int valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    novo_elemento->valor = valor;
    
    if (lista == NULL) {
        novo_elemento->prox = novo_elemento;
        return novo_elemento;
    } else {
        No* aux = lista;
        while (aux->prox != lista) {
            aux = aux->prox;
        }
        novo_elemento->prox = lista;
        aux->prox = novo_elemento;
        return novo_elemento;
    }
}

No* inserir_no_fim(No* lista, int valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
        printf("No memory!\n");
        exit(1);
    }
    novo_elemento->valor = valor;

    if (lista == NULL) {
        novo_elemento->prox = novo_elemento;
        return novo_elemento;
    } else {
        No* aux = lista;
        while (aux->prox != lista) {
            aux = aux->prox;
        }
        aux->prox = novo_elemento;
        novo_elemento->prox = lista;
        return lista;
    }
}

void exibir_lista(No* lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* count = lista;
    do {
        printf("%d -> ", count->valor);
        count = count->prox;
    } while (count != lista);
}

void libera_lista(No* lista) {
    if (lista == NULL) return;

    No* count = lista;
    No* aux;
    do {
        aux = count->prox;
        free(count);
        count = aux;
    } while (count != lista);
}
