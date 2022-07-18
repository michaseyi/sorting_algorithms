#include "sort.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>


/**
 * counting_sort - sorts an array of numbers using the counting sort algorithm
 * @array: input array
 * @size: size of the input array
 */

void counting_sort(int *array, size_t size)
{
	int max = INT_MIN, *k, *result, pos, j;
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	k = malloc(sizeof(int) * (max + 1));
	if (k == NULL)
		return;
	memset(k, 0, sizeof(int) * (max + 1));
	for (i = 0; i < size; i++)
		k[array[i]]++;
	for (j = 1; j < max + 1; j++)
		k[j] += k[j - 1];
	print_array(k, max + 1);
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;
	for (i = 0; i < size; i++)
	{
		pos = k[array[i]]--;
		result[--pos] = array[i];
	}
	memcpy(array, result, size * sizeof(int));
}
