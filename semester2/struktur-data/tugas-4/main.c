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

typedef struct Book
{
  char title[255];
  int pages;
  char publisher[255];
} Book;

int main()
{

  int exit = 0;
  int max_stack_size = 0;
  printf("Program tumpukan buku\n");
  printf("Ketik jumlah maksimum tumpukan buku: ");
  get_int(&max_stack_size);

  Book book_stack[max_stack_size];
  int last_book = -1;

  memset(book_stack, 0, max_stack_size * sizeof(Book));

  while (exit != 1)
  {
    int option = 0;
    printf("\n[1] Tambah Buku\n[2] Ambil Buku\n[3] Keluar\n");
    printf("Pilihan: ");
    get_int(&option);
    switch (option)
    {
    case 1:
    {
      if (last_book + 1 < max_stack_size)
      {
        Book new_book;
        printf("\nKetik Judul Buku: ");
        fgets(new_book.title, sizeof(new_book.title), stdin);
        new_book.title[strcspn(new_book.title, "\n")] = 0;
        printf("Ketik Jumlah Halaman: ");
        get_int(&(new_book.pages));
        printf("Penerbit: ");
        fgets(new_book.publisher, sizeof(new_book.publisher), stdin);
        new_book.publisher[strcspn(new_book.publisher, "\n")] = 0;
        book_stack[last_book + 1] = new_book;
        last_book += 1;
        break;
      }
      else
      {
        printf("\nBook stack is full!\n");
        break;
      }
    }

    case 2:
    {
      char buf[3];
      printf("Anda Yakin (Y/t) ");
      fgets(buf, sizeof(buf), stdin);
      buf[strcspn(buf, "\n")] = 0;
      if (strcmp(buf, "Y") != 1 || strcmp(buf, "y") == 1 || strcmp(buf, "") == 1)
      {
        if (last_book > -1)
        {
          printf("\nBuku dengan judul %s telah diambil.\n", book_stack[last_book].title);
          memset(&(book_stack[last_book]), 0, sizeof(Book));
          last_book -= 1;
          break;
        }
        else
        {
          printf("\nTidak ada buku untuk diambil!\n");
          break;
        }
      }
      else if (strcmp(buf, "T") == 1 || strcmp(buf, "t") == 1)
      {
        break;
      }
    }

    case 3:
    {
      char buf[3];
      printf("Anda Yakin (Y/t) ");
      fgets(buf, sizeof(buf), stdin);
      buf[strcspn(buf, "\n")] = 0;
      if (strcmp(buf, "Y") != 1 || strcmp(buf, "y") == 1 || strcmp(buf, "") == 1)
      {
        exit = 1;
        printf("\nTerima kasih\n");
        break;
      }
      else if (strcmp(buf, "T") == 1 || strcmp(buf, "t") == 1)
      {
        break;
      }
    }
    }
  }
}