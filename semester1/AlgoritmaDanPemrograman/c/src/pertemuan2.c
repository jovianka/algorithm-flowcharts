#include <stdio.h>

int main() {
  // Program Nilai Mahasiswa
  int nilai_mahasiswa[3];
  int nilai_tertinggi;

  for (int i = 0; i < 3; i++){
    printf("Nilai mahasiswa ke-%d: ", i + 1);
    scanf("%d", &nilai_mahasiswa[i]);

    printf("\n");
  }

  nilai_tertinggi = nilai_mahasiswa[0];

  for (int i = 1; i < 3; i++) {
    if (nilai_mahasiswa[i] > nilai_tertinggi) {
      nilai_tertinggi = nilai_mahasiswa[i];
    }
  }

  printf("Nilai mahasiswa berurutan: ");
  for (int i = 0; i < 3; i++){
    printf("%d, ", nilai_mahasiswa[i]);
  }

  printf("\n Nilai tertinggi: %d", nilai_tertinggi);
  
  return 0;
}