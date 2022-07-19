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
 * merge - merges two sequence
 * @array: array
 * @size: size of the input array
 * @order: order in which to merge the array
 */

void merge(int *array, size_t size, int order)
{
	int half, i;

	if (size < 2)
		return;
	half = size / 2;
	for (i = 0; i < half; i++)
	{
		if ((array[i] < array[i + half]) != order)
			swap(array, i, i + half);
	}
	merge(array, half, order);
	merge(array + half, half, order);
}

/**
 * _bitonic_sort - sorts an array using the bitonic sorting algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @orig_size: size of the underlining array
 * @order: the order in which to sort the array
 */

void _bitonic_sort(int *array, size_t size, size_t orig_size, int order)
{
	int half;
	char *direction = order == 1 ? "UP" : "DOWN";

	if (size < 2)
		return;
	half = size / 2;
	printf("Merging [%lu/%lu] (%s):\n", size, orig_size, direction);
	print_array(array, size);
	_bitonic_sort(array, half, orig_size, 1);
	_bitonic_sort(array + half, half, orig_size, 0);
	merge(array, size, order);
	printf("Result [%lu/%lu] (%s):\n", size, orig_size, direction);
	print_array(array, size);
}

/**
 * bitonic_sort - wraps the _bitonic_sort function
 * @array: input array
 * @size: size of the input array
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	_bitonic_sort(array, size, size, 1);
}
