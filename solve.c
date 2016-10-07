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

int		fill_it_solve(int n, int *row, int *col, char **board, t_list *start)
{
	t_list	*lst;
	int		piece;
	int		found;

	lst = start;
	if (n == row)
		return (1);
	while (row < n)
	{
		while (col < n)
		{
			found = 1;
			piece = 0;
			while (lst)
			{
				// needs to search throught the entire list of tetriminos for every position
			}
			if(found)
			{
				// when it has found a spot for a tetrimino it will 
			}
			(*col)++;
		}
		(*row)++;
	}
	return (0);
}
