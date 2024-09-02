#include <stdio.h>

int busca_linear(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

/*

T(n) = c1(n) + c2(1)
T(n) = c1(n) + b
T(n)= an + b
T(n) = O(n)

O pior caso da busca linear é O(n), ou seja, o item procurado estaria na ultima posição do array.
A busca binária em um array ordenado tem complexidade O(log n), que acaba sendo mais efetiva do que a linear.
*/