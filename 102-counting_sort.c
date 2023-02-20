#include "sort.h"
#include <stddef.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The pointer to array to be sorted
 * @size: The size of the array
 *
 * Return: 0
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	size_t maxValue = 0;
	int *count_array, *output_array;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > maxValue)
			maxValue = array[i];
	}

	count_array = malloc(sizeof(int) * (maxValue + 1));
	output_array = malloc(sizeof(int) * size);

	if (count_array == NULL || output_array == NULL)
	{
		free(count_array);
		free(output_array);
		return;
	}

	for (i = 0; i <= maxValue; i++)
		count_array[i] = 0;

	for (i = 0; i < size; i++)
		count_array[array[i]]++;

	for (i = 1; i <= maxValue; i++)
		count_array[i] += count_array[i - 1];

	for (i = size - 1; i > 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	for (i = 0; i < maxValue; i++)
	{
		printf("%d", count_array[i]);
		if (i != maxValue)
			printf(", ");
	}
	printf("\n");
	free(count_array);
	free(output_array);
}
