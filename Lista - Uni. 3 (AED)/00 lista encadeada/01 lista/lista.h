#include <stdio.h>
#include <stdlib.h>

typedef struct no No;

No* inserir_no_inicio(No* lista, int valor);

No* inserir_no_fim(No* lista, int valor);

void exibir_lista(No *lista);

No* remove_primeiro(No* lista);

void libera_lista(No *lista);