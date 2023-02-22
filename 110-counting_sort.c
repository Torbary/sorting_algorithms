/**
 * merge_sort - sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: array of integers to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp_array;

    if (!array || size < 2)
        return;

    temp_array = malloc(sizeof(int) * size);

    if (!temp_array)
        return;

    /* Sort the array using the top-down merge sort algorithm */
    top_down_split_merge(array, 0, size, temp_array);

    /* Free the temporary array used during the merge process */
    free(temp_array);
}

/**
 * top_down_split_merge - recursively splits an array in half and merges it
 *                        back together in sorted order
 * @array: array to sort
 * @start: starting index of the array to sort
 * @end: ending index of the array to sort
 * @temp_array: temporary array used during the merge process
 */
void top_down_split_merge(int *array, size_t start, size_t end, int *temp_array)
{
    size_t mid;

    if (end - start < 2)
        return;

    mid = (end + start) / 2;

    /* Recursively sort the left half of the array */
    top_down_split_merge(array, start, mid, temp_array);

    /* Recursively sort the right half of the array */
    top_down_split_merge(array, mid, end, temp_array);

    /* Merge the two sorted halves of the array back together */
    top_down_merge(array, start, mid, end, temp_array);
}

/**
 * top_down_merge - merges two sorted sub-arrays of an array back together
 * @array: array containing the two sorted sub-arrays
 * @start: starting index of the first sub-array
 * @mid: ending index of the first sub-array (one less than the start of the second sub-array)
 * @end: ending index of the second sub-array
 * @temp_array: temporary array used during the merge process
 */
void top_down_merge(int *array, size_t start, size_t mid, size_t end, int *temp_array)
{
    size_t i, j, k;

    printf("Merging...\n[left]: ");
    print_array(array + start, mid - start);

    printf("[right]: ");
    print_array(array + mid, end - mid);

    /* Copy the sub-arrays to the temporary array */
    for (i = start, j = mid, k = 0; i < mid && j < end; k++)
    {
        if (array[i] < array[j])
            temp_array[k] = array[i++];
        else
            temp_array[k] = array[j++];
    }

    while (i < mid)
        temp_array[k++] = array[i++];

    while (j < end)
        temp_array[k++] = array[j++];

    /* Copy the sorted temporary array back to the original array */
    for (i = start, k = 0; i < end; i++, k++)
        array[i] = temp_array[k];

    printf("[Done]: ");
    print_array(array + start, end - start);
}

