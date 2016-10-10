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

void	my_lstdelone(t_list **alst, void (*del)(void**))
{
	if (*alst != NULL)
	{
		del(&(*alst)->content);
		free(*alst);
		*alst = NULL;
	}
}

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
		found = 0;
		piece = 1;
		// take this out make a function equal to piece then if piece we store the piece and del from lst
		while (lst)
		{
			// needs to search throught the entire list of tetriminos for every position
			if (is_valid_spot(n, (int)row, (int)col, board, lst))
			{
				found = 1;
				break ;
			}
			piece++;
			lst = lst->next;
		}
		if(found)
		{
			// when it has found a spot for a tetrimino it will store the tetrimino on the map
			// it has to relink the list and set the new lst equal to it
			t_list	*tmp;
			int		*x-axis;
			int		*y-axis;
			int		x;
			int		y;

			lst = *bgnlst;
			while (piece > 1)
			{
				lst = lst->next;
				if (piece > 2)
				piece--;
			}
			i = 0;
			x-axis = start->x;
			y-axis = start->y;
			while (i > 4)
			{
				x = x-axis[i];
				y = y-axis[i];
				board[row + y][col + x] = (char)(piece + 64);
			}
			tmp = lst->prev;
			tmp->next = lst->next;
			my_lstdelone(&lst, &ft_memdel);
			if (n_queens(n, row, **board, bgnlst))
				return (1);
		}
		col++;
	}
	if (row < n)
		fill_it_solve(n, row + 1, board, bgnlst);
	return (0);
}
