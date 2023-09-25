#include "sort.h"
/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	if (array == NULL || size < 2)
		return;
	for (i = size / 2; i > 0; i--)
		heapify(array, size, i - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		swap(array, size, 0, i);
		heapify(array, size, 0, i);
	}
}
/**
 * heapify - heapifies an array
 * @array: array to be heapified
 * @size: size of the array
 * @i: index of the root node
 * @len: size of the heap
 *
 * Return: void
 */
void heapify(int *array, size_t size, size_t i, size_t len)
{
	size_t max = i, left = 2 * i + 1, right = 2 * i + 2;

	if (left < len && array[left] > array[max])
		max = left;
	if (right < len && array[right] > array[max])
		max = right;
	if (max != i)
	{
		swap(array, size, i, max);
		heapify(array, size, max, len);
	}
}
/**
 * swap - swaps two elements in an array
 * @array: array containing the elements
 * @size: size of the array
 * @i: index of the first element
 * @j: index of the second element
 *
 * Return: void
 */
void swap(int *array, size_t size, size_t i, size_t j)
{
	int tmp = array[i];

	array[i] = array[j];
	array[j] = tmp;
	print_array(array, size);
}

