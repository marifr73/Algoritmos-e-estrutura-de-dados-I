#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

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

    if (lista == NULL) {
        return novo_elemento;
    } else{
        No* count;
        for (count = lista; count->prox != NULL; count = count->prox){
        }
        count->prox = novo_elemento;
        return lista;
    }
}

void exibir_lista(No *lista) {
    No *count;  
    if (lista == NULL) {  
        printf("Lista vazia\n");  
        return;  
    }  

    for (count = lista; count != NULL; count = count->prox) {  
        printf("%d -> ", count->valor);  
    }  
    printf("NULL\n");
}  

No* remover_primeiro(No* lista) {
    if (lista == NULL) {
        return NULL;
    }

    No* count = lista;
    lista = lista->prox;
    free(count);
    return lista;
}

void libera_lista(No *lista) {
    No *count = lista;
    No *aux;
    while (count != NULL) {
        aux = count->prox;
        free(count);
        count = aux;
    }
}

No* buscar(int valor, No *lista) {
    No *count;
    for (count = lista; count != NULL; count = count->prox) {
        if (count->valor == valor) {
            printf("\nValor encontrado: %d\n", count->valor);
            return count;
        }
    }
    return NULL;
}

No *remover_valor(No* lista, int valor){
    No *ant = NULL;
    No *count = lista;
    while (count != NULL && count -> valor != valor){
        ant = count;
        count = count->prox;
    }

    if(count == NULL){
        return lista;
    }

    if(ant == NULL){
        lista = lista->prox;
    } else {
        ant->prox = count->prox;
    }
    free(count);
    return lista;
}

No* inserir_apos(No* lista, int valor, int novo_valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
        exit(1); 
    }
    novo_elemento->valor = novo_valor;
    novo_elemento->prox = NULL;

    No* count;
    for (count = lista; count != NULL; count = count->prox) {
        if (count->valor == valor) {
            novo_elemento->prox = count->prox;
            count->prox = novo_elemento;
            return lista;
        }
    }
    free(novo_elemento);
    return lista;
}