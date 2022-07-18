#include "sorting.h"
#define max(list, a, b) ((list[a]) > (list[b]) ? (a) : (b))
#include <stdio.h>

void BubbleUp(int list[], int i, int size)
{
   int parent;
   while (1)
   {
      parent = (i - 1) / 2;
      if (parent >= 0 & list[parent] < list[i])
      {
         swap(list, parent, i);
         i = parent;
      }
      else
         break;
   }
}

void BubbleDown(int list[], int size, int i)
{
   int left, right;
   while (1)
   {
      left = 2 * i + 1;
      right = 2 * i + 2;
      if (left < size && list[i] < list[left] && right < size && list[i] < list[right])
      {
         int pos = max(list, right, left);
         swap(list, pos, i);
         i = pos;
      }
      else if (left < size && list[i] < list[left])
      {
         swap(list, left, i);
         i = left;
      }
      else if (right < size && list[i] < list[right])
      {
         swap(list, right, i);
         i = right;
      }
      else
         break;
   }
}

void HeapSort(int list[], int size)
{
   int size_h = size / 2;

   // heapify is O(n) and i still don't know why
   for (int j = size / 2 - 1; j >= 0; j--)
      BubbleDown(list, size, j);

   for (int i = size - 1; i > 0; i--)
   {
      swap(list, 0, i);
      BubbleDown(list, i, 0);
   }
}