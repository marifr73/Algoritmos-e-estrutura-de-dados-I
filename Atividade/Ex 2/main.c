#include "lista.h"

int main(){
    No* lista = NULL;

    lista = inserir_no_inicio(lista, 8);
    lista = inserir_no_inicio(lista, 5);
    lista = inserir_no_inicio(lista, 2);
    lista = inserir_no_fim(lista, 3);

    printf("\n");
    exibir_lista(lista);

    lista = inserir_apos(lista, 2, 6);

    printf("\n");
    exibir_lista(lista);

    No *numero = buscar(3, lista);

    lista = remove_valor(lista, 6);

    printf("\n");
    exibir_lista(lista);

    No *num = remover_primeiro(lista);
    
    printf("\n");
    exibir_lista(lista);

    libera_lista(lista);
    return 0;
}
