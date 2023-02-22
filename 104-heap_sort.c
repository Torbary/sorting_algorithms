#include "sort.h"

/**
 * shift_down - create the maxheap
 * @array: pointer to array to be sorted
 * @start: start of the maxheap
 * @end: end of the maxheap
 *
 * Return: 0
 */

void shift_down(int *array, int start, int end)
{
	int root = start;
	int child = root * 2 + 1;

	while (root * 2 + 1 <= end)
	{
		if (child + 1 <= end && array[child] < array[child + 1])
		{
			child += 1;
		}

		if (array[root] < array[child])
		{
			int temp = array[root];

			array[root] = array[child];
			array[child] = temp;
			printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
			       array[0], array[1], array[2], array[3], array[4],
			       array[5], array[6], array[7], array[8], array[9]);
			root = child;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - sort the array using the heapsort algorithm
 * @array: pointer to array to be sorted
 * @size: size  of the array
 * Return: 0
 */

void heap_sort(int *array, size_t size)
{
	int start = (size - 2) / 2;
	int end = size - 1;

	while (start >= 0)
	{
		shift_down(array, start, size - 1);
		start -= 1;
	}
	while (end > 0)
	{
		int temp = array[end];

		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		end -= 1;
		shift_down(array, 0, end);
	}
}
