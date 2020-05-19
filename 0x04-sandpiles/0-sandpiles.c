#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * print_grid - print a sandpile grid
 * @grid: tyoe int a sandpile 3 x 3
 */

static void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
	    {
		    printf(" ");
	    }
	    printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * if_sandpile - Checks if the grid contains valid
 * sandiles int < 3
 * @grid: type int a sandpile 3 x 3
 */

static int if_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}


/**
 * sum_grids - sum grids grid1 and grid2
 * @grid: type int a sandpile 3 x 3
 * @grid: type int a sandpile 3 x 3
 */

static void sum_grids(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
}


/**
 * topple - Move across the grid to operate a sum3
 * @grid: type int a sandpile 3 x 3
 */

void topple(int grid[3][3])
{
	int i, j;
	int nextpiles[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; i < 3; j++)
			nextpiles[i][j] = 0;
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i + 1 < 3)
					nextpiles[i + 1][j] += 1;
				if (i - 1 >= 0)
					nextpiles[i - 1][j] += 1;
				if (j + 1 < 3)
					nextpiles[i][j + 1] += 1;
				if (j - 1 >= 0)
					nextpiles[i][j - 1] += 1;
			}
		}
	}
	sum_grids(grid, nextpiles);
}


/**
 * sandpiles_sum -sum iteratively two sandpiles
 * @grid1: type int a sandpile 3 x 3
 * @grid2: type int a sandpile 3 x 3
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

	sum_grids(grid1, grid2);
	while (if_sandpile(grid1) == 0)
	{
		print_grid(grid1);
		topple(grid1);
	}
}
