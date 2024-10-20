#include "lista.h"

int main() {
    No* lista = NULL;

    lista = inserir_no_inicio(lista, 5);
    lista = inserir_no_inicio(lista, 2);
    lista = inserir_no_fim(lista, 3);

    printf("\n");
    exibir_lista(lista);

    lista = inserir_no_inicio(lista, 1);
    lista = inserir_no_fim(lista, 4);

    printf("\n");
    exibir_lista(lista);

    buscar(3, lista);

    lista = remover_ultimo(lista);

    printf("\n");
    exibir_lista(lista);

    lista = remover_primeiro(lista);

    printf("\n");
    exibir_lista(lista);

    libera_lista(lista);
    return 0;
}