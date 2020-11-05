#include "sort.h"

/**
 * merge_sub - merge sorting algorithm function.
 *@subarray: array split into sub array.
 *@buffer: buffer of array.
 *@lo: low partition.
 *@mid: mid partition.
 *@hi: high partition.
 * Return: Always 0
 */
void merge_sub(int *subarray, int *buffer, size_t lo, size_t mid, size_t hi)
{
	size_t low;
	size_t midi;
	size_t a = 0;

	printf("Merging...\n[left]: ");
	print_array(subarray + lo, mid - lo);

	printf("[right]: ");
	print_array(subarray + mid, hi - mid);

	for (low = lo, midi = mid; low < mid && midi < hi; a++)
	{
		if (subarray[low] < subarray[midi])
		{
			buffer[a] = subarray[low++];
		}
		else
		{
			buffer[a] = subarray[midi++];
		}
	}
	for (; low < mid; low++)
	{
		buffer[a++] = subarray[low];
	}
	for (; midi < hi; midi++)
	{
		buffer[a++] = subarray[midi];
	}
	for (low = lo, a = 0; low < hi; low++)
	{
		subarray[low] = buffer[a++];
	}
	printf("[Done]: ");
	print_array(subarray + lo, hi - lo);
}

/**
 * merge_sort_call - calling the merge sort function.
 *@subarray: subarray to be sorted.
 *@buffer: buffer of array.
 *@lo: low partition.
 *@hi: high partition.
 * Return: Always 0
 */
void merge_sort_call(int *subarray, int *buffer, size_t lo, size_t hi)
{
	size_t mid;

	if (hi - lo > 1)
	{
		mid = lo + (hi - lo) / 2;
		merge_sort_call(subarray, buffer, lo, mid);
		merge_sort_call(subarray, buffer, mid, hi);
		merge_sub(subarray, buffer, lo, mid, hi);
	}
}

/**
 * merge_sort - merge sort algorithm implementation
 *@array: array to be sorted.
 *@size: size of array to be sorted.
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (buffer == NULL)
		return;

	merge_sort_call(array, buffer, 0, size);

	free(buffer);
}
