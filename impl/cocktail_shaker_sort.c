#include "sorting.h"

void CocktailShakerSort(int list[], int size)
{
   int start = 0, end = size - 1;

   while (start < end)
   {
      int i;
      for (i = start; i < end; i++)
      {
         if (list[i] > list[i + 1])
         {
            swap(list, i, i + 1);
            print_list(list, size);
         }
      }
      end--;
      for (i = end; i > start; i--)
      {
         if (list[i] < list[i - 1])
         {
            swap(list, i, i - 1);
            print_list(list, size);
         }
      }
      start++;
   }
}