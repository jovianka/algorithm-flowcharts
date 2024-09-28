#include <stdio.h>
#include <stdlib.h>

void linear_probe(int *hash_values, int *array, int *linear, int slot)
{
  int temp[slot];
  for (int i = 0; i < slot; i++)
  {
    temp[i] = hash_values[i];
  }

  for (int i = 0; i < slot; i++)
  {
    while (linear[temp[i]] != 0)
    {
      temp[i] = (temp[i] + 1) % slot;
    }
    linear[temp[i]] = array[i];
  }
}

void quadratic_probe(int *hash_values, int *array, int *quadratic, int slot)
{
  int j;

  int temp[slot];
  for (int i = 0; i < slot; i++)
  {
    temp[i] = hash_values[i];
  }

  for (int i = 0; i < slot; i++)
  {
    j = 0;
    while (quadratic[temp[i]] != 0)
    {
      temp[i] = (temp[i] + (j * j)) % slot;
      j++;
    }
    quadratic[temp[i]] = array[i];
  }
}

void print_hash(int *hash_values, int *array, int *linear, int *quadratic, int slot)
{
  for (int i = 0; i < slot; i++)
  {
    printf("data-%d: %d\n", i + 1, array[i]);
  }

  printf("\n------------------------------------\n");

  for (int i = 0; i < slot; i++)
  {
    printf("hash data-%d: %d\n", i + 1, hash_values[i]);
  }

  printf("\n------------------------------------\n");

  for (int i = 0; i < slot; i++)
  {
    printf("linear probing index-%d: %d\n", i, linear[i]);
  }

  printf("\n------------------------------------\n");

  for (int i = 0; i < slot; i++)
  {
    printf("quadratic probing index-%d: %d\n", i, quadratic[i]);
  }
}

int main()
{
  int input;
  printf("Storage Size: ");
  scanf("%d", &input);

  int *array = (int *)malloc(input * sizeof(int));
  printf("Insert data(example: 1 2 3 4 etc): ");
  for (int i = 0; i < input; i++)
  {
    scanf("%d", &array[i]);
  }

  int *hash_values = (int *)malloc(input * sizeof(int));
  for (int i = 0; i < input; i++)
  {
    hash_values[i] = array[i] % input;
  }

  int *linear = (int *)calloc(input, sizeof(int));
  int *quadratic = (int *)calloc(input, sizeof(int));

  linear_probe(hash_values, array, linear, input);
  quadratic_probe(hash_values, array, quadratic, input);
  print_hash(hash_values, array, linear, quadratic, input);

  free(array);
  free(hash_values);
  free(linear);
  free(quadratic);

  return 0;
}
