#ifndef LISTA2_CIRCULAR_H
#define LISTA2_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista2 Lista2;

Lista2* l2circ_cria_no(int valor);
void l2circ_imprime(Lista2* l);
Lista2* l2circ_insere(Lista2* l, int valor);
Lista2* l2circ_retira(Lista2* l, int valor);
void l2circ_libera(Lista2* l);
Lista2* l2circ_busca(Lista2* l, int valor);

#endif