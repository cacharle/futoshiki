#ifndef __FUTO_H__
# define __FUTO_H__

# define UNASSIGNED 0
# define TRUE 1
# define FALSE 0

typedef int** Square;
typedef struct
{
    int index_less;
    int index_greater;
} Comparison;

int		solve(Square square, Comparison *comparisons, int *solved);
int comparisons_respected(Square square, Comparison *comparisons);
int		find_next_unassigned(Square square, int *row, int *col);
int		is_alone(Square square, int bfloor, int row, int col);
int		**init_square(int size);
int		**dup_square(int **square);
void	destroy_square(int **square);
void	print_square(Square square);

#endif
