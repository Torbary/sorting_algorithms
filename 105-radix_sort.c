#include "sort.h"
#include <stddef.h>

/**
 * countSort - sort an array of integers in ascending order using
 * counting sort algorithm
 *
 * @array: pointer to array to be sorted
 * @size: size of the array
 * @exponent: the current exponent
 *
 * Return: 0
 */
void countSort(int *array, int size, int exponent)
{
	int *output, *count;
	int i;

	output = malloc(sizeof(int) * size);
	count = malloc(sizeof(int) * 10);

	for (i = 0; i < 10; i++)
	{
		count[i] = 0;
	}

	for (i = 0; i < size; i++)
	{
		count[(array[i] / exponent) % 10]++;
	}

	for (i = 0; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exponent) % 10] - 1] = array[i];
		count[(array[i] / exponent) % 10]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	print_array(array, size);
	free(output);
	free(count);
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 * using the LSD radix sort algorithm
 *
 * @array: The array to be sorted
 * @size: The size of the array
 *
 * Return: 0
 */
void radix_sort(int *array, size_t size)
{
	int i, max;
	int exponent;

	if (array == NULL || size < 2)
		return;
	max = array[0];

	for (i = 1; i < (int) size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	for (exponent = 1; max / exponent > 0; exponent *= 10)
	{
		countSort(array, size, exponent);
	}
}
