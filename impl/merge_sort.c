#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "sorting.h"

int is_sorted(int list[], int len)
{
   for (int i = 0; i < len - 1; i++)
   {
      if (list[i] > list[i + 1])
         return 0;
   }
   return 1;
}

void merge(int first[], int first_len, int second[], int second_len)
{
   int *first_ptr = first, *second_ptr = second, size = first_len + second_len;
   int *merged_list = malloc(sizeof(int) * size);
   int f = 0, s = 0;

   for (int i = 0; i < size; i++)
   {
      if (second_ptr == NULL)
         merged_list[i] = first_ptr[f++];
      else if (first_ptr == NULL)
         merged_list[i] = second_ptr[s++];
      else if (first_ptr[f] <= second_ptr[s])
         merged_list[i] = first_ptr[f++];
      else
         merged_list[i] = second_ptr[s++];

      if (f == first_len)
         first_ptr = NULL;
      if (s == second_len)
         second_ptr = NULL;
   }
   memcpy(first, merged_list, size * sizeof(int));
   free(merged_list);
}

void MergeSort(int list[], int len)
{
   // if (is_sorted(list, len))
   //    return;
   if (len < 2)
      return;
   int mid = len / 2;
   MergeSort(list, mid);
   MergeSort(list + mid, len - mid);

   merge(list, mid, list + mid, len - mid);
}
