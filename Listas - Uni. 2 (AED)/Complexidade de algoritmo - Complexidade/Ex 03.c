#include <stdio.h>

int soma(int arr[], int n) {
    int soma = 0; 
    for (int i = 0; i < n; i++) { 
        soma += arr[i]; 
    }
    return soma; 
}

/*
O(n), pois vai consumir n quantidade de espaço.
*/