#include "lista.h"

struct no {
    int valor;
    No* prox;
};

No* inserir_no_inicio(No* lista, int valor) {
    No* novo_elemento = (No*)malloc(sizeof(No));
    if (novo_elemento == NULL) {
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

No* buscar(int valor, No* lista) {
    if (lista == NULL) {
        return NULL;
    }

    No* count = lista;
    No* aux = NULL; 
    do {
        if (count->valor == valor) {
            printf("\nValor %d encontrado.\n", valor);
            return count;
        }
        count = count->prox;
        aux = count;
    } while (count != lista);

    return NULL;
}

No* remover_valor(No* lista, int valor) {
    if (lista == NULL) {
        return NULL;
    }
    No* aux = lista;
    No* ant = NULL;
    No* count = lista;
    do {
        if (count->valor == valor) {
            if (ant == NULL) {
                lista = count->prox;
                while (aux->prox != count) {
                    aux = aux->prox;
                }
                aux->prox = lista;
            } else {
                ant->prox = count->prox;
            }
            free(count);
            return lista;
        }
        ant = count;
        count = count->prox;
    } while (count != lista);
    return lista;
}

No* remover_primeiro(No* lista) {
    if (lista == NULL) {
        return NULL;
    }

    No* count = lista;
    if (lista->prox == lista) {
        free(lista);
        return NULL;
    }

    No* aux;
    for (aux = lista; aux->prox != lista; aux = aux->prox) {
    }
    aux->prox = lista->prox;
    lista = lista->prox;
    free(count);
    return lista;
}

No* remover_ultimo(No* lista) {
    if (lista == NULL) {
        return NULL;
    }

    No* count = lista;
    No* ant = NULL;

    if (lista->prox == lista) {
        free(lista);
        return NULL;
    }

    for (ant = lista, count = lista->prox; count->prox != lista; ant = count, count = count->prox) {
    }

    ant->prox = lista; 
    free(count);

    return lista;
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
