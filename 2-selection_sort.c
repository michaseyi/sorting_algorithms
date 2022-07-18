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
 * min - finds the minimum number in the list and returns the position
 * @list: input list
 * @len: size of the input list
 * Return: the index of the smallest number
 */
size_t min(int *list, size_t len)
{
	size_t min_index = 0, i;

	for (i = 0; i < len; i++)
	{
		if (list[i] < list[min_index])
			min_index = i;
	}
	return (min_index);
}

/**
 * selection_sort - sorts an array using the selection sort
 * algorithm
 * @array: input array
 * @size: length of the input array
 */

void selection_sort(int *array, size_t size)
{
	size_t min_pos, i;

	if (array == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		min_pos = min(array + i, size - i);
		if (array[min_pos + i] != array[i])
		{
			swap(array, i, min_pos + i);
			print_array(array, size);
		}
	}
}
