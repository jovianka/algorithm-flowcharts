#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief
 *
 * Get floating point number input.
 *
 * @param float pointer to the variable to be assigned to input.
 */
void get_float(float *num)
{
  char buf[100];
  if (fgets(buf, sizeof(buf), stdin))
  {
    sscanf(buf, "%f", num);
  }
}

/**
 * @brief
 *
 * Get integer input.
 *
 * @param float pointer to the variable to be assigned to input.
 */
void get_int(int *num)
{
  char buf[100];
  if (fgets(buf, sizeof(buf), stdin))
  {
    sscanf(buf, "%d", num);
  }
}

int main()
{
  int nomor;
  char nama[255];
  int nilai_teori;
  int nilai_praktek;
  int nilai_total;
  int nilai_rata;
  char status[32];

  printf("Ketik Data Peserta Kompetisi:");

  printf("\nNo Peserta: ");
  get_int(&nomor);

  printf("Nama: ");
  fgets(nama, sizeof(nama), stdin);
  nama[strcspn(nama, "\n")] = 0; // Remove newline from string

  printf("Nilai Teori: ");
  get_int(&nilai_teori);

  printf("Nilai Praktek: ");
  get_int(&nilai_praktek);

  nilai_total = nilai_praktek + nilai_teori;
  nilai_rata = nilai_total / 2;

  printf("Nilai Total: %d", nilai_total);
  printf("\nRata: %d", nilai_rata);

  if (60 <= nilai_rata)
  {
    printf("\nStatus: Lulus\n");
  }
  else
  {
    printf("\nStatus: Gagal\n");
  }
}