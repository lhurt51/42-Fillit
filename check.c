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

int		findspace(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '.' || s[i] == '\n')
		i++;
	return (i);
}

char	*ft_tertrim(char const *s)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*new;

	i = findspace((char*)s);
	start = i;
	while (s[i])
		i++;
	while (i > start && (s[i] == '.' || s[i] == '\n' || s[i] == '\0'))
		i--;
	end = i;
	new = ft_strnew(end - start + 1);
	i = 0;
	if (!new)
		return (NULL);
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

int		tetriminocheck(char *str)
{
	char *tmp;
	int i;

	i = 0;
	tmp = (ft_tertrim(str));
	while(TESTER[i])
	{
		if(ft_strcmp(tmp, TESTER[i]) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
