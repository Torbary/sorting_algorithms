#include "sort.h"
#include <stddef.h>

/**
 * merge - Merge two sorted sub-arays into a single sorted array
 * @left: pointer to the first element of the list sub-array
 * @lft_size: size of the left sub array
 * @right: pointer to the first eleemnt of the right sub-array
 * @ryt_size: size of the right sub-array
 * @array: pointer to the first element of the array to sort
 */

void merge(int *left, size_t lft_size, int *right, size_t ryt_size, int *array)
{
	int *result;
	size_t i = 0, j = 0, k = 0;

	result = malloc(sizeof(int) * (lft_size + ryt_size));

	if (!result)
	{
		printf("Error: malloc failed in merge()\n");
		exit(1);
	}

	while (i < lft_size && j < ryt_size)
	{
		if (left[i] < right[j])
			result[k++] = left[i++];
		else
			result[k++] = right[j++];
	}

	while (i < lft_size)
		result[k++] = left[i++];
	while (j < ryt_size)
		result[k++] = right[j++];
	for (i = 0; i < lft_size + ryt_size; i++)
		array[i] = result[i];

	free(result);
}

/**
 * merge_sort - sort an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: pointer to the first eleemnt of the array to sort
 * @size: number of eleemnt in the array
 *
 * Return: 0
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	int *left, *right;

	if (size <= 1)
		return;
	left = array;
	right = array + middle;

	merge_sort(left, middle);
	merge_sort(right, size - middle);

	printf("Merging...\n[left]: ");
	print_array(left, middle);
	printf("[right]: ");
	print_array(right, size - middle);

	merge(left, middle, right, size - middle, array);

	printf("[Done]: ");
	print_array(array, size);
}
