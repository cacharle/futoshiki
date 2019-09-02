#include <stdio.h>
#include <stdbool.h>
#include "futo.h"

bool solve(Square *square, Comparison *comparisons, int *solved)
{
	int		row;
	int		col;
	Square	*square_clone;

	if (!find_next_unassigned(square, &row, &col))
    {
        if (!comparisons_respected(square, comparisons))
            return false;
		square_print(square);
		return true;
    }

    for (int i = 1; i <= square->len; i++)
	{
		if (!is_alone(square, i, row, col))
			continue ;
		square_clone = square_dup(square);
		square_clone->self[row][col] = i;
		if (solve(square_clone, comparisons, solved))
		{
			*solved = true;
			square_destroy(square_clone);
			return true;
		}
		square_destroy(square_clone);
	}
	return false;
}

static int square_at(Square *square, int *index)
{
    return square->self[index[0]][index[1]];
}

bool comparisons_respected(Square *square, Comparison *comparisons)
{
    for (int i = 0; comparisons[i].index_lesser[0] != -1; i++)
    {
        int lesser = square_at(square, comparisons[i].index_lesser);
        int greater = square_at(square, comparisons[i].index_greater);
        if (lesser > greater)
            return false;
    }
    return true;
}

bool find_next_unassigned(Square *square, int *row, int *col)
{
    for (*row = 0; *row < square->len; (*row)++)
    {
        for (*col = 0; *col < square->len; (*col)++)
			if (square->self[*row][*col] == UNASSIGNED)
				return true;
    }
	return false;
}

bool is_alone(Square *square, int value, int row, int col)
{
    for (int i = 0; i < square->len; i++)
		if (i != col && square->self[row][i] == value)
			return false;
    for (int i = 0; i < square->len; i++)
		if (i != row && square->self[i][col] == value)
			return false;
	return true;
}
