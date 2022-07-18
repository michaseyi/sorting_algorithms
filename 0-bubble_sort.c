#include "sort.h"

/**
 * swap - This does what you think it does
 * @array: input array
 * @first: position 1
 * @second: position 2
 */

void swap(int *array, int first, int second)
{
	int temp = array[first];

	array[first] = array[second];
	array[second] = temp;
}

/**
 * bubble_sort - performs bubble sort on an array to sort it
 * @array: input array
 * @size: size of the input array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j, did_swap;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		did_swap = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				print_array(array, size);
				did_swap = 1;
			}
		}
		if (!did_swap)
			break;
	}
}
