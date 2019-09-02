#ifndef __FUTO_H__
# define __FUTO_H__

# include <stdbool.h>

# define UNASSIGNED 0

typedef int** Square;
typedef struct
{
    int index_lesser[2];
    int index_greater[2];
} Comparison;

// futo.c
bool solve(Square square, Comparison *comparisons, int *solved);
bool comparisons_respected(Square square, Comparison *comparisons);
bool find_next_unassigned(Square square, int *row, int *col);
bool is_alone(Square square, int bfloor, int row, int col);

// square.c
Square square_init(int size);
Square square_dup(int **square);
void square_destroy(int **square);
void square_print(Square square);

#endif
