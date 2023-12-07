// C program to print all permutations using
// Heap's algorithm

#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// Generating permutation using Heap Algorithm
void heap_permutation(char a[], int size, int n) {
    char temp = 'x';

    // if size becomes 1 then print the obtained
    // permutation
    if (size == 1) {
        for (int i = 0; i < n; i++) {
            printf("%c, ", a[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        heap_permutation(a, size - 1, n);

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
    char a[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int n = sizeof(a) / sizeof(a[0]);
    int res_size = factorial(n);

    heap_permutation(a, n, n);

    return 0;
}