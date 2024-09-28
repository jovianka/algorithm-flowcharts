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
  struct Node *prev;
} Node;

typedef struct
{
  Node *head;
  Node *tail;
  int node_count;
  int max;
} RingBuffer;

RingBuffer initialize_ring_buffer(int max_length)
{
  RingBuffer new_buffer;
  new_buffer.max = max_length;
  new_buffer.node_count = 0;
  new_buffer.head = NULL;
  new_buffer.tail = NULL;

  return new_buffer;
}

void enqueue_mahasiswa(RingBuffer *queue, Mahasiswa mhs)
{
  if (queue->node_count == queue->max)
  {
    printf("QUEUE IS ALREADY FULL!");
    return;
  }

  if (queue->node_count == 0)
  {
    Node *new_node = malloc(sizeof(Node));
    new_node->mhs = mhs;
    queue->head = new_node;
    queue->tail = new_node;

    new_node->next = new_node;
    new_node->prev = new_node;
    queue->node_count += 1;
    return;
  }

  Node *new_node = malloc(sizeof(Node));
  new_node->mhs = mhs;
  queue->tail->next = new_node;
  new_node->prev = queue->tail;

  queue->tail = queue->tail->next;
  queue->tail->next = queue->head;
  queue->head->prev = queue->tail;
  queue->node_count += 1;

  return;
}

void dequeue_mahasiswa(RingBuffer *queue)
{
  if (queue->node_count == 0)
  {
    printf("QUEUE IS ALREADY EMPTY!");
    return;
  }

  if (queue->node_count == 1)
  {
    Node *temp = queue->head;
    queue->head = NULL;

    queue->tail->next = NULL;

    free(temp);
    queue->node_count -= 1;

    return;
  }

  Node *temp = queue->head;
  queue->head = queue->head->next;

  queue->tail->next = queue->head;

  free(temp);
  queue->node_count -= 1;

  return;
}

void free_ring_buffer(RingBuffer *queue)
{
  while (queue->node_count != 0)
  {
    dequeue_mahasiswa(queue);
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
  RingBuffer queue = initialize_ring_buffer(max);

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
      if (queue.node_count == queue.max)
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

      enqueue_mahasiswa(&queue, new_mhs);

      break;
    }

    case 2:
    {
      if (queue.node_count == 0)
      {
        printf("Queue is empty!\n");
        break;
      }
      int nominal_bayar = 0;
      Mahasiswa mhs = queue.head->mhs;
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
        dequeue_mahasiswa(&queue);
      }
      else
      {
        printf("Nominal sekarang: %d (BELUM LUNAS)\n", mhs.nominal - nominal_bayar);
        mhs.nominal -= nominal_bayar;
        queue.head->mhs.nominal = mhs.nominal;
      }
      break;
    }

    case 3:
    {
      if (queue.node_count == 0)
      {
        printf("Queue is empty!\n");
        break;
      }
      Node *temp = queue.head;
      Mahasiswa mhs;

      printf("Nama\tNIM\tUKT\tNominal\n");
      while (temp != queue.tail)
      {
        mhs = temp->mhs;
        printf("%s\t%s\t%d\t%d\n", mhs.nama, mhs.nim, mhs.ukt, mhs.nominal);
        temp = temp->next;
      }
      mhs = temp->mhs;
      printf("%s\t%s\t%d\t%d\n", mhs.nama, mhs.nim, mhs.ukt, mhs.nominal);
      break;
    }

    case 4:
      exit = 1;
      break;
    }
  }
}