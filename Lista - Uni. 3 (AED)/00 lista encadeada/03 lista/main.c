#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    No* lista = NULL;

    lista = inserir_no_inicio(lista, 5);
    lista = inserir_no_inicio(lista, 3);
    lista = inserir_no_fim(lista, 7);
    lista = inserir_no_fim(lista, 9);

    exibir_lista(lista);

    libera_lista(lista);
    return 0;
}