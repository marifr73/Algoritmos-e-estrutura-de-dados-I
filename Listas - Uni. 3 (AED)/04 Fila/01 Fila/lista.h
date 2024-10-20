#ifndef FILA_LISTA_H
#define FILA_LISTA_H

typedef struct fila_lista FilaLista;
typedef struct no No;

FilaLista* fila_lista_cria(void);
void fila_lista_insere(FilaLista* f, float v);
float fila_lista_retira(FilaLista* f);
int fila_lista_vazia(FilaLista* f);
void fila_lista_imprime(FilaLista* f);
void fila_lista_libera(FilaLista* f);

#endif // FILA_LISTA_H
