#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estoque.h"

struct produto{
    int codigo;
    char descricao[20];
    int qnt_estoque;
};

void adicionarProdutoAoEstoque(FILE* arquivo, Produto* produto){
    //fwrite(&variavel,numero_de_bytes,numero_de_registros,arquivo);
    fwrite(produto,sizeof(Produto),1,arquivo);

}

void exibe_estoque(FILE* arquivo,Produto* produto){
    fread(produto,sizeof(Produto),1,arquivo);

    printf("\nCodigo:%d\nNome:%s\nQuantidade:%d\n",produto->codigo,produto->descricao,produto->qnt_estoque);
}

FILE* abre_arquivo(char* nome_arquivo,char* modo){
    FILE* arquivo = fopen(nome_arquivo,modo);
    if(arquivo != NULL){
        printf("arquivo aberto.\n");
        return arquivo;
    }else{
        printf("erro ao abrir o arquivo");
    }
}

Produto* cria_produto(int codigo, char* nome, int qnt_estoque){
    Produto* produto = (Produto*)malloc(sizeof(Produto));
    if(produto == NULL)
        printf("Erro ao alocar memoria");
    
    produto->codigo = codigo;
    strcpy(produto->descricao,nome);
    produto->qnt_estoque = qnt_estoque;

    return produto;
    }

void adiciona_produto(Produto* produto[], int* tam, Produto* novo_produto){
   if(*tam > MAX){
    printf("nao ha mais espaço para adicionar produto");
   }

   produto[*tam] = novo_produto;
   (*tam)++;
}

void remove_produto(Produto* produto[],int* tam, int codigo){
    int i,j;
    for(i = 0;i < *tam;i++){
        if(produto[i]->codigo == codigo){
            free(produto[i]);
        
        for(j = i;j < *tam - 1;j++){
            produto[j] = produto[j + 1];
        }
        (*tam)--;
        }
     }
    
}

void atualiza_qnt(Produto* produto, int nova_qnt,int tam){
    produto->qnt_estoque = nova_qnt;
    printf("Estoque de %s foi atualizado para %d\n",produto->descricao,produto->qnt_estoque);
}

void libera_array(Produto* produto[], int tam) {
    int i;
    for (i = 0; i < tam; i++) {
        free(produto[i]);
    }
}