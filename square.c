#include <stdlib.h>
#include <stdio.h>
#include "futo.h"

Square *square_init(int size)
{
    Square *square = malloc(sizeof(Square));
	square->self = malloc(sizeof(int*) * size);
    square->len = size;
    for (int i = 0; i < size; i++)
	{
		square->self[i] = malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++)
			square->self[i][j++] = UNASSIGNED;
	}
	return square;
}

Square *square_dup(Square *square)
{
    Square *clone = square_init(square->len);
    for (int i = 0; i < square->len; i++)
	{
        for (int j = 0; j < square->len; j++)
			clone->self[i][j] = square->self[i][j];
	}
	return clone;
}

void square_destroy(Square *square)
{
    for (int i = 0; i < square->len; i++)
		free(square->self[i]);
	free(square);
}

void square_print(Square *square)
{
    for (int i = 0; i < square->len; i++)
    {
        for (int j = 0; j < square->len; j++)
		{
			printf("%d", square->self[i][j]);
			if (j != square->len)
				putchar(' ');
		}
		putchar('\n');
	}
}
