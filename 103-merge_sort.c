#include "sort.h"
#include <stddef.h>

/**
 * merge_sort - Merge two sorted sub-arays into a single sorted array
 * using Merge sort algorithm
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: 0
 */

void merge_sort(int *array, size_t size)
{
	int *temp_array;

	if (!array || size < 2)
		return;

	temp_array = malloc(sizeof(int) * size);

	if (!temp_array)
		return;

	top_down_split_merge(array, 0, size, temp_array);
	free(temp_array);
}


/**
 * top_down_split_merge - recursively splits an array in half and merge int
 * back together in sorted order
 * @array: pointer to array to sort
 * @start: starting index of the array to sort
 * @end: ending index of the array to sort
 * @temp_array: temporary array used during the merge process
 *
 * Return: 0
 */

void top_down_split_merge(int *array, size_t start, size_t end,
			  int *temp_array)
{
	size_t middle;

	if (end - start < 2)
		return;

	middle = (end + start) / 2;

	top_down_split_merge(array, start, middle, temp_array);
	top_down_split_merge(array, middle, end, temp_array);
	top_down_merge(array, start, middle, end, temp_array);
}

/**
 * top_down_merge - merges two sorted sub-arrays of an array back together
 * @array: array containing the two sorted sub-arrays
 * @start: starting index of the first sub-array
 * @middle: ending index of the first sub-array (one less than the start of the
 * second sub-array)
 * @end: ending index of the second sub-array
 * @temp_array: temporary array used during the merge process
 *
 * Return: 0
 */

void top_down_merge(int *array, size_t start, size_t middle, size_t end,
		    int *temp_array)
{
	size_t i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + start, middle - start);

	printf("[right]: ");
	print_array(array + middle, end - middle);

	for (i = start, j = middle, k = 0; i < middle && j < end; k++)
	{
		if (array[i] < array[j])
			temp_array[k] = array[i++];
		else

			temp_array[k] = array[j++];
	}

	while (i < middle)
		temp_array[k++] = array[i++];

	while (j < end)
		temp_array[k++] = array[j++];
	for (i = start, k = 0; i < end; i++, k++)
		array[i] = temp_array[k];

	printf("[Done]: ");
	print_array(array + start, end - start);
}
