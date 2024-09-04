#ifndef LISTA_H
#define LISTA_H

typedef struct no No;

No* inserir_no_inicio(No* lista, int valor);

No* inserir_no_fim(No* lista, int valor);

void exibir_lista(No* lista);

#endif
