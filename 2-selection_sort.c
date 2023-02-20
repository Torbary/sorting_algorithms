#include "sort.h"
#include <stddef.h>



void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * selection_sort - sort an array of in in accesding order
 * @array: pointers of array to be sorted
 * @size: size of the array
 *
 * Return: 0
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, miniIndex;

	for (i = 0; i < size - 1; i++)
	{
		miniIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[miniIndex])
				miniIndex = j;
		}
		if (miniIndex != i)
		{
			swap(&array[miniIndex], &array[i]);
			print_array(array, size);
		}
	}
}
