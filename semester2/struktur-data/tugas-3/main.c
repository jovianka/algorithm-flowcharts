#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pasien
{
  char nama[255];
  float berat;
  float tinggi;

} Pasien;

void get_float(float *num)
{
  char buf[100];
  if (fgets(buf, sizeof(buf), stdin))
  {
    sscanf(buf, "%f", num);
  }
}

void get_int(int *num)
{
  char buf[100];
  if (fgets(buf, sizeof(buf) / sizeof(buf[0]), stdin))
  {
    sscanf(buf, "%d", num);
  }
}

int main()
{
  int jumlah_pasien;
  printf("Ketik Jumlah Pasien: ");
  get_int(&jumlah_pasien);
  printf("\n");

  Pasien *patients = (Pasien *)malloc(jumlah_pasien * sizeof(Pasien));

  for (int i = 0; i < jumlah_pasien; i++)
  {
    printf("Data %d\n", i + 1);

    Pasien pasien;
    printf("Nama: ");
    fgets(pasien.nama, sizeof(pasien.nama) - 1, stdin);
    pasien.nama[strcspn(pasien.nama, "\n")] = 0;
    printf("Berat Badan: ");
    get_float(&pasien.berat);
    printf("Tinggi Badan: ");
    get_float(&pasien.tinggi);

    patients[i] = pasien;
    printf("\n");
  }

  Pasien *pasien_berat_terendah = &patients[0];
  float rata_berat = 0;
  Pasien *pasien_tinggi_terendah = &patients[0];
  float rata_tinggi = 0;

  for (int i = 0; i < jumlah_pasien; i++)
  {
    if (patients[i].berat < pasien_berat_terendah->berat)
    {
      pasien_berat_terendah = &patients[i];
    }
    if (patients[i].tinggi < pasien_tinggi_terendah->tinggi)
    {
      pasien_tinggi_terendah = &patients[i];
    }
    rata_berat += patients[i].berat;
    rata_tinggi += patients[i].tinggi;
  }

  rata_berat /= jumlah_pasien;
  rata_tinggi /= jumlah_pasien;

  printf("Berat Terendah: %.2f (%s)\n", pasien_berat_terendah->berat, pasien_berat_terendah->nama);
  printf("Rata-Rata Berat: %.2f\n", rata_berat);
  printf("Tinggi Terendah: %.2f (%s)\n", pasien_tinggi_terendah->tinggi, pasien_tinggi_terendah->nama);
  printf("Rata-Rata Tinggi: %.2f\n", rata_tinggi);

  free(patients);
}