#include "menger.h"

/**
 * menger - 2D menger sponge
 * @level: level of the menger sponge
 */

void menger(int level)
{
	int size, row, col;
	char character;

	size = pow(3, level);

	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			character = get_character(row, col);
			printf("%c", character);
		}
		printf("\n");
	}
}
/**
 * get_character - get the character
 * @row: get the row
 * @col: get the col
 * Return: #
 */
char get_character(int row, int col)
{
	while (row || col)
	{
		if (row % 3 == 1 && col % 3 == 1)
			return (' ');
		row /= 3;
		col /= 3;
	}
	return ('#');
}
