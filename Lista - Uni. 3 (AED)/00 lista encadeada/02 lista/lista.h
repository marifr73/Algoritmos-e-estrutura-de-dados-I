#ifndef LISTA_H
#define LISTA_H
#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

No* inserir_no_inicio(No* lista, int valor);

No* inserir_no_fim(No* lista, int valor);

void exibir_lista(No *lista);

No* remover_primeiro(No* lista);

void libera_lista(No *lista);

No *buscar(int valor, No *lista);

No *remover_valor(No* lista, int valor);

No* inserir_apos(No* lista, int valor, int novo_valor);

#endif