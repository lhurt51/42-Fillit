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

void	print(t_hash *lst)
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
		lst = lst->next;
	}
}

char	**gridmal()
{
	char **grid;
	grid = (char**)malloc(sizeof(char*) * 4);
	grid[0] = (char*)malloc(sizeof(char) * 5);
	grid[1] = (char*)malloc(sizeof(char) * 5);
	grid[2] = (char*)malloc(sizeof(char) * 5);
	grid[3] = (char*)malloc(sizeof(char) * 5);
	return grid;
}

char **getgrid(char *str)
{
	int i;
	int x;
	int y;
	char **grid;

	y = 0;
	x = 0;
	i = 0;
	grid = gridmal();
	while(i < 20)
	{
		if (str[i] == '.' || str[i] == '#')
		{
			grid[y][x] = str[i];
			x++;
		}
		else if(str[i] == '\n')
		{
			grid[y][x] = '\0';
			y++;
			x = 0;
		}
		i++;
	}
	return grid;
}

void	findkey(int *x, int *y, char **grid)
{
	int i;
	int j;
	//printf("%s\n","here 1");
	i = 0;
	while(i < 4)
	{
		j = 0;
		while(grid[i][j])
		{
			if (grid[i][j] == '#')
			{
				if (i < *y)
					y[0] = i;
				if (j < *x)
					x[0] = j;
			}
			j++;
		}
		i++;
	}
}

int	*findpointx(char **grid, int xdef)
{
	int x;
	int y;
	int *pointx;
	int pc;

	pointx = (int*)malloc(sizeof(int) * 4);
	y = 0;
	pc  = 0;
	while (y < 5)
	{
		x = 0;
		while(grid[y][x])
		{
			if (grid[y][x] == '#')
			{
				pointx[pc] = (x - xdef);
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointx);
}

int	*findpointy(char **grid, int ydef)
{
	int x;
	int y;
	int *pointy;
	int pc;

	pointy = (int*)malloc(sizeof(int) * 4);
	y = 0;
	pc  = 0;
	while (y < 5)
	{
		x = 0;
		while(grid[y][x])
		{
			if (grid[y][x] == '#')
			{
				pointy[pc] = (y - ydef);
				pc++;
			}
			x++;
		}
		y++;
	}
	return (pointy);
}

t_hash	*storepoints(t_list **heads)
{
	t_list *lsts;
	t_hash *points;
	char *str;
	char **grid;
	int count;
	int x;
	int y;
	unsigned int i;
	
	i = 0;
	count = 0;
	x = 0;
	y = 0;
	lsts = *heads;
	while (lsts)
	{
		str = lsts->content;
		grid = getgrid(str);
		findkey(&x,&y,grid);
		if (count == 0)
		{
			points = ft_newhash(i, findpointx(grid,x),findpointx(grid,y));
			count++;
		}
		else
			ft_addhash(&points,ft_newhash(i,findpointx(grid,x),findpointx(grid,y)));
		lsts = lsts->next;
		i++;
	}
	print(points);
	return points;
}
