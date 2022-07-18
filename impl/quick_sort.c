#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sorting.h"

void swap(int list[], int first, int second)
{
   int temp = list[first];
   list[first] = list[second];
   list[second] = temp;
}

int LumotoPartitionScheme(int list[], int len, int pivot)
{
   int new_pivot = 0;
   for (int i = 0; i < len - 1; i++)
   {
      if (list[i] < list[pivot])
         swap(list, new_pivot++, i);
   }
   swap(list, pivot, new_pivot);
   return new_pivot;
}

int HoarePartitionScheme(int list[], int len, int pivot)
{
   int start = 0, end = len - 1, target = list[pivot];
   while (start < end)
   {
      if (list[start] > target && list[end] <= target)
         swap(list, start, end);
      else if (list[start] > target)
         end--;
      else if (list[end] <= target)
         start++;
      else
      {
         start++;
         end--;
      }
   }
   return start;
}

void QuickSort(int list[], int len)
{
   if (len < 2)
      return;
   int pivot = len - 1, partitioned_pivot;
   partitioned_pivot = HoarePartitionScheme(list, len, len - 1);
   QuickSort(list, partitioned_pivot);
   QuickSort(list + partitioned_pivot + 1, len - partitioned_pivot - 1);
}
