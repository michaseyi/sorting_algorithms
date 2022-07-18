#include "sorting.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   // srand(time(NULL));
   // int size = 12;
   // int *listnum = malloc(sizeof(int) * size);
   // size_t len = size;
   time_t start, end;
   // int *list = malloc(sizeof(int) * len);

   // for (int i = 0; i < len; i++)
   //    listnum[i] = rand() % 100;

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // BubbleSort(list, len);
   // end = time(NULL) - start;
   // printf("BubbleSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // InsertionSort(list, len);
   // end = time(NULL) - start;void print_list(const listint_t *list)
   // {
   //     int i;

   //     i = 0;
   //     while (list)
   //     {
   //         if (i > 0)
   //             printf(", ");
   //         printf("%d", list->n);
   //         ++i;
   //         list = list->next;
   //     }
   //     printf("\n");
   // }
   // printf("InsertionSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // MergeSort(list, len);
   // end = time(NULL) - start;
   // printf("MergeSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   int list[] = {35, 75, 45, 85, 65, 25, 15, 55};
   int len = sizeof(list) / sizeof(int);

   // for (int i = 0; i < len; i++)
   //    list[i] = rand() % 100;
   // print_list(list, );
   print_list(list, len);
   printf("-----------------------------------------\n");
   start = time(NULL);
   BitonicSort(list, len);
   end = time(NULL) - start;
   printf("-----------------------------------------\n");
   print_list(list, len);
   printf("BitonicSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // SelectionSort(list, len);
   // end = time(NULL) - start;
   // printf("SelectionSort %lds\n", end);

   return 0;
}