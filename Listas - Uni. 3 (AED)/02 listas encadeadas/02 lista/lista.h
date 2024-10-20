#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

Lista* cria_no(int valor);
void lcirc_imprime(Lista* l);
Lista* lcirc_insere(Lista* l, int valor);
Lista* lcirc_retira(Lista* l, int valor);
int lcirc_verifica(Lista* l, int valor);
void lcirc_libera(Lista* l);

#endif // LISTA_CIRCULAR_H