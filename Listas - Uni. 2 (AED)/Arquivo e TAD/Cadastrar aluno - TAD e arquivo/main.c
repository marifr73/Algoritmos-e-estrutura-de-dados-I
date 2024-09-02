#include "aluno.h"

int main(){
    Aluno *aluno = criarAluno(123, "MARIA", 8.5);
    SalvarAlunoEmArquivo("aluno.txt", aluno);
    ExibirAluno("aluno.txt");
    return 0;
}