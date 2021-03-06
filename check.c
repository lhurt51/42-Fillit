/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 14:13:11 by rpassafa          #+#    #+#             */
/*   Updated: 2016/10/12 14:13:12 by rpassafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		set0(int *one, int *two, int *three)
{
	*one = 0;
	*two = 0;
	*three = 0;
}

static int		sizecheck(char *str, int i)
{
	int hash;
	int len;
	int height;

	set0(&hash, &len, &height);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			len++;
		if (str[i] == '#')
			hash++;
		if (str[i] == '\n')
		{
			if (len != 4 || i > 19)
				return (0);
			height++;
			len = 0;
		}
		if (str[i + 1] == '\0' && len == 4)
			height++;
		i++;
	}
	if (height != 4 || hash != 4)
		return (0);
	return (1);
}

int				tetriminocheck(char *str)
{
	if (sizecheck(str, 0) && count_islands(ft_strsplit(str, '\n')) == 1)
		return (1);
	return (0);
}
