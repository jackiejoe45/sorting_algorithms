#include "sort.h"
/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;
	size_t i;

	if (array == NULL || size < 2)
		return;
	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;
	for (i = 0; i < size; i++)
		tmp[i] = array[i];
	merge_sort_helper(array, tmp, 0, size);
	free(tmp);
}
/**
 * merge_sort_helper - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array to store the sorted array
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: void
 */
void merge_sort_helper(int *array, int *tmp, size_t start, size_t end)
{
	size_t mid;

	if (end - start < 2)
		return;
	mid = (start + end) / 2;
	merge_sort_helper(tmp, array, start, mid);
	merge_sort_helper(tmp, array, mid, end);
	merge(array, tmp, start, mid, end);
}
/**
 * merge - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to be sorted
 * @tmp: temporary array to store the sorted array
 * @start: start index of the array
 * @mid: middle index of the array
 * @end: end index of the array
 *
 * Return: void
 */
void merge(int *array, int *tmp, size_t start, size_t mid, size_t end)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(tmp + start, mid - start);
	printf("[right]: ");
	print_array(tmp + mid, end - mid);
	i = start;
	j = mid;
	for (k = start; k < end; k++)
	{
		if (i < mid && (j >= end || tmp[i] <= tmp[j]))
		{
			array[k] = tmp[i];
			i++;
		}
		else
		{
			array[k] = tmp[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(array + start, end - start);
}

