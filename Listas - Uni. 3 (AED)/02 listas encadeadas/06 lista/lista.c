#include "lista.h"

struct retangulo {
    float base, altura;
};

struct triangulo {
    float base, altura;
};

struct circulo {
    float raio;
};

struct listaHet {
    int tipo;
    void *objeto;
    ListaHet *prox;
};

ListaHet* cria_ret(float b, float h) {
    Retangulo *r = (Retangulo *) malloc(sizeof(Retangulo));
    if (r == NULL) {
        printf("Erro ao alocar memória para Retângulo.\n");
        exit(1);
    }
    r->base = b;
    r->altura = h;
    ListaHet *no = (ListaHet *) malloc(sizeof(ListaHet));
    if (no == NULL) {
        printf("Erro ao alocar memória para nó da lista.\n");
        exit(1);
    }
    no->tipo = 0;
    no->objeto = r;
    no->prox = NULL;
    return no;
}

ListaHet* cria_tri(float b, float h) {
    Triangulo *t = (Triangulo *) malloc(sizeof(Triangulo));
    if (t == NULL) {
        printf("Erro ao alocar memória para Triângulo.\n");
        exit(1);
    }
    t->base = b;
    t->altura = h;
    ListaHet *no = (ListaHet *) malloc(sizeof(ListaHet));
    if (no == NULL) {
        printf("Erro ao alocar memória para nó da lista.\n");
        exit(1);
    }
    no->tipo = 1;
    no->objeto = t;
    no->prox = NULL;
    return no;
}

ListaHet* cria_circ(float r) {
    Circulo *c = (Circulo *) malloc(sizeof(Circulo));
    if (c == NULL) {
        printf("Erro ao alocar memória para Círculo.\n");
        exit(1);
    }
    c->raio = r;
    ListaHet *no = (ListaHet *) malloc(sizeof(ListaHet));
    if (no == NULL) {
        printf("Erro ao alocar memória para nó da lista.\n");
        exit(1);
    }
    no->tipo = 2;
    no->objeto = c;
    no->prox = NULL;
    return no;
}

float ret_area(Retangulo *r) {
    return r->base * r->altura;
}

float tri_area(Triangulo *t) {
    return (t->base * t->altura) / 2;
}

float circ_area(Circulo *c) {
    return PI * pow(c->raio, 2);
}

float area(ListaHet *p) {
    switch (p->tipo) {
        case 0:
            return ret_area((Retangulo *) p->objeto);
        case 1:
            return tri_area((Triangulo *) p->objeto);
        case 2:
            return circ_area((Circulo *) p->objeto);
        default:
            return 0;
    }
}

float max_area(ListaHet *l) {
    float max = 0;
    while (l != NULL) {
        float a = area(l);
        if (a > max) {
            max = a;
        }
        l = l->prox;
    }
    return max;
}

void libera_lista(ListaHet* l) {
    while (l != NULL) {
        ListaHet* temp = l->prox;
        free(l->objeto);
        free(l);
        l = temp;
    }
}