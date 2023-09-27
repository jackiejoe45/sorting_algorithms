#include "sort.h"

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_recur(array, 0, size, 1);
}

/**
 * bitonic_recur - recursive function for bitonic sort
 * @array: array to be sorted
 * @low: low index
 * @size: size of the array
 * @dir: direction (1 for UP, 0 for DOWN)
 *
 * This function recursively divides the array and merges it in a bitonic manner.
 *
 * Return: void
 */
void bitonic_recur(int *array, size_t low, size_t size, int dir)
{
	size_t k = size / 2;

	if (size < 2)
		return;
	printf("Merging [%lu] (%s):\n", size, dir == 1 ? "UP" : "DOWN");
	print_array(array + low, size);
	bitonic_recur(array, low, k, 1);
	bitonic_recur(array, low + k, k, 0);
	bitonic_merge(array, low, size, dir);
	printf("Result [%lu] (%s):\n", size, dir == 1 ? "UP" : "DOWN");
	print_array(array + low, size);
}

/**
 * bitonic_merge - merge function for bitonic sort
 * @array: array to be sorted
 * @low: low index
 * @size: size of the array
 * @dir: direction (1 for UP, 0 for DOWN)
 *
 * This function recursively merges two bitonic sequences.
 *
 * Return: void
 */
void bitonic_merge(int *array, size_t low, size_t size, int dir)
{
	size_t i;
	size_t k = size / 2;

	int tmp;

	if (size < 2)
		return;
	for (i = low; i < low + k; i++)
	{
		if (dir == (array[i] > array[i + k]))
		{
			tmp = array[i];
			array[i] = array[i + k];
			array[i + k] = tmp;
		}
	}
	bitonic_merge(array, low, k, dir);
	bitonic_merge(array, low + k, k, dir);
}

