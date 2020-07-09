#include <stdio.h>
#include <stdlib.h>
#include "slide_line.h"

/**
 * move_right - Function to move numbers right
 * @line: type pointer first number in line
 * @size: size of the array
 * Return: 1 success otherwise 0
 *
 */

int move_right(int *line, size_t size)
{
	int num_1 = 0;
	int num_2 = 0;
	size_t move = size - 1;
	size_t idx;

	for (idx = size - 1; idx < size; idx--)
	{
		if (line[idx] != 0 && num_1 == 0)
		{
			num_1 = line[idx];
		}
		else if (line[idx] != 0 && num_1 != 0)
		{
			num_2 = line[idx];
		}
		if (num_1 != 0 && num_2 != 0)
		{
			if (num_1 == num_2)
			{
				line[move--] = num_1 + num_2;
				num_1 = 0;
				num_2 = 0;
			}
			else
			{
				line[move--] = num_1;
				num_1 = num_2;
				num_2 = 0;
				if (idx == 0)
				{
					line[move--] = num_1;
				}
			}

		}
		else if (num_1 != num_2 && idx == 0)
		{
			line[move--] = num_1;
		}
	}
	for (idx = 0; idx < move + 1; idx++)
	{
		line[idx] = 0;
	}
	return (1);
}

/**
 * move_left - Function to move numbers left
 * @line: type pointer first number in line
 * @size: size of the array
 * Return: 1 success otherwise 0
 *
 */
int move_left(int *line, size_t size)
{
	int num_1 = 0;
	int num_2 = 0;
	size_t count = 0, idx;


	for (idx = 0; idx < size; idx++)
	{
		if (line[idx] != 0 && num_1 == 0)
		{
			num_1 = line[idx];
		}
		else if (line[idx] != 0 && num_1 != 0)
		{
			num_2 = line[idx];
		}
		if (num_1 != 0 && num_2 != 0)
		{
			if (num_1 == num_2)
			{
				line[count++] = num_1 + num_2;
				num_1 = 0;
				num_2 = 0;
			}
			else
			{
				line[count++] = num_1;
				num_1 = num_2;
				num_2 = 0;
				if (idx == size - 1)
				{
					line[count++] = num_1;
				}
			}
		}
		else if (num_1 != num_2 && idx == size - 1)
		{
			line[count++] = num_1;
		}
	}
	for (idx = count; idx < size; idx++)
	{
		line[idx] = 0;
	}
	return (1);
}

/**
 * slide_line - Function that moves and if apply sum int in the array
 * @line: type pointer in an array of integers
 * @size: Type size_t the number of elements in array
 * @direction: Macros SLIDE_LEFT, SLIDE_RIGHT
 * Return: 1 success otherwise 0
 *
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_RIGHT)
	{
		return (move_right(line, size));
	}
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
	{
		return (0);
	}
	return (move_left(line, size));
}
