#include "lista.h"

int main(){
    No* lista = NULL;

    lista = inserir_no_inicio(lista, 5);
    lista = inserir_no_inicio(lista, 2);
    lista = inserir_no_fim(lista, 3);

    exibir_lista(lista);

    printf("\n\n");

    lista = remove_primeiro(lista);

    exibir_lista(lista);

    libera_lista(lista);

    return 0;
}