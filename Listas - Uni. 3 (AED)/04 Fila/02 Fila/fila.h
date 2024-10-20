#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;
typedef struct no No;

Fila* fila_cria(void);
void fila_insere(Fila* f, float v);
float fila_retira(Fila* f);
int fila_vazia(Fila* f);
void fila_imprime(Fila* f);
void fila_libera(Fila* f);

void combina_filas(Fila* f_res, Fila* f1, Fila* f2);

#endif // FILA_H
