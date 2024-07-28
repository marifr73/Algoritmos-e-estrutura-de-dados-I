/*Escreva um programa em C que solicite ao usuário o tamanho de um vetor e, em seguida, aloque
dinamicamente memória para armazenar esse vetor. Depois disso, peça ao usuário que insira os
elementos do vetor e, por fim, imprima os elementos na ordem inversa.*/

#include<stdio.h>
#include<stdlib.h>

void preencher_vetor(int tamanho, int *vetor){
    int count;
    
    printf("\nInforme os elementos do vetor: \n");

    for(count = 0; count < tamanho; count++){
        scanf("%d", &vetor[count]);
    }
}

void imprime (int tamanho, int *vetor){
    int count;
    printf("Vetor inverso: \t");
    for (count = tamanho-1; count >= 0; count--)
    {
        printf("%d \t", vetor[count]);
    }
}

int * aloca_vetor(int tamanho){
    int *vetor = (int*) malloc(tamanho* sizeof (int));
    if (vetor == NULL){
        printf("No memory\n");
        exit(1);
    } else{
        printf("Vetor alocado com sucesso\n");
    }
    return vetor;
}

int main (void){
    int tamanho;
    printf("Informe o tamanho do vetor: \t");
    scanf("%d", &tamanho);
    
    //Aloca vetor
    int * vetor = aloca_vetor(tamanho);
    
    //Elementos do vetor
    preencher_vetor (tamanho, vetor);

    //Imprimei vetor inverso
    imprime(tamanho, vetor);

    free(vetor);
    return 0;
}