#include "sorting.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   srand(time(NULL));
   int size = 12;
   int *listnum = malloc(sizeof(int) * size);
   size_t len = size;
   time_t start, end;
   int *list = malloc(sizeof(int) * len);

   for (int i = 0; i < len; i++)
      listnum[i] = rand() % 10;

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // BubbleSort(list, len);
   // end = time(NULL) - start;
   // printf("BubbleSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // InsertionSort(list, len);
   // end = time(NULL) - start;
   // printf("InsertionSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // MergeSort(list, len);
   // end = time(NULL) - start;
   // printf("MergeSort %lds\n", end);

   memcpy(list, listnum, sizeof(int) * len);
   // int list[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
   // int len = sizeof(list) / sizeof(int);

   // for (int i = 0; i < len; i++)
   //    list[i] = rand() % 100;
   // print_list(list, );
   print_list(list, len);
   start = time(NULL);
   HeapSort(list, len);
   end = time(NULL) - start;
   print_list(list, len);
   printf("HeapSort %lds\n", end);

   // memcpy(list, listnum, sizeof(int) * len);
   // start = time(NULL);
   // SelectionSort(list, len);
   // end = time(NULL) - start;
   // printf("SelectionSort %lds\n", end);

   return 0;
}