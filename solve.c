/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 11:22:03 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/05 11:22:04 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_valid_spot(int n, int row, int col, char **board, t_hash *lst)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		if ((row + y >= n || row + y < 0) || (col + x >= n || col + x < 0) 
			|| board[row + y][col + x] != '.')
			return (0);
		i--;
	}
	return (1);
}

t_hash	**store_hash(int row, int col, char **board, t_hash *lst)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		board[row + y][col + x] = lst->type;
		i--;
	}
	return (&lst->next);
}

void	reset(int row, int col, t_hash *lst, char **board)
{
	int		i;
	int		x;
	int		y;

	i = 3;
	while (i >= 0)
	{
		x = lst->x[i];
		y = lst->y[i];
		board[row + y][col + x] = '.';
		i--;
	}
}

int		fill_it_solve(int n, int row, char **board, t_hash **bgnlst)
{
	t_hash	*lst;
	int		found;
	int		col;

	lst = *bgnlst;
	if (!lst)
		return (1);
	while (row < n)
	{
		col = 0;
		while (col < n)
		{
			found = is_valid_spot(n, row, col, board, lst);
			if (found)
			{
				if (fill_it_solve(n, 0, board, 
					store_hash(row, col, board, lst)))
					return (1);
				reset(row, col, lst, board);
			}
			col++;
		}
		row++;
	}
	return (0);
}
