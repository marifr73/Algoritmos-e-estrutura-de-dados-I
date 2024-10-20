#ifndef FILA_VETOR_H
#define FILA_VETOR_H

typedef struct fila_vetor FilaVetor;

FilaVetor* fila_vetor_cria(void);
void fila_vetor_insere(FilaVetor* f, float v);
float fila_vetor_retira(FilaVetor* f);
int fila_vetor_vazia(FilaVetor* f);
void fila_vetor_imprime(FilaVetor* f);
void fila_vetor_libera(FilaVetor* f);

#endif // FILA_VETOR_H
