#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

int main(){
    Aluno *aluno = aloca_aluno(); //aloca

    preenche(aluno); //preenche
    imprime(aluno); //imprime
    free(aluno); //liberar memoria

    return 0;
}