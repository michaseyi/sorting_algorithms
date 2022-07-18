#include "sort.h"
#define max(list, a, b) ((list[a]) > (list[b]) ? (a) : (b))

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
 * BubbleDown - it sinks newly inserted value in a min heap to the
 * appropriate position
 * @list: heap
 * @size: size of the heap
 * @i: position of the value to be sinked
 * @orig_size: size of the underlining array
 */

void BubbleDown(int *list, int size, int i, int orig_size)
{
	int left, right, pos;

	while (1)
	{
		left = 2 * i + 1;
		right = 2 * i + 2;
		if (left < size && list[i] < list[left] &&
right < size && list[i] < list[right])
		{
			pos = max(list, right, left);
			swap(list, pos, i);
			print_array(list, orig_size);
			i = pos;
		}
		else if (left < size && list[i] < list[left])
		{
			swap(list, left, i);
			print_array(list, orig_size);
			i = left;
		}
		else if (right < size && list[i] < list[right])
		{
			swap(list, right, i);
			print_array(list, orig_size);
			i = right;
		}
		else
			break;
	}
}

/**
 * heap_sort - sorts an array on integers using the heap sort algorithm
 * @array: input array
 * @size: size of the input array
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		BubbleDown(array, size, i, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		BubbleDown(array, i, 0, size);
	}
}
