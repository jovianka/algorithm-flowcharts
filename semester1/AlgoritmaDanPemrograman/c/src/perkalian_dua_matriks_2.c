// Akses elemen seperti array
// #include <stdio.h>
// #include <stdlib.h>

// int print_multiplied_matrix(int a_rows, int a_cols, int b_rows, int b_cols, int** a, int** b) {

//     // NAIVE APPROACH
//         // Input: matrices A and B
//         // Let C be a new matrix of the appropriate size
//         // For i from 1 to n:
//         //     For j from 1 to p:
//         //         Let sum = 0
//         //         For k from 1 to m:
//         //             Set sum ← sum + Aik × Bkj
//         //         Set Cij ← sum
//         // Return C


//     int c[a_rows][b_cols];
//     int sum = 0;
    
//     for (int i = 0; i < a_rows; i++) {
//         for (int j = 0; j < b_cols; j++) {
//             for (int k = 0; k < a_cols; k++) {
//                 sum += a[i][k] * b[k][j];
//             }
//             c[i][j] = sum;
//             sum = 0;
//         }
//     }
    
//     printf("Hasil a x b: \n");
    
//     for (int i = 0; i < a_rows; i++) {
//         printf("\tbaris ke-%d: ", i + 1);
        
//         for (int j = 0; j < b_cols; j++) {
//             printf("%d, ", c[i][j]);
//         }
        
//         printf("\n");
//     }

// }

// int main() {
//     // Deklarasi orde matriks A dan B
//     int a_rows;
//     int a_cols;
//     int b_rows;
//     int b_cols;
    
//     printf("=========================\n");
//     printf("PROGRAM PERKALIAN MATRIKS\n");
//     printf("=========================\n");

//     // Inisialisasi orde matriks dengan input dari user
//     printf("Masukkan jumlah baris matriks pertama: ");
//     scanf("%d", &a_rows);
//     printf("Masukkan jumlah kolom matriks pertama: ");
//     scanf("%d", &a_cols);
//     printf("Masukkan jumlah baris matriks kedua: ");
//     scanf("%d", &b_rows);
//     printf("Masukkan jumlah kolom matriks kedua: ");
//     scanf("%d", &b_cols);
    
//     // Pemeriksaan syarat perkalian matriks
//     if (a_cols != b_rows) {
//         printf("Tidak dapat mengalikan matriks a dengan b");
//         return 0;
//     }

//     // Deklarasi matriks A dan B
//     int** a = (int**) malloc(a_rows * sizeof(int*));
//     int** b = (int**) malloc(b_rows * sizeof(int*));

//     for (int i = 0; i < a_cols; i++) {
//       a[i] = (int*) malloc(a_cols * sizeof(int));
//     }

//     for (int i = 0; i < a_cols; i++) {
//       b[i] = (int*) malloc(b_cols * sizeof(int));
//     }

    
//     // Inisialisasi nilai matriks dengan input dari user
//     printf("Masukkan elemen matriks pertama:\n");
//     for (int i = 0; i < a_rows; i++) {
//         printf("Baris ke-%d\n", i + 1);
//         for (int j = 0; j < a_cols; j++) {
//             printf("\tKolom ke-%d: ", j + 1);
//             scanf("%d", &a[i][j]);
//         }
//     }

//     printf("Masukkan elemen matriks kedua:\n");
//     for (int i = 0; i < b_rows; i++) {
//         printf("Baris ke-%d\n", i + 1);
//         for (int j = 0; j < b_cols; j++) {
//             printf("\tKolom ke-%d: ", j + 1);
//             scanf("%d", &b[i][j]);
//         }
//         printf("\n");
//     }
    
//     // print hasil kali matriks
//     print_multiplied_matrix(a_rows, a_cols, b_rows, b_cols, a, b);

//     return 0;
// }


// Akses elemen dengan pointer arithmetic
#include <stdio.h>
#include <stdlib.h>

int print_multiplied_matrix(int a_rows, int a_cols, int b_rows, int b_cols, int** a, int** b) {

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


    int** c = (int**) malloc(a_rows * sizeof(int*));

    for (int i = 0; i < a_rows; i++) {
      *(c + i) = (int*) malloc(b_cols * sizeof(int));
    }

    int sum = 0;
    
    for (int i = 0; i < a_rows; i++) {
        for (int j = 0; j < b_cols; j++) {
            for (int k = 0; k < a_cols; k++) {
                sum += *(*(a + i) + k) * *(*(b + k) + j);
            }
            *(*(c + i) + j) = sum;
            c[i][j] = sum;
            sum = 0;
        }
    }
    
    printf("Hasil a x b: \n");
    
    for (int i = 0; i < a_rows; i++) {
        printf("\tbaris ke-%d: ", i + 1);
        
        for (int j = 0; j < b_cols; j++) {
            printf("%d, ", *(*(c + i) + j));
        }
        
        printf("\n");
    }

    for (int i = a_rows - 1; i >= 0; i--) {
      free(*(c + i));
    }
    free(c);

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
    int** a = (int**) malloc(a_rows * sizeof(int*));
    for (int i = 0; i < a_rows; i++) {
      *(a + i) = (int*) malloc(a_cols * sizeof(int));
    }

    int** b = (int**) malloc(b_rows * sizeof(int*));
    for (int i = 0; i < b_rows; i++) {
      *(b + i) = (int*) malloc(b_cols * sizeof(int));
    }

    
    // Inisialisasi nilai matriks dengan input dari user
    printf("Masukkan elemen matriks pertama:\n");
    for (int i = 0; i < a_rows; i++) {
        printf("Baris ke-%d\n", i + 1);
        for (int j = 0; j < a_cols; j++) {
            printf("\tKolom ke-%d: ", j + 1);
            scanf("%d", &(*(*(a + i) + j)));
        }
    }

    printf("Masukkan elemen matriks kedua:\n");
    for (int i = 0; i < b_rows; i++) {
        printf("Baris ke-%d\n", i + 1);
        for (int j = 0; j < b_cols; j++) {
            printf("\tKolom ke-%d: ", j + 1);
            scanf("%d", &(*(*(b + i) + j)));
        }
        printf("\n");
    }
    
    // print hasil kali matriks
    print_multiplied_matrix(a_rows, a_cols, b_rows, b_cols, a, b);

    for (int i = a_rows - 1; i >= 0; i--) {
      free(*(a + i));
    }
    free(a);

    for (int i = b_rows - 1; i >= 0; i--) {
      free(*(b + i));
    }
    free(b);

    return 0;
}