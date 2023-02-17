#include "sort.h"
#include <stddef.h>

/**
 * swap - swap two integers (helper function)
 * @a: first integer to swap
 * @b: second integer to swap
 *
 * Return: 0
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partition the array and set the pivot
 *
 * @array: pointer to array to be sorted
 * @low: lowest index of partition to sort
 * @high: highest index of partition to sort
 * @size:size of the array
 *
 * Return: index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive -  Sorts an array of integers(recursively)
 * using the quicksort algorithm
 * @array: pointer to the first element of the array to sort
 * @low: THe starting index og the partition to sort
 * @high: the ending  index of the partition to sort
 * @size: size of the array
 *
 * Return: 0
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partitionIndex = partition(array, low, high, size);

		quicksort_recursive(array, low, partitionIndex - 1, size);
		quicksort_recursive(array, partitionIndex + 1, high, size);
	}
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to be sorted
 * @size: size of the array
 *
 * Return: 0
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_recursive(array, 0, size - 1, size);
}
