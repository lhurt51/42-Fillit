/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 13:49:34 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/11 13:49:36 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_hash	*ft_newhash(unsigned int i, int	*x, int *y)
{
	t_hash	*new;

	new = malloc(sizeof(t_hash));
	if (new)
	{
		if (x == NULL || y == NULL)
		{
			new->x = NULL;
			new->y = NULL;
			new->type = 0;
		}
		else
		{
			new->type = (char)(i + 65);
			if (!(new->x = ft_memalloc(4 * 4)) 
				|| !(new->y = ft_memalloc(4 * 4)))
				return (NULL);
			new->x = (int*)ft_memcpy(new->x, x, 4 * 4);
			new->y = (int*)ft_memcpy(new->y, y, 4 * 4);
		}
		new->next = NULL;
	}
	return (new);
}

void	ft_addhash(t_hash **bgnlst, t_hash *lst)
{
	t_hash	*tmp;

	tmp = *bgnlst;
	if (!tmp)
	{
		*bgnlst = lst;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
}

int		ft_hashcount(t_hash **bgnlst)
{
	t_hash			*lst;
	int	i;

	i = 0;
	lst = *bgnlst;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

void	my_lstdelone(t_hash **alst, void (*del)(void*))
{
	if (*alst != NULL)
	{
		del((*alst)->x);
		del((*alst)->y);
		free(*alst);
		*alst = NULL;
	}
}

void	del(void *str)
{
	free(str);
}
