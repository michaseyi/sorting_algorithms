#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * merge - merges two sorted list
 * @first: first list
 * @first_len: size of first list
 * @second: second list
 * @second_len: size of second list
 * @merged_list: array that holds merge result
 */

void merge(int first[], int first_len, int second[], int second_len,
int *merged_list)
{
	int *first_ptr = first, *second_ptr = second, size = first_len + second_len;
	int f = 0, s = 0, i = 0;

	for (i = 0; i < size; i++)
	{
		if (second_ptr == NULL)
			merged_list[i] = first_ptr[f++];
		else if (first_ptr == NULL)
			merged_list[i] = second_ptr[s++];
		else if (first_ptr[f] <= second_ptr[s])
			merged_list[i] = first_ptr[f++];
		else
			merged_list[i] = second_ptr[s++];

		if (f == first_len)
			first_ptr = NULL;
		if (s == second_len)
			second_ptr = NULL;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(first, first_len);
	printf("[right]: ");
	print_array(second, second_len);
	printf("[Done]: ");
	print_array(merged_list, size);
	memcpy(first, merged_list, size * sizeof(int));
}

/**
 * _merge_sort - sorts an array using the merge sort algorithm
 * @array: input array
 * @size: size of input array
 * @merged_list: array that holds merge result
 */

void _merge_sort(int *array, size_t size, int *merged_list)
{
	size_t mid;

	if (size < 2)
		return;
	mid = size / 2;
	_merge_sort(array, mid, merged_list);
	_merge_sort(array + mid, size - mid, merged_list);

	merge(array, mid, array + mid, size - mid, merged_list);
}

/**
 * merge_sort - wraps the _merge_sort function
 * @array: input array
 * @size: size of the input array
 */

void merge_sort(int *array, size_t size)
{
	int *merged_list = malloc(sizeof(int) * size);

	if (array == NULL || size < 2 || merged_list == NULL)
		return;
	_merge_sort(array, size, merged_list);
	free(merged_list);
}
