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

int		is_valid_spot(int n, int row, int col, char **board, t_list *start)
{
	//checking the position of the tetrimino to see if it is valid
	int		*x-axis;
	int		*y-axis;
	int		x;
	int		y;
	int		i;

	i = 0;
	x-axis = start->x;
	y-axis = start->y;
	while (i < 4)
	{
		x = x-axis[i];
		y = y-axis[i];
		if (board[row + y][col + x] == '#' || (row + y) >= n 
					|| (col + x) >= n)
			return (0);
		i++;
	}
	return (1);
}

int		fill_it_solve(int n, int row, char **board, t_list **bgnlst)
{
	t_list	*lst;
	int		col;
	int		piece;
	int		found;

	col = 0;
	lst = *bgnlst;
	if (!lst)
		return (1);
	while (col < n)
	{
		found = 1;
		piece = 1;
		// take this out make a function equal to piece then if piece we store the piece and del from lst
		while (lst)
		{
			// needs to search throught the entire list of tetriminos for every position
			if (!is_valid_spot(n, (int)row, (int)col, board, lst))
				found = 0;
			piece++;
			lst = lst->next;
		}
		if(found)
		{
			// when it has found a spot for a tetrimino it will store the tetrimino on the map 
		}
		col++;
	}
	if (row < n)
		fill_it_solve(n, row + 1, board, bgnlst);
	return (0);
}
