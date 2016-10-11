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

void	ft_hashiter(t_hash *tmp, t_hash **bgnlst, t_hash *(*f)(t_hash *elem))
{
	t_hash	*lst;

	lst = *bgnlst;
	while (lst)
	{
		if (lst == tmp)
		lst = lst->next;
	}
	return (head);
}

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
			if (!(new->x = ft_memalloc(4 * 4)) || !(new->y = ft_memalloc(4 * 4)))
				return (NULL);
			new->x = (int*)ft_memcpy(new->x, x, 4 * 4);
			new->y = (int*)ft_memcpy(new->y, y, 4 * 4);
		}
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

void	ft_addhash(t_hash **bgnlst, t_hash *lst)
{
	t_hash	*tmp;

	tmp = *bgnlst;
	while (tmp->next)
		tmp = tmp->next;
	lst->prev = tmp;
	tmp->next = lst;
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
