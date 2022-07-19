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
 * HoarePartitionScheme - partitions a list using the hoare partitioning
 * scheme
 * @origlist: pointer to the orignal list
 * @origlist_size: length of the original list
 * @list: pointer to the sublist
 * @len: lenght of the input sublist
 * @pivot: pivot postion
 * Return: The posistion of the partitioned pivot
 */

int HoarePartitionScheme(int *origlist, int origlist_size, int *list,
int len, int pivot)
{
	int start = -1, end = len, target = list[pivot];

	while (start < end)
	{
		do {
			start++;
		} while (list[start] < target);
		do {
			end--;
		} while (list[end] > target);
		if (start < end)
		{
			swap(list, start, end);
			print_array(origlist, origlist_size);
		}
	}
	return (start);
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
	partitioned_pivot = HoarePartitionScheme(orig, orig_size,
														  array, size, size - 1);
	_quick_sort(orig, orig_size, array, partitioned_pivot);
	_quick_sort(orig, orig_size, array + partitioned_pivot,
					size - partitioned_pivot);
}

/**
 * quick_sort_hoare - wraps the _quick_sort function
 * @array: input array
 * @size: size of the input array
 */

void quick_sort_hoare(int *array, size_t size)
{
	_quick_sort(array, size, array, size);
}
