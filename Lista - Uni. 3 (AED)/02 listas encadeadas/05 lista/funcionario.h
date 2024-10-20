#ifndef LISTA_FUNCIONARIOS_H
#define LISTA_FUNCIONARIOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listaFunc ListaFunc;

ListaFunc* lstfunc_cria(void);
void lstfunc_libera(ListaFunc* l);
ListaFunc* lstfunc_insere(ListaFunc* l, char depto, int mat, const char* nome, float salario);
float lstfunc_folha_pagto(ListaFunc* l, char depto);
void lstfunc_imprime(ListaFunc* l);

#endif
