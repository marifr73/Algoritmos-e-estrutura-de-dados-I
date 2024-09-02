#include <stdio.h>

int soma_numeros(int n) {
    int soma = 0; //c1
    for (int i = 1; i <= n; i++) { //c2(n - 1)
        soma += i; //c3(n-1)
    }
    return soma; //c4
}

/*
T(n) = c1 + c2(n - 1) + c3(n - 1) + c4
T(n) = (n - 1)(c2 + c3) + c1 + c4
T(n) = (n - 1)a + b
T(n) = na - a + b
T(n) = O(n)

E O(n) pois o laço for e executado n vezes.
*/