#include <stdbool.h>
#include "futo.h"

/*
** Find all the sudoku 4x4 grid recursively
** print the one that checks out with the given viewpoints
*/

int	solve(Square square, Comparison *comparisons, int *solved)
{
	int		row;
	int		col;
	int		i;
	Square	board_clone;

	if (!find_next_unassigned(square, &row, &col))
    {
		print_square(square);
		return (TRUE);
    }
	i = 0;
	while (++i <= 4)
	{
		if (!is_alone(square, row, col, i))
			continue ;
		board_clone = dup_square(square);
		board_clone[row][col] = i;
		if (solve(board_clone, comparisons, solved)
            && comparisons_respected(board_clone, comparisons))
		{
			*solved = TRUE;
			destroy_square(board_clone);
			return (TRUE);
		}
		destroy_square(board_clone);
	}
	return (FALSE);
}

int comparisons_respected(Square square, Comparison *comparisons)
{

    return false;
}


/*
** Move `row` and `col` to the next unassigned(== 0) position
** returns FALSE if the square is already filled with number, TRUE otherwise
*/

int	find_next_unassigned(Square square, int *row, int *col)
{
	*row = 0;
	while (*row < 4)
	{
		*col = 0;
		while (*col < 4)
		{
			if (square[*row][*col] == UNASSIGNED)
				return (TRUE);
			(*col)++;
		}
		(*row)++;
	}
	return (FALSE);
}

/*
** Check if `building_floor` is already is unique in the row and column
*/

int	is_alone(Square square, int row, int col, int building_floor)
{
	int i;

	i = 0;
	while (i < 4)
		if (square[row][i++] == building_floor)
			return (FALSE);
	i = 0;
	while (i < 4)
		if (square[i++][col] == building_floor)
			return (FALSE);
	return (TRUE);
}
