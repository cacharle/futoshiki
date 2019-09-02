#include <stdio.h>
#include <stdbool.h>
#include "futo.h"

bool solve(Square square, Comparison *comparisons, int *solved)
{
	int		row;
	int		col;
	Square	square_clone;

	if (!find_next_unassigned(square, &row, &col))
    {
		square_print(square);
		return true;
    }
    for (int i = 1; i <= 4; i++)
	{
		if (!is_alone(square, i, row, col))
			continue ;
		square_clone = square_dup(square);
		square_clone[row][col] = i;
		if (solve(square_clone, comparisons, solved)
            && comparisons_respected(square_clone, comparisons))
		{
			*solved = true;
			square_destroy(square_clone);
			return true;
		}
		square_destroy(square_clone);
	}
	return false;
}

bool comparisons_respected(Square square, Comparison *comparisons)
{

    return false;
}

bool find_next_unassigned(Square square, int *row, int *col)
{
    for (*row = 0; *row < 4; (*row)++)
    {
        for (*col = 0; *col < 4; (*col)++)
			if (square[*row][*col] == UNASSIGNED)
				return true;
    }
	return false;
}

bool is_alone(Square square, int value, int row, int col)
{
    for (int i = 0; i < 4; i++)
		if (i != col && square[row][i] == value)
			return false;
    for (int i = 0; i < 4; i++)
		if (i != row && square[i][col] == value)
			return false;
	return true;
}
