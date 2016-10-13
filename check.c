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

char	*ter_make(char *s, unsigned int *start, unsigned int *end)
{
	unsigned int	i;
	char			*new;

	i = 0;
	while (s[i] == '.' || s[i] == '\n')
		i++;
	*start = i;
	while (s[i])
		i++;
	while (i > *start && (s[i] == '.' || s[i] == '\n' || s[i] == '\0'))
		i--;
	*end = i;
	new = ft_strnew(*end - *start + 1);
	return (new);
}

char	*ft_tertrim(char const *s)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*new;
	
	new = ter_make((char*)s, &start, &end);
	if (!new)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		if (s[start] == '\n')
			start++;
		else
		{
			new[i] = s[start];
			start++;
			i++;	
		}

	}
	new[i] = '\0';
	return (new);
}

void set0(int *one, int *two, int *three, int *four)
{
	*one = 0;
	*two = 0;
	*three = 0;
	*four = 0;
}

int	sizecheck(char *str)
{
	int i;
	int hash;
	int len;
	int height;

	set0(&i, &hash, &len, &height);
	while (str[i])
	{
		if (str[i] == '.' || str[i] == '#')
			len++;
		if (str[i] == '#')
			hash++;
		if (str[i] == '\n')
		{
			if (len != 4)
				return (0);
			height++;
			len = 0;
		}
		if (height > 4 || hash > 4 || len > 4 || i > 21)
			return (0);
		i++;
	}
	return (1);
}

int		tetriminocheck(char *str)
{
	char *tmp;
	int i;

	i = 0;
	tmp = ft_tertrim(str);
	while(TESTER[i])
	{
		if(ft_strcmp(tmp, TESTER[i]) == 0 && sizecheck(str))
		{
			ft_strdel(&tmp);
			return (1);
		}
		i++;
	}
	ft_strdel(&tmp);
	return (0);
}
