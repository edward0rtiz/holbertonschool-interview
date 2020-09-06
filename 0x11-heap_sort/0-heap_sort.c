#include <stdio.h>
#include "sort.h"

/**
 * swap - aux function that inteexchange the values
 * @val_a: type pointer of first value
 * @val_b: type pointer of second value
 */

void swap(int *val_a, int *val_b)
{
	int v1 = *val_a;
	int v2 = *val_b;

	*val_a = v2;
	*val_b = v1;
}

/**
 * heapify - binary sort
 * @array: type pointer of the array
 * @size: type size_t size
 * @i: type size_t posiition
 * @total_size: type size_t total size of the array
 */

void heapify(int *array, size_t size, size_t i, size_t total_size)
{
	size_t big = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[big])
		big = left;

	if (right < size && array[right] > array[big])
		big = right;

	if (big != i)
	{
		swap(&array[i], &array[big]);
		print_array(array, total_size);
		heapify(array, size, big, total_size);
	}
}

/**
 * heap_sort - heap sort algo
 * @array: Type array
 * @size: n-elements at the array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t total_size = size;

	if (array)
	{
		for (i = size / 2 - 1; (int)i >= 0; i--)
			heapify(array, size, i, total_size);
		for (i = size - 1; i > 0; i--)
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			heapify(array, i, 0, total_size);
		}
	}
}
