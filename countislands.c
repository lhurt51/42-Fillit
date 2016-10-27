/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countislands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/23 18:51:18 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/27 10:49:36 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		get_ydimen(char **map)
{
	int i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

static int		get_xdimen(char **map)
{
	return ft_strlen(map[0]);
}

static void		delete_island(char **map, int x, int y)
{
	if (map[x][y] == '#')
	{
		map[x][y] = '.';
		if (x > 0)
			delete_island(map, x - 1, y);
		if (x < get_xdimen(map) - 1)
			delete_island(map, x + 1, y);
		if (y > 0)
			delete_island(map, x, y - 1);
		if (y < get_ydimen(map) - 1)
			delete_island(map, x, y + 1);
	}

}

int				count_islands(char **map)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (j < get_ydimen(map))
	{
		while (i < get_xdimen(map))
		{
			if (map[i][j] == '#')
			{
				count++;
				delete_island(map, i, j);
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (count);
}
