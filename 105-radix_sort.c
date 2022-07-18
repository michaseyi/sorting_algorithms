#include "sort.h"
#include <limits.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * raise_pow - raises the base to the power and returns
 * the result
 * @base: base
 * @power: power
 * Return: base raised to power
 */

int raise_pow(int base, int power)
{
	int res = 1;

	while (power--)
		res *= base;
	return (res);
}

/**
 * get_digit_count - gets the number of digits in a number
 * @num: input num
 * @count: holds the number of digits, it starts at 0
 * Return: the number of digits in a number
 */

int get_digit_count(int num, int count)
{
	int dig_count;

	if (!num)
		return (count);
	dig_count = get_digit_count(num / 10, count + 1);
	return (dig_count);
}

/**
 * get_nth_val - get the nth digit of a number
 * @number: input number
 * @n: the posistion of the digit to be retrived
 * Return: the value of the nth posistion of a number
 */

int get_nth_val(int number, int n)
{
	return ((number / raise_pow(10, n)) % 10);
}

/**
 * radix_sort - sorts an array using radix sorting algorithm
 * @array: input array
 * @size: size of the input array
 */

void radix_sort(int *array, size_t size)
{
	int max = INT_MIN, *k, *result, l, val, pos;
	size_t i, j, digit_count;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];
	digit_count = get_digit_count(max, 0);
	k = malloc(sizeof(int) * 10);
	if (k == NULL)
		return;
	result = malloc(sizeof(int) * size);
	if (result == NULL)
		return;
	for (i = 0; i < digit_count; i++)
	{
		memset(k, 0, sizeof(int) * 10);
		for (j = 0; j < size; j++)
			k[get_nth_val(array[j], i)]++;
		for (j = 1; j < 10; j++)
			k[j] += k[j - 1];
		for (l = size - 1; l >= 0; l--)
		{
			val = get_nth_val(array[l], i);
			pos = k[val]--;
			result[--pos] = array[l];
		}
		memcpy(array, result, sizeof(int) * size);
		print_array(array, size);
	}
	free(k);
	free(result);
}
