#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//postar no github
void ler_vetor(float *vetor, int tamanho);
void exibe_vetor(float *vetor, int tamanho);
void linha();

float * cria_vetor(int tamanho);

int main(){
	setlocale(LC_ALL,"portuguese");
	int tamanho = 5;
    float * vetor = cria_vetor(5);
    
    ler_vetor(vetor,tamanho);
    linha();
    exibe_vetor(vetor,tamanho);
    free(vetor);//libera a memória para utilizar futuramente

	free(vetor);
    return 0;
}

void ler_vetor(float *vetor, int tamanho){
	int i;
	for(i = 0;i < tamanho;i++){
        printf("Digite o %dº número: ",i + 1);
        scanf("%f",&vetor[i]);
    }
}

void exibe_vetor(float *vetor, int tamanho){
	int i;
	
	for(i = 0;i < tamanho;i++){
    	printf("%dº número: %.1f\n",i + 1,vetor[i]);    
    }
	
}

void linha(){
	printf("\n\n");
}

float * cria_vetor(int tamanho){
    float *vetor = (float*)malloc(tamanho * sizeof(float));
    if(vetor == NULL){
        exit(1);
    }
    return vetor;
}