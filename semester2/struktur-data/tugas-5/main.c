#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
typedef struct UKTTransaction
{
    char nama[256];
    char nim[11];
    int ukt;
    int nominal;
} UKTTransaction;

typedef struct RBQueue
{
    UKTTransaction *transactions;
    int front;
    int rear;
    int has_elements;
    int max;
} RBQueue;

void init_ring_transactions(RBQueue *queue, int max)
{
    queue->transactions = calloc(max, sizeof(UKTTransaction));
    queue->front = 0;
    queue->rear = 0;
    queue->has_elements = 0;
    queue->max = max;
}

void rb_enqueue(UKTTransaction new_transaction, RBQueue *queue)
{

    if (queue->has_elements == 1 && queue->front == queue->rear)
    {
        printf("Queue is full!\n\n");
        return;
    }

    queue->transactions[queue->rear] = new_transaction;
    queue->rear = (queue->rear + 1) % queue->max;
    queue->has_elements = 1;
}

void rb_dequeue(RBQueue *queue)
{
    queue->front = (queue->front + 1) % queue->max;

    if (queue->front == queue->rear)
    {
        queue->has_elements = 0;
    }

    return;
}

void print_ukt_queue(RBQueue *queue)
{
    printf("Nama\t\tNIM\tUKT\tNominal\n");
    int i = queue->front;

    if (queue->has_elements == 1 && queue->front == queue->rear)
    {
        while (i != (queue->rear + 1) % queue->max)
        {
            printf("%s\t\t%s\t%d\t%d\n",
                   queue->transactions[i].nama,
                   queue->transactions[i].nim,
                   queue->transactions[i].ukt,
                   queue->transactions[i].nominal);
            i = (i + 1) % queue->max;
        }
        printf("%s\t\t%s\t%d\t%d\n",
               queue->transactions[i].nama,
               queue->transactions[i].nim,
               queue->transactions[i].ukt,
               queue->transactions[i].nominal);
        return;
    }

    while (i != queue->rear)
    {
        printf("%s\t\t%s\t%d\t%d\n",
               queue->transactions[i].nama,
               queue->transactions[i].nim,
               queue->transactions[i].ukt,
               queue->transactions[i].nominal);
        i = (i + 1) % queue->max;
    }
    printf("\n");
}

int main()
{
    int exit = 0;
    int max = 0;
    int pilihan = 0;

    printf("PROGRAM ANTRIAN PEMBAYARAN UKT\n");
    printf("Input Maks Antrian dalam 1 waktu: ");

    get_int(&max);
    RBQueue queue;
    init_ring_transactions(&queue, max);

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
            UKTTransaction new_mhs;
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

            rb_enqueue(new_mhs, &queue);

            break;
        }

        case 2:
        {
            if (queue.has_elements == 0 && queue.front == queue.rear)
            {
                printf("Queue is already empty!\n\n");
                break;
            }
            int nominal_bayar = 0;
            UKTTransaction mhs = queue.transactions[queue.front];
            printf("Data Mahasiswa\n");
            printf("Nama: %s\n", mhs.nama);
            printf("NIM: %s\n", mhs.nama);
            printf("UKT: %d\n", mhs.ukt);
            printf("Nominal: %d\n", mhs.nominal);

            printf("Nominal bayar: ");
            get_int(&nominal_bayar);

            if (nominal_bayar >= mhs.nominal)
            {
                printf("Kembalian: %d\n\n", nominal_bayar - mhs.nominal);
                rb_dequeue(&queue);
            }
            else
            {
                printf("Nominal sekarang: %d (BELUM LUNAS)\n", mhs.nominal - nominal_bayar);
                mhs.nominal -= nominal_bayar;
                queue.transactions[queue.front].nominal = mhs.nominal;
            }
            break;
        }

        case 3:
        {
            print_ukt_queue(&queue);
            break;
        }

        case 4:
            exit = 1;

            free(queue.transactions);
            break;
        }
    }
}