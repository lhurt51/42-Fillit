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

int		fill_it_solve(int n, int row, char **board, t_list **bgnlst);

int		is_valid_spot(int n, int row, int col, char **board, t_list *start)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = start->x[i];
		y = start->y[i];
		if (board[row + y][col + x] == '#' || (row + y) >= n 
					|| (col + x) >= n)
			return (0);
		i++;
	}
	return (1);
}

int		store_hash(int row, int col, char **board, t_list **bgnlst, t_list *tmp)
{
	t_list	*lst;
	int		x;
	int		y;

	lst = *bgnlst;
	while (piece > 1)
	{
		lst = lst->next;
		if (piece > 2)
			tmp = tmp->next;
		piece--;
	}
	tmp->next = lst->next;
	while (tmp->prev)
		tmp = tmp->prev;
	*bgnlst = tmp;
	my_lstdelone(&lst, &ft_memdel);
	i = 0;
	while (i > 4)
	{
		x = start->x[i];
		y = start->y[i];
		board[row + y][col + x] = (char)(piece + 64);
		i--;
	}
	if (fill_it_solve(n, row, col, **board, bgnlst))
		return (1);
	return (0);
}

int		check_entire_lst(int row, int col, int *piece, char **board, 
			t_list **bgnlst)
{
	t_list lst;

	lst = *bgnlst;
	while (lst)
	{
		if (is_valid_spot(n, (int)row, (int)col, board, lst))
			return (1);
		(*piece)++;
		lst = lst->next;
	}
	return (0);
}

int		fill_it_solve(int n, int row, int col, char **board, t_list **bgnlst)
{
	t_list	*lst;
	int		piece;
	int		found;

	lst = *bgnlst;
	if (!lst)
		return (1);
	while (col < n)
	{
		piece = 0;
		found = check_entire_lst(n, (int)row, (int)col, &piece, board, bgnlst);
		if(found)
			store_hash(row, col, piece, board, bgnlst, *bgnlst);
		col++;
	}
	if (row < n)
		fill_it_solve(n, row + 1, 0, board, bgnlst);
	return (0);
}
