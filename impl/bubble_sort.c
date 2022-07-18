#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
#include <limits.h>


void BubbleSort(int list[], int len)
{
   for (int i = 0; i < len - 1; i++)
   {
      int did_swap = 0;
      for (int j = 0; j < len - 1 - i; j++)
         if (list[j] > list[j + 1])
         {
            if (!did_swap)
               did_swap = 1;
            swap(list, j, j + 1);
         }
      if (!did_swap)
         break;
   }
}

void print_list(int *list, int len)
{
   for (int i = 0; i < len; i++)
      printf("%d, ", list[i]);

   printf("\n");
}