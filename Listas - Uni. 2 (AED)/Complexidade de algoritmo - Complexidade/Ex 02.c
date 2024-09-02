#include <stdio.h>

//Algoritmo A:
void algoritmo_a(int n) {
    for (int i = 0; i < n; i++) { // c1
        for (int j = 0; j < n; j++) { // c2 n^2
            printf("%d, %d\n", i, j); // c3 n^2
        }
    }
}

//Algoritmo B:
void algoritmo_b(int n) {
    for (int i = 0; i < n; i++) { // c1
        printf("%d\n", i); 
    }

    for (int j = 0; j < n; j++) { // c2
        printf("%d\n", j); 
    }
}

/*
A:
T(n) = c1 + c2n + c3n + c4
T(n) = (c2 + c3)n^2 + (c1 + c4)
T(n) = n^2a + b
T(n) = n^2a
T(n) = n^2
O(n^2)
*/

/*
B:
T(n) = (n)(c1 + c2)
T(n) = na
T(n) = n
O(n)

O melhor e a B, pois e linear.
*/