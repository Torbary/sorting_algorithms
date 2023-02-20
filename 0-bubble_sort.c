#include "sort.h"

/**
 * bubble_sort - sort an array of int in ascending order
 * @array: pointer to the unsorted array
 * @size: sise of the array
 *
 * Return: 0
 */



void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp = 0;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}

