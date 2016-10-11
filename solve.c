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

void	print(t_hash *lst)
{
	while (lst)
	{
		ft_putnbr(lst->x[0]);
		ft_putnbr(lst->x[1]);
		ft_putnbr(lst->x[2]);
		ft_putnbr(lst->x[3]);
		ft_putendl("");
		ft_putendl("|-|-|-|-|");
		ft_putnbr(lst->y[0]);
		ft_putnbr(lst->y[1]);
		ft_putnbr(lst->y[2]);
		ft_putnbr(lst->y[3]);
		ft_putendl("");
		ft_putchar(lst->type);
		ft_putnbr(lst->found);
		ft_putendl("");
		ft_putendl("");
		lst = lst->next;
	}
}

int		is_valid_spot(int n, int row, int col, char **board, t_hash *lst)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = lst->x[i];
		y = lst->y[i];
		if (board[row + y][col + x] != '.' || ((row + y) >= n) || ((col + x) >= n))
			return (0);
		i++;
	}
	return (1);
}

t_hash	*store_hash(int row, int col, char **board, t_hash **bgnlst)
{
	t_hash *tmp;
	int		x;
	int		y;
	int		i;

	i = 0;
	tmp = *bgnlst;
	while (tmp->found != 1)
		tmp = tmp->next;
	while (i < 4)
	{
		x = tmp->x[i];
		y = tmp->y[i];
		board[row + y][col + x] = tmp->type;
		i++;
	}
	tmp->found = 2;
	return (tmp);
}

int		check_entire_lst(int n, int row, int col, char **board, t_hash **bgnlst)
{
	t_hash	*lst;

	lst = *bgnlst;
	while (lst)
	{
		if (is_valid_spot(n, (int)row, (int)col, board, lst) && lst->found == 0)
		{
			lst->found = 1;
			ft_putendl("it has been found");
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void	reset(int n, char **str, t_hash *tmp, t_hash **bgnlst)
{
	int i;
	int j;

	i = 0;
	ft_putendl("it has been reset");
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (str[i][j] == tmp->type)
				str[i][j] = '.';
			j++;
		}
		i++;
	}
	tmp->found = 0;
	while (tmp->prev)
		tmp = tmp->prev;
	*bgnlst = tmp;
}

int		fill_it_solve(int n, int row, char **board, t_hash **bgnlst)
{
	t_hash	*lst;
	t_hash	*tmp;
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
			found = check_entire_lst(n, row, col, board, &lst);
			if(found)
			{
				ft_putendl("fresh");
				print(lst);
				tmp = store_hash(row, col, board, &lst);
				ft_putendl("modified");
				print(lst);
				if (fill_it_solve(n, row, board, &lst))
					return (1);
				else
				{
					reset(n, board, tmp, &lst);
					col--;
				}
			}
			col++;
		}
		row++;
	}
	return (0);
}

int		main()
{
	t_hash	*lst;
	char **board;
	int	i;
	int j;
	int	x1[4] = {0, 1, 2, 2};
	int	y1[4] = {0, 0, 0, 1};
	int x2[4] = {0, 0, 1, 0};
	int y2[4] = {0, 1, 1, 2};
	int x3[4] = {0, 1, 1, 2};
	int y3[4] = {0, 0, 1, 1};

	i = 0;
	board = (char**)malloc(sizeof(char*) * 5);
	while (i < 4)
	{
		board[i] = ft_strnew(5);
		board[i] = ft_memset(board[i], '.', 4);
		i++;
	}
	lst = ft_newhash(0, x1, y1);
	ft_addhash(&lst, ft_newhash(1, x2, y2));
	ft_addhash(&lst, ft_newhash(2, x3, y3));
	if(fill_it_solve(4, 0, board, &lst))
		ft_putendl("It worked!!!!");
	else
		ft_putendl("It didnt work!!!!");
	j = 0;
	while (j < 4)
	{
		ft_putendl(board[j]);
		j++;
	}
}