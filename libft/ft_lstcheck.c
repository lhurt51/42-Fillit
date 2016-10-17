/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:47:55 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/10 11:48:01 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstcheck(t_list **begin, int (*f)(t_list *elem))
{
	t_list *lst;

	lst = *begin;
	if (!lst)
		return (0);
	while (lst)
	{
		if (!f(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}
