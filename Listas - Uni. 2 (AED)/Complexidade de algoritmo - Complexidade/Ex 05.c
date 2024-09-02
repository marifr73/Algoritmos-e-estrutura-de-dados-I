#include <stdio.h>

void selection_sort(int arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i; 
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

/*
A complexidade é O(n^2), um algoritmo mais eficiente seria o Quicksort que tem complexidade de O(n log n)
*/