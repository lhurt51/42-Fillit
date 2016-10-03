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
	// 0 is my NULL or Fail int
	return (NULL);
}

void	ft_printlst(t_list *alst)
{
	t_list *list;

	list = alst;
	while (list)
	{
		ft_putendl(list->content);
		list = list->next;
	}
}

int		checkfile(char *av)
{
	char buff;
	int	fd;
	// unsigned	hashcount;
	unsigned	row;
	unsigned	col;

	fd = open(av, O_RDONLY);
	row = 0;
	col = 0;
	if (fd == -1)
		return ((int)error("error: failed to open file"));
	while (read(fd, &buff, 1))
	{
		if (buff == '\n' && row < 5)
			row++;
		else if (row == 0)
			col++;
		// cant be more than 4 wide
		// 4 tall
		// can only have 4 hashes
		// dots should fill the remainder of the space
	}
	if (row != 5 || col != 4)
		return ((int)error("error: file not formated correctly"));
	return (1);
}

t_list	*storepieces(char *av)
{
	t_list	*pieces;
	char	*str;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (error("error: failed to open file"));
	str = ft_strnew(SIZE + 1);
	if (!str)
		return (error("error: failed to malloc"));
	while (read(fd, str, SIZE + 1))
		ft_lstadd(&pieces, ft_lstnew(str, SIZE + 1));
	return (pieces);
}

int		main(int argc, char **argv)
{
	t_list	*new;

	if (argc != 2)
		return ((int)error("usage: ./fillit target_file"));
	if (!checkfile(argv[1]))
		return (0);
	new = storepieces(argv[1]);
	ft_printlst(new);
	return (1);
}