#ifndef LISTA_H
#define LISTA_H

#define PI 3.14

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct circulo Circulo;
typedef struct triangulo Triangulo;
typedef struct retangulo Retangulo;
typedef struct listaHet ListaHet;

ListaHet* cria_ret(float b, float h);
ListaHet* cria_tri(float b, float h);
ListaHet* cria_circ(float r);
float ret_area(Retangulo *r);
float tri_area(Triangulo *t);
float circ_area(Circulo *c);
float area(ListaHet *p);
float max_area(ListaHet *l);
void libera_lista(ListaHet* l);

#endif // LISTA_H