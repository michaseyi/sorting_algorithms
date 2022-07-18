#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sorting.h"

int min(int *list, int len)
{
   int min_index = 0;

   for (int i = 0; i < len; i++)
   {
      if (list[i] < list[min_index])
         min_index = i;
   }

   return min_index;
}

void SelectionSort(int list[], int len)
{

   int min_pos, temp;

   for (int i = 0; i < len; i++)
   {
      min_pos = min(list + i, len - i); 
      swap(list, min_pos + i, i);
   }
}
