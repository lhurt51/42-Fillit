/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:12:59 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/12 14:13:00 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	findkey(int *x, int *y, char **grid)
{
	int i;
	int j;

	i = 3;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (grid[i][j] == '#')
			{
				if (i < *y)
					*y = i;
				if (j < *x)
					*x = j;
			}
			j--;
		}
		i--;
	}
}

int		*findpointx(char **grid, int xdef, int y, int x)
{
	int	first;
	int *pointx;
	int pc;

	pointx = (int*)malloc(sizeof(int) * 4);
	pc = 0;
	while (y < 4)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '#')
			{
				pointx[pc] = (x - xdef);
				if (pc == 0)
					first = pointx[pc];
				if (first)
					pointx[pc] -= 1;
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointx);
}

int		*findpointy(char **grid, int ydef, int y, int x)
{
	int	first;
	int *pointy;
	int pc;

	pointy = (int*)malloc(sizeof(int) * 4);
	pc = 0;
	while (y < 4)
	{
		x = 0;
		while (grid[y][x])
		{
			if (grid[y][x] == '#')
			{
				pointy[pc] = (y - ydef);
				if (pc == 0)
					first = pointy[pc];
				if (first)
					pointy[pc] -= 1;
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointy);
}

void	storepoints(t_hash **bgnlst, char *str, unsigned int i)
{
	char	**grid;
	int		*x;
	int		*y;

	x = (int*)malloc(sizeof(int) * 1);
	y = (int*)malloc(sizeof(int) * 1);
	*x = 4;
	*y = 4;
	grid = ft_strsplit(str, '\n');
	findkey(x, y, grid);
	if (i == 0)
		*bgnlst = ft_newhash(i, findpointx(grid, *x, 0, 0),
			findpointy(grid, *y, 0, 0));
	else
		ft_addhash(bgnlst, ft_newhash(i, findpointx(grid, *x, 0, 0),
			findpointy(grid, *y, 0, 0)));
	free(x);
	free(y);
}
