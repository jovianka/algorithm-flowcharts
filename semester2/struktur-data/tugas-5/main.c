#include <stdio.h>
#include <stdlib.h>

typedef struct UKTTransaction
{
    char nama[256];
    char nim[11];
    int level_ukt;
    int harga_ukt;
} UKTTransaction;

typedef struct RBQueue
{
    UKTTransaction *transactions;
    int front;
    int rear;
    int has_elements;
    int max;
} RBQueue;

void init_ring_transactions(RBQueue *queue, int size, int max)
{
    queue->transactions = calloc(size, sizeof(queue->transactions[0]));
    queue->front = 0;
    queue->rear = 0;
    queue->has_elements = 0;
    queue->max = max;
}

void rb_enqueue(UKTTransaction new_transaction, RBQueue *queue)
{

    if (queue->has_elements == 1 && queue->front == queue->rear)
    {
        printf("Queue is full!");
        return;
    }

    queue->transactions[queue->rear] = new_transaction;
    queue->rear = (queue->rear + 1) % queue->max;
    queue->has_elements = 1;
}

void rb_dequeue(RBQueue *queue)
{

    if (queue->has_elements == 0 && queue->front == queue->rear)
    {
        printf("Queue is already empty!");
        return;
    }
    UKTTransaction return_value = queue->transactions[queue->front];
    queue->front = (queue->front + 1) % queue->max;

    if (queue->front == queue->rear)
    {
        queue->has_elements = 0;
    }

    return return_value;
}

print_ukt_queue(RBQueue *queue)
{
    printf("Nama\t\tNIM\tUKT\tNominal\n");
    for (int i = 0; i < queue->rear; i++)
    {
        printf("%s\t%s\t%d\t%d",
               queue->transactions[(queue->front + i) % queue->max].nama,
               queue->transactions[(queue->front + i) % queue->max].nim,
               queue->transactions[(queue->front + i) % queue->max].level_ukt,
               queue->transactions[(queue->front + i) % queue->max].harga_ukt);
    }
}

int main()
{
    printf("Program Antrian Pembayaran UKT");

    RBQueue queue;
    init_ring_buffer(&queue);

    printf("Input Maks Antrian: ");
}