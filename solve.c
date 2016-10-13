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

	i = 0;
	while (i < 4)
	{
		x = lst->x[i];
		y = lst->y[i];
		// ft_putnbr(col);
		// ft_putnbr(row);
		// ft_putchar('\n');
		if ((row + y >= n || row + y < 0) || (col + x >= n || col + x < 0) 
			|| board[row + y][col + x] != '.')
			return (0);
		i++;
	}
	return (1);
}

t_hash	**store_hash(int row, int col, char **board, t_hash *lst)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 4)
	{
		x = lst->x[i];
		y = lst->y[i];
		board[row + y][col + x] = lst->type;
		i++;
	}
	return (&lst->next);
}

void	reset(int n, char **str, char c)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (str[i][j] == c)
				str[i][j] = '.';
			j++;
		}
		i++;
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
	while (row < n) // - lst->height
	{
		col = 0;
		while (col < n) // - lst->len
		{
			found = is_valid_spot(n, row, col, board, lst);
			if (found)
			{
				if (fill_it_solve(n, 0, board, 
					store_hash(row, col, board, lst)))
					return (1);
				reset(n, board, lst->type);
			}
			col++;
		}
		row++;
	}
	return (0);
}

// int		main()
// {
// 	t_hash	*lst;
// 	char **board;
// 	int	i;
// 	int j;
// 	int	x1[4] = {0, 1, 2, 2};
// 	int	y1[4] = {0, 0, 0, 1};
// 	int x2[4] = {0, 0, 1, 0};
// 	int y2[4] = {0, 1, 1, 2};
// 	int x3[4] = {0, 1, 1, 2};
// 	int y3[4] = {0, 0, 1, 1};

// 	i = 0;
// 	board = (char**)malloc(sizeof(char*) * 5);
// 	while (i < 4)
// 	{
// 		board[i] = ft_strnew(5);
// 		board[i] = ft_memset(board[i], '.', 4);
// 		i++;
// 	}
// 	lst = ft_newhash(0, x1, y1);
// 	ft_addhash(&lst, ft_newhash(1, x2, y2));
// 	ft_addhash(&lst, ft_newhash(2, x3, y3));
// 	if(fill_it_solve(4, 0, board, &lst))
// 		ft_putendl("It worked!!!!");
// 	else
// 		ft_putendl("It didnt work!!!!");
// 	j = 0;
// 	while (j < 4)
// 	{
// 		ft_putendl(board[j]);
// 		j++;
// 	}
// }