// C program to print all permutations using
// Heap's algorithm

#include <stdio.h>
#include <stdlib.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Generating permutation using Heap Algorithm
void heap_permutation(char a[], int size, int n, int res_size, char** res, int* x) {
    char temp = 'x';

    // if size becomes 1 then add the obtained
    // permutation
    if (size == 1) {
        for (int i = 0; i < n; i++) {
            res[*x][i] = a[i];
        }
        *x = *x + 1;
        return;
    }

    for (int i = 0; i < size; i++) {
        heap_permutation(a, size - 1, n, res_size, res, x);

        if (i < size - 1) {
            // if size is odd, swap 0th i.e (first) and 
            // (size-1)th i.e (last) element
            if (size % 2 == 1) {
                temp = a[0];
                a[0] = a[size - 1];
                a[size - 1] = temp;
            }

            // If size is even, swap ith and 
            // (size-1)th i.e (last) element
            else {
                temp = a[i];
                a[i] = a[size - 1];
                a[size - 1] = temp;
            }
        }
    }

    return;
}

// Driver code
int main() {
    char a[] = { 'B', 'A', 'Y', 'U'};
    int n = sizeof(a) / sizeof(a[0]);
    int res_size = factorial(n);

    char** res = (char**) malloc(res_size * sizeof(char*));
    for (int i = 0; i < res_size; i++) {
        res[i] = (char*) malloc(n * sizeof(char));
    }

    int x = 0;

    heap_permutation(a, n, n, res_size, res, &x);

    for (int i = 0; i < res_size; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c, ", res[i][j]);
        }
        printf("\n");
    }

    for (int i = res_size - 1; i >= 0; i--) {
        free(res[i]);
    }
    free(res);

    printf("%d", x);
    return 0;
}