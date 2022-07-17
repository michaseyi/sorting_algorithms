#include "sorting.h"
#include <stdlib.h>
#include <limits.h>
#include <string.h>

void CountingSort(int list[], int size)
{
   int max = INT_MIN;

   for (int i = 0; i < size; i++)
      if (list[i] > max)
         max = list[i];

   int *k = malloc(sizeof(int) * (max + 1));

   memset(k, 0, sizeof(int) * (max + 1));

   for (int i = 0; i < size; i++)
      k[list[i]]++;

   for (int i = 1; i < max + 1; i++)
      k[i] += k[i - 1];

   int *result = malloc(sizeof(int) * size);

   for (int i = 0; i < size; i++)
   {

      int pos = k[list[i]]--;
      result[--pos] = list[i];
   }
   memcpy(list, result, size * sizeof(int));
}