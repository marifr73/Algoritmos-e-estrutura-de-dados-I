#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno Aluno;

Aluno *criarAluno(int matricula, char nome[], float media);

void SalvarAlunoEmArquivo (char nome_do_arquivo[], Aluno *aluno);

void ExibirAluno(char nome_do_arquivo[]);
