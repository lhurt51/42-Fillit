/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 11:56:00 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/13 11:56:01 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*error(char *msg)
{
	ft_putendl(msg);
	return (NULL);
}

int		find_sqrt(int n, int nb)
{
	if (n * n > nb)
	{
		return (0);
	}
	if (n * n == nb)
	{
		return (n);
	}
	else
	{
		return (find_sqrt(n + 1, nb));
	}
}

void	print_board(char **board, unsigned int size)
{
	unsigned int j;

	j = 0;
	while (j < size)
	{
		ft_putendl(board[j]);
		j++;
	}
}
