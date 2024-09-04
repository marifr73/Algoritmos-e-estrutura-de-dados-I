#include "lista.h"

struct no{
    int valor;
    No * prox;
};

No* inserir_no_inicio(No* lista, int valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
        exit(1);
    }
    novo_elemento->valor = valor;
    novo_elemento->prox = lista;

    return novo_elemento; 
}

No* inserir_no_fim(No* lista, int valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
        exit(1);
    }
    novo_elemento->valor = valor;
    novo_elemento->prox = NULL;

    No* count = lista;

    if (lista == NULL) {
        return novo_elemento;
    } else {
        for (count = lista; count->prox != NULL; count = count->prox) {
        }
        count->prox = novo_elemento;
        return lista; 
    }
}

void exibir_lista(No *lista){
    No *count;
    for(count = lista; count != NULL; count = count->prox){
        printf(" %d\t", count->valor);
    }
}

No* remove_primeiro(No* lista) {
    No* count = lista;
    if (lista == NULL) {
        return NULL;
    }

    lista = lista->prox;
    free(count);

    return lista;
}

void libera_lista(No *lista){
    No *count = lista;
    No *aux;
    while (count!=NULL){
        aux = count -> prox;
        free(count);
        count = aux;
    }
}