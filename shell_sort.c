#include "sorting.h"

void ShellSort(int list[], int len)
{
   int gap = 1;
   while (gap < len / 3)
      gap = (gap * 3) + 1;
   while (gap)
   {
      for (int i = 0; i < len - gap; i++)
      {
         for (int j = i + gap; j >= gap; j -= gap)
         {
            if (list[j - gap] > list[j])
            {
               swap(list, j, j - gap);
               continue;
            }
            break;
         }
      }
      gap /= 3;
   }
}