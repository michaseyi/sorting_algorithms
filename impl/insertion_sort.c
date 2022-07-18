#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "sorting.h"
int binary_search(int list[], int start, int end, int target)
{
   if (start > end)
      return start;
   int mid_pos = (start + end) / 2;
   if (list[mid_pos] < target)
      binary_search(list, mid_pos + 1, end, target);
   else if (list[mid_pos] > target)
      binary_search(list, start, mid_pos - 1, target);
   else
      return mid_pos;
}

int find_position(int list[], int len, int target)
{
   int i;
   for (i = 0; i < len - 1; i++)
   {
      if (list[i] > target)
         return i;
   }
   return i;
}

void shift(int list[], int len)
{
   int val = 0, temp = 0, i;
   for (i = 0; i <= len; i++)
   {
      temp = list[i];
      list[i] = val;
      val = temp;
   }
}

void InsertionSort(int list[], int len)
{
   int hole, pos, value;
   for (int i = 0; i < len; i++)
   {
      value = list[i];
      hole = i;
      while (hole > 0 && list[hole - 1] > value)
      {
         list[hole] = list[hole - 1];
         hole--;
      }
      list[hole] = value;
   }
}
