#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * right_line - Function to move numbers right
 * @line: type pointer first number in line
 * @size: size of the array
 *
 */

int move_right(int *line, size_t size)
{
	int num_1 = 0;
	int num_2 = 0;
	size_t count = size - 1;
	size_t i;

	for (i = size - 1; i < size; i--)
	{
		if (num_1 == 0 && line[i] != 0)
			num_1 = line[i];
		else if (num_1 != 0 && line[i] != 0)
			num_2 = line[i];
		if (n1 != 0 && n2 != 0)
	   
	}
}
