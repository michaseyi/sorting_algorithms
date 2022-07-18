#include "sorting.h"
#include <stdio.h>

void firstPhase(int list[], int size) {}
void secondPhase(int list[], int size) {}
void thirdPhase(int list[], int size) {}
void BitonicSort(int list[], int size)
{
   while (!is_sorted(list, size))
   {
      // 1st phase
      for (int i = 0, j = 0; i < size; i += 2, j++)
      {
         // sort ascending
         if (j % 2 == 0 && list[i] > list[i + 1])
            swap(list, i, i + 1);
         // sort descending
         else if (j % 2 != 0 && list[i] < list[i + 1])
            swap(list, i, i + 1);
      }
      printf("First phase - ");
      print_list(list, size);

      // 2nd phase
      int half = size / 2;
      for (int i = 0; i < size; i += half)
      {
         if (i == 0)
            for (int j = i; j < half - 2; j++)
            {
               if (list[j] > list[j + 2])
                  swap(list, j, j + 2);
            }
         else
            for (int j = i; j < size - 2; j++)
            {
               if (list[j] < list[j + 2])
                  swap(list, j, j + 2);
            }
      }
      printf("Second phase - ");
      print_list(list, size);

      // 3rd phase
      for (int i = 0; i < size; i += half)
      {
         if (i == 0)
            for (int j = i; j < half; j += 2)
            {
               if (list[j] > list[j + 1])
                  swap(list, j, j + 1);
            }
         else
            for (int j = i; j < size; j += 2)
            {
               if (list[j] < list[j + 1])
                  swap(list, j, j + 1);
            }
      }
      printf("Third phase - ");
      print_list(list, size);

      break;
   }
}
