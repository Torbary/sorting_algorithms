#include "sort.h"
#include <stdbool.h>
#include <math.h>

void compare_swap(int *a, int *b, int dir)
{
 	if ((dir && *a > *b) || (!dir && *a < *b))
	{
		int temp = *a;
		*a = *b;
		*b = temp;
	}
}

void bitonic_merge(int *array, size_t size, int dir)
{
	size_t i, half_size;

	if (size > 1)
	{
		half_size = size / 2;
		for (i = 0; i < half_size; i++)
		{
			compare_swap(&array[i], &array[i + half_size], dir);
		}
		bitonic_merge(array, half_size, dir);
		bitonic_merge(array + half_size, half_size, dir);
	}
}

void bitonic_sort(int *array, size_t size)
{
	size_t k, j, i;

	for (k = 2; k <= size; k *= 2)
	{
		for (j = k / 2; j > 0; j /= 2)
		{
			for (i = 0; i < size; i += k)
			{
				bitonic_merge(array + i, j, 1);
				bitonic_merge(array + i + j, j, 0);
			}
			printf("Merging [%lu/%lu] (%s) :\n", k, size,
				j == k / 2 ? "UP" : "DOWN");
			for (i = 0; i < size; i++)
			{
				printf("%d%s", array[i], i == size - 1
					? "\n" : ", ");
			}
		}
	}
}
