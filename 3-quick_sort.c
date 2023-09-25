#include "sort.h"
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
/**
 * quick_sort_helper - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}
/**
 * partition - partitions an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @lo: lowest index of the partition
 * @hi: highest index of the partition
 * @size: size of the array
 *
 * Return: void
 */
int partition(int *array, int lo, int hi, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[hi];
	i = lo;

	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > array[hi])
	{
		tmp = array[i];
		array[i] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i);
}

