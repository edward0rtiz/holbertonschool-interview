#include "sort.h"
#include <stdio.h>


/**
 * aux_function - radix sort auxiliar function
 * @array: type int the entry array
 * @size: type size_t of the array
 * @digit: type size_t the len of digit in the array
 */

void aux_function(int *array, size_t size, size_t digit)
{
	size_t i = 0, j = 0;
	size_t digits[10] = {0};
	int *radxs[10];
	int temp, counter;

	for (i = 0; i < size; i++)
	{
		temp = (array[i] % digit) / (digit / 10);
		digits[temp] = digits[temp] + 1;
	}
	if (digits[0] == size)
		return;
	for (i = 0; i < 10; i++)
		radxs[i] = malloc(digits[i] * sizeof(int));
	for (i = 0; i < 10; i++)
	{
		counter = 0;
		for (j = 0; j < size; j++)
			if (((array[j] % digit) / (digit / 10)) == i)
			{
				radxs[i][counter] = array[j];
				counter++;
			}
	}
	counter = 0;
	for (i = 0; i < 10; i++)
		for (j = 0; j < digits[i]; j++)
		{
			array[counter] = radxs[i][j];
			counter++;
		}
	print_array((const int *)array, size);
	for (i = 0; i < 10; i++)
		free(radxs[i]);
	aux_function(array, size, digit * 10);
}

/**
 * radix_sort - radix sort algorithm
 * @array: The array to sort
 * @size: The size of the array to sort
 */
void radix_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	if (size < 2)
		return;
	aux_function(array, size, 10);
}
