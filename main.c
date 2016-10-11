/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:24:41 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/02 14:24:42 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*error(char *msg)
{
	ft_putendl(msg);
	return (NULL);
}

t_list	*storepieces(char *av)
{
	t_list	*pieces;
	char	str[SIZE + 1];
	int		fd;
	int		count;

	count = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (error("error: failed to open file"));
	while (read(fd, str, SIZE + 1))
	{
		if (count == 0)
		{
			pieces = ft_lstnew(str, SIZE + 1);
			count++;
		}
		else
			ft_lstadd(&pieces, ft_lstnew(str, SIZE + 1));
	}
	close(fd);
	return (pieces);
}

int		main(int argc, char **argv)
{
	t_list	*new;

	if (argc != 2)
		return ((int)error("usage: ./fillit target_file"));
	new = storepieces(argv[1]);
	if (!ft_lstcheck(&new, &tetriminocheck))
		return (0);
	ft_printlst(new);
	return (1);
}