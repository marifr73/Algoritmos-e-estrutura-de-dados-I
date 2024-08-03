#include<stdio.h>

int comprimento (char *s){
    int i;
    int n = 0; /* Contador */
    for(i = 0; s[i] != '\0'; i++)
        n++;
    return n;
}

void copia (char *dest, char* orig){
    int i;
    for (i = 0; orig[i] != '\0'; i++)
        dest[i] = orig[i];
        /* Fecha a cadeia capiada */
    dest[i] = '\0';
}

void concatena (char * dest, char * orig){
    int i = 0;/* Indice usada na cadeia destino, inicializada com zero */
    int j; /* Indece udsada na cadeia origem */
    /* acha elementos da origem para o final do destino */
    while (dest[i] != '\0')
        i++;
    /* Copia elementos da origem para o final do destino */
    for(j = 0; orig[j] != '\0'; j++){
        dest[i] = orig[j];
        i++;
    }
    /* Fecha cadeia destino */
    dest[i] = '\0';
}