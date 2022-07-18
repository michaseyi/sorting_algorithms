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
 * LumotoPartitionScheme - partitions a list using the lumoto partitioning
 * scheme
 * @origlist: pointer to the orignal list
 * @origlist_size: length of the original list
 * @list: pointer to the sublist
 * @len: lenght of the input sublist
 * @pivot: pivot postion
 * Return: The posistion of the partitioned pivot
 */

int LumotoPartitionScheme(int *origlist, int origlist_size, int *list,
								  int len, int pivot)
{
	int i, new_pivot = 0;

	for (i = 0; i < len - 1; i++)
	{
		if (list[i] < list[pivot])
		{
			if (list[i] == list[new_pivot])
			{
				new_pivot++;
				continue;
			}
			swap(list, new_pivot++, i);
			print_array(origlist, origlist_size);
		}
	}
	if (list[pivot] != list[new_pivot])
	{
		swap(list, pivot, new_pivot);
		print_array(origlist, origlist_size);
	}
	return (new_pivot);
}

/**
 * _quick_sort - implementation of the quick sort algorithm
 * @orig: pointer to the orignal list
 * @orig_size: length of the original list
 * @array: pointer to the sublist
 * @size: lenght of the input sublist
 */

void _quick_sort(int *orig, size_t orig_size, int *array, size_t size)
{
	int partitioned_pivot;

	if (array == NULL || size < 2)
		return;
	partitioned_pivot = LumotoPartitionScheme(orig, orig_size,
															array, size, size - 1);
	_quick_sort(orig, orig_size, array, partitioned_pivot);
	_quick_sort(orig, orig_size, array + partitioned_pivot + 1,
					size - partitioned_pivot - 1);
}

/**
 * quick_sort - wraps the _quick_sort function
 * @array: input array
 * @size: size of the input array
 */

void quick_sort(int *array, size_t size)
{
	_quick_sort(array, size, array, size);
}
