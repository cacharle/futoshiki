/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cacharle <charles.cabergs@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 12:31:20 by cacharle          #+#    #+#             */
/*   Updated: 2019/07/14 15:04:11 by cacharle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "futo.h"

/*
** Parse the program's first argument where each row is in order
** col up, col down, row left, row right
*/

/*
** Allocate memory for a 2D array(square) of `size`
** initialize each cell to 0.
*/

Square square_init(int size)
{
	int i;
	int j;
	Square square;

	square = malloc(sizeof(int*) * size);
	i = 0;
	while (i < size)
	{
		square[i] = malloc(sizeof(int) * size);
		j = 0;
		while (j < size)
			square[i][j++] = 0;
		i++;
	}
	return (square);
}

/*
** Duplicate the square, create an empty clone
** and copy each element of `square` in it.
*/

Square square_dup(int **square)
{
	int **clone;
	int	i;
	int	j;

	clone = square_init(4);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			clone[i][j] = square[i][j];
			j++;
		}
		i++;
	}
	return (clone);
}

/*
** Free each row of the square and the square itself.
*/

void square_destroy(int **square)
{
	int i;

	i = 0;
	while (i < 4)
		free(square[i++]);
	free(square);
}

/*
** Print each row followed by a line break
** and each element of the row but the last followed by a space.
*/

void square_print(Square square)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%d", square[i][j]);
			j++;
			if (j != 4)
				putchar(' ');
		}
		putchar('\n');
		i++;
	}
}
