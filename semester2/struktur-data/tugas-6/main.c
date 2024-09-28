#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// UTIL
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

// RING BUFFER

typedef struct
{
  char nama[32];
  char nim[32];
  int ukt;
  int nominal;
} Mahasiswa;

typedef struct Node
{
  Mahasiswa mhs;
  struct Node *next;
} Node;

typedef struct
{
  Node *head;
  Node *tail;
  int node_count;
  int max;
} RingBuffer;

RingBuffer *initialize_ring_buffer(int max_length)
{
  RingBuffer *new_buffer = malloc(sizeof(RingBuffer));
  new_buffer->max = max_length;
  new_buffer->node_count = 0;
  new_buffer->head = NULL;
  new_buffer->tail = NULL;
}

void enqueue_mahasiswa(RingBuffer *queue, Mahasiswa mhs)
{
  if (queue->node_count == queue->max)
  {
    printf("Queue is full!\n");
    return;
  }

  Node *temp;
  temp = queue->head;

  if (queue->node_count == 0)
  {
    Node *new_mhs = malloc(sizeof(Node));
    new_mhs->mhs = mhs;
    queue->head = new_mhs;
    queue->tail = queue->head;

    queue->node_count += 1;
    return;
  }

  while (temp->next != NULL)
  {
    temp = temp->next;
  }

  Node *new_mhs = malloc(sizeof(Node));
  new_mhs->mhs = mhs;

  temp->next = new_mhs;
  queue->tail = queue->tail->next;
  queue->node_count += 1;
}

void dequeue_mahasiswa(RingBuffer *queue)
{
  if (queue->node_count == 0)
  {
    printf("Queue is empty!\n");
    return;
  }

  Node *temp;
  temp = queue->head;
  queue->head = queue->head->next;
  free(temp);
  queue->node_count -= 1;
}

void free_ring_buffer(RingBuffer *queue)
{
  Node *temp = queue->tail;
  while (temp != NULL)
  {
    queue->head = queue->head->next;
    free(temp);
    temp = queue->head;
  }
}

int main()
{
  int exit = 0;
  int max = 0;
  int pilihan = 0;

  printf("PROGRAM ANTRIAN PEMBAYARAN UKT\n");
  printf("Input Maks Antrian dalam 1 waktu: ");

  get_int(&max);
  RingBuffer *queue = initialize_ring_buffer(max);

  printf("\n");

  while (exit == 0)
  {
    printf("Menu:\n");
    printf("[1] Tambah Antrian\n");
    printf("[2] Proses Pembayaran\n");
    printf("[3] Lihat Antrian\n");
    printf("[4] Keluar\n");
    printf("Pilihan: ");
    get_int(&pilihan);

    printf("\n");

    switch (pilihan)
    {
    case 1:
    {
      if (queue->node_count == queue->max)
      {
        printf("Queue is full!\n");
        break;
      }
      Mahasiswa new_mhs;
      printf("Input Data Mahasiswa\n");

      printf("Nama: ");
      fgets(new_mhs.nama, sizeof(new_mhs.nama), stdin);
      new_mhs.nama[strcspn(new_mhs.nama, "\n")] = 0; // Remove newline from string

      printf("NIM: ");
      fgets(new_mhs.nim, sizeof(new_mhs.nim), stdin);
      new_mhs.nim[strcspn(new_mhs.nim, "\n")] = 0; // Remove newline from string

      printf("UKT: ");
      get_int(&new_mhs.ukt);

      printf("Nominal: ");
      get_int(&new_mhs.nominal);

      printf("\n");

      enqueue_mahasiswa(queue, new_mhs);

      break;
    }

    case 2:
    {
      if (queue->node_count == 0)
      {
        printf("Queue is empty!\n");
        break;
      }
      int nominal_bayar = 0;
      Mahasiswa mhs = queue->head->mhs;
      printf("Data Mahasiswa\n");
      printf("Nama: %s\n", mhs.nama);
      printf("NIM: %s\n", mhs.nama);
      printf("UKT: %d\n", mhs.ukt);
      printf("Nominal: %d\n", mhs.nominal);

      printf("Nominal bayar: ");
      get_int(&nominal_bayar);

      if (nominal_bayar >= mhs.nominal)
      {
        printf("Kembalian: %d\n", nominal_bayar - mhs.nominal);
        dequeue_mahasiswa(queue);
      }
      else
      {
        printf("Nominal sekarang: %d (BELUM LUNAS)\n", mhs.nominal - nominal_bayar);
        mhs.nominal -= nominal_bayar;
        queue->head->mhs.nominal = mhs.nominal;
      }
      break;
    }

    case 3:
    {
      if (queue->node_count == 0)
      {
        printf("Queue is empty!\n");
        break;
      }
      Node *temp = queue->head;
      Mahasiswa mhs;

      printf("Nama\t\tNIM\tUKT\tNominal\n");
      while (temp != NULL)
      {
        mhs = temp->mhs;
        printf("%s\t%s\t%d\t%d\n", mhs.nama, mhs.nim, mhs.ukt, mhs.nominal);
        temp = temp->next;
      }
      break;
    }

    case 4:
      exit = 1;

      free_ring_buffer(queue);
      free(queue);
      break;
    }
  }
}