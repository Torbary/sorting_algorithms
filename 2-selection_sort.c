#include "sort.h"
#include <stddef.h>

/**
 * selection_sort - sort an array of in in accesding order
 * @array: pointers of array to be sorted
 * @size: size of the array
 *
 * Return: 0
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, miniIndex;

	for (i = 0; i < size - 1; i++)
	{
		miniIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[miniIndex])
				miniIndex = j;
		}
		temp = array[miniIndex];
		array[miniIndex] = array[i];
		array[i] = temp;
		print_array(array, size);
	}
}
