#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mhs
{
  char nama[32];
  float nilai_kuis;
  float nilai_tugas;
  float nilai_uts;
  float nilai_uas;
  float nilai_total;
  char grade;
} Mhs;

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
  int jumlah_mhs;

  printf("NILAI MAHASISWAMU!\n");
  printf("Ketik Jumlah Mahasiswa: ");
  get_int(&jumlah_mhs);
  printf("\n");
  Mhs mahasiswas[jumlah_mhs];

  for (int i = 0; i < jumlah_mhs; i++)
  {
    Mhs mahasiswa;
    printf("Mhs-%d\n", i + 1);

    printf("Nama= ");
    fgets(mahasiswa.nama, sizeof(mahasiswa.nama), stdin);
    mahasiswa.nama[strcspn(mahasiswa.nama, "\n")] = 0; // Remove newline from string

    printf("Kuis= ");
    get_float(&mahasiswa.nilai_kuis);

    printf("Tugas= ");
    get_float(&mahasiswa.nilai_tugas);

    printf("UTS= ");
    get_float(&mahasiswa.nilai_uts);

    printf("UAS= ");
    get_float(&mahasiswa.nilai_uas);
    printf("\n");

    mahasiswa.nilai_total = 0.2 * (mahasiswa.nilai_kuis + mahasiswa.nilai_tugas) + 0.3 * (mahasiswa.nilai_uas + mahasiswa.nilai_uts);

    if (mahasiswa.nilai_total >= 80.00)
    {
      mahasiswa.grade = 'A';
    }
    else if (mahasiswa.nilai_total >= 65.00)
    {
      mahasiswa.grade = 'B';
    }
    else if (mahasiswa.nilai_total >= 50.00)
    {
      mahasiswa.grade = 'C';
    }
    else if (mahasiswa.nilai_total >= 30.00)
    {
      mahasiswa.grade = 'D';
    }
    else if (mahasiswa.nilai_total < 30.00)
    {
      mahasiswa.grade = 'E';
    }

    mahasiswas[i] = mahasiswa;
  }

  printf("Hasil: \n");
  for (int i = 0; i < jumlah_mhs; i++)
  {
    if (mahasiswas[i].grade)
    {
      printf("%d. %s: %c (%.2f)\n", i + 1, mahasiswas[i].nama, mahasiswas[i].grade, mahasiswas[i].nilai_total);
    }
  }
}