/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:46:17 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/10 11:46:18 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list *alst)
{
	t_list *list;

	list = alst;
	while (list)
	{
		if (list->content)
			ft_putendl(list->content);
		list = list->next;
	}
}
