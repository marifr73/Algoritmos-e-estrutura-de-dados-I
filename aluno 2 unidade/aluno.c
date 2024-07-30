#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

//Os modulos permitem "esconder" as implementações das funções

struct aluno{
    int idade;
    char nome[20];
    long int matricula;
};

Aluno * aloca_aluno(void){
    Aluno * aluno = (Aluno*) malloc(sizeof(Aluno));
    if (aluno == NULL){
        printf("NO MEMORY!");
        exit(1);
    }
    else{
        printf("Aluno alocado!\n");
    }
    return aluno;
}

void preenche (Aluno *aluno){
    printf("Digite o nome: ");
    scanf(" %[^\n]", aluno->nome);
    getchar();
    printf("Digite a Idade e Matricula: ");
    scanf("%d %ld", &aluno->idade, &aluno->matricula);
    getchar();
}

void imprime (Aluno * aluno){
    printf("\nIdade: %d\nMatatricula: %ld\n", aluno->idade, aluno->matricula);
    printf("Nome: %s\n", aluno->nome);
}

/* PARA COMPILAR: 

gcc -c aluno.c
gcc -c main.c
gcc -o main.exe aluno.o main.o */