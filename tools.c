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

void	ft_printhash(t_hash *lst)
{
	while (lst)
	{
		ft_putchar(lst->type);
		ft_putchar('\n');
		ft_putnbr(lst->x[0]);
		ft_putnbr(lst->x[1]);
		ft_putnbr(lst->x[2]);
		ft_putnbr(lst->x[3]);
		ft_putchar('\n');
		ft_putnbr(lst->y[0]);
		ft_putnbr(lst->y[1]);
		ft_putnbr(lst->y[2]);
		ft_putnbr(lst->y[3]);
		ft_putchar('\n');
		lst = lst->next;
	}
}
