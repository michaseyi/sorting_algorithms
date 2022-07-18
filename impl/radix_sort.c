#include "sorting.h"
#include <limits.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int get_digit_count(int num, int count)
{
   if (!num)
      return count;
   return get_digit_count(num / 10, count + 1);
}

int get_nth_val(int number, int n)
{
   return (number / (int)pow(10, n)) % 10;
}

void RadixSort(int list[], int size)
{
   int max = INT_MIN, digit_count;

   for (int i = 0; i < size; i++)
      if (list[i] > max)
         max = list[i];

   digit_count = get_digit_count(max, 0);
   int *k = malloc(sizeof(int) * 10);
   int *result = malloc(sizeof(int) * size);
   for (int i = 0; i < digit_count; i++)
   {
      memset(k, 0, sizeof(int) * 10);
      for (int j = 0; j < size; j++)
         k[get_nth_val(list[j], i)]++;

      for (int j = 1; j < 10; j++)
         k[j] += k[j - 1];
      
      // Starting from the end to ensure the stability of the sorting algorithm
      for (int j = size - 1; j >= 0; j--)
      {
         int val = get_nth_val(list[j], i);
         int pos = k[val]--;
         result[--pos] = list[j];
      }

      memcpy(list, result, sizeof(int) * size);
      print_list(result, size);
   }
   free(k);
   free(result);
}