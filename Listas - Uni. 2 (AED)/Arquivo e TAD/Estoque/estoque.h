#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct produto Produto;

//função para abrir arquivo
FILE* abre_arquivo(char* nome_arquivo,char* modo);

//função que adiciona uma struct de produto ao arquivo.bin
void adicionarProdutoAoEstoque(FILE* arquivo, Produto* produto);

//função que inicializa produto(preenche a struct)
Produto* cria_produto(int codigo, char* nome, int qnt_estoque);

//função que adiciona struct preenchida ao array
void adiciona_produto(Produto* produto[], int* tam, Produto* novo_produto);

//função que lê o produto do arquivo e exibe no terminal
void exibe_estoque(FILE* arquivo,Produto* produto);

//função que atualiza a quantidade de cada produto
void atualiza_qnt(Produto* produto, int nova_qnt,int tam);

//função que remove o produto
void remove_produto(Produto* produto[],int* tam, int codigo);

//função que libera o array
void libera_array(Produto* produto[], int tam);


#endif // ESTOQUE_H