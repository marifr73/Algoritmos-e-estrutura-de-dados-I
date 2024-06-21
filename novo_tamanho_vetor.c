#include <stdio.h>
#include <stdlib.h>

void testa_tamanho(int *vetor);

int main(){
	int tamanho,novo_tamanho;
	
	printf("Digite o tamanho do vetor: ");
	scanf("%d",&tamanho);
	int * vetor = (int *) calloc(tamanho,sizeof(int));
	testa_tamanho(vetor);
	
	printf("\nDigite o novo tamanho: ");
	scanf("%d",&novo_tamanho);
	vetor = (int* )realloc(vetor,novo_tamanho*sizeof(int));
	testa_tamanho(vetor);
	
	free(vetor);
	return 0;
}

void testa_tamanho(int *vetor){
	if(vetor == NULL){
		exit(1);
	}
}