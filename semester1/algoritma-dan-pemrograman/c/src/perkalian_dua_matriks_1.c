#include <stdio.h>

int* multiply_matrix(int a_rows, int a_cols, int b_rows, int b_cols, int a[a_rows][a_cols], int b[b_rows][b_cols]) {

    // NAIVE APPROACH
        // Input: matrices A and B
        // Let C be a new matrix of the appropriate size
        // For i from 1 to n:
        //     For j from 1 to p:
        //         Let sum = 0
        //         For k from 1 to m:
        //             Set sum ← sum + Aik × Bkj
        //         Set Cij ← sum
        // Return C


    static int c[a_rows][b_cols];
    int sum = 0;
    
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            for (int k = 0; k < a_cols; k++) {
                sum += a[i][k] * b[k][j];
            }
            c[i][j] = sum;
            sum = 0;
        }
    }

    return c;

}

int main() {
    // Deklarasi orde matriks A dan B
    int a_rows;
    int a_cols;
    int b_rows;
    int b_cols;
    
    printf("=========================\n");
    printf("PROGRAM PERKALIAN MATRIKS\n");
    printf("=========================\n");

    // Inisialisasi orde matriks dengan input dari user
    printf("Masukkan jumlah baris matriks pertama: ");
    scanf("%d", &a_rows);
    printf("Masukkan jumlah kolom matriks pertama: ");
    scanf("%d", &a_cols);
    printf("Masukkan jumlah baris matriks kedua: ");
    scanf("%d", &b_rows);
    printf("Masukkan jumlah kolom matriks kedua: ");
    scanf("%d", &b_cols);
    
    // Pemeriksaan syarat perkalian matriks
    if (a_cols != b_rows) {
        printf("Tidak dapat mengalikan matriks a dengan b");
        return 0;
    }

    // Deklarasi matriks A dan B
    int a[a_rows][a_cols];
    int b[b_rows][b_cols];

    
    // Inisialisasi nilai matriks dengan input dari user
    printf("Masukkan elemen matriks pertama:\n");
    for (int i = 0; i < a_rows; i++) {
        printf("Baris ke-%d\n", i + 1);
        for (int j = 0; j < a_cols; j++) {
            printf("\tKolom ke-%d: ", j + 1);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Masukkan elemen matriks kedua:\n");
    for (int i = 0; i < b_rows; i++) {
        printf("Baris ke-%d\n", i + 1);
        for (int j = 0; j < b_cols; j++) {
            printf("\tKolom ke-%d: ", j + 1);
            scanf("%d", &b[i][j]);
        }
        printf("\n");
    }

    int* c = multiply_matrix(a_rows, a_cols, b_rows, b_cols, a, b);

    // print hasil kali matriks
    
    printf("Hasil a x b: \n");
    
    for (int i = 0; i < a_rows; i++) {
        printf("\tbaris ke-%d: ", i + 1);
        
        for (int j = 0; j < b_cols; j++) {
            printf("%d, ", c[i][j]);
        }
        
        printf("\n");
    }
    

    return 0;
}