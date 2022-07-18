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
 * shell_sort - sorts an array using the shell sort algorithm with knuth
 * sequence
 * @array: input array
 * @size: size of the input array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, j, i;

	if (array == NULL)
		return;
	while (gap < size / 3)
		gap = (gap * 3) + 1;
	while (gap > 0)
	{
		for (i = 0; i < size - gap; i++)
		{
			for (j = i + gap; j >= gap; j -= gap)
			{
				if (array[j - gap] > array[j])
				{
					swap(array, j, j - gap);
					continue;
				}
				break;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
