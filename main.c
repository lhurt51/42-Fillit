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

t_hash	*storepieces(char *av)
{
	t_hash			*pieces;
	char			str[SIZE + 1];
	unsigned int	i;
	int				fd;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (error("error: failed to open file"));
	while (read(fd, str, SIZE + 1))
	{
		if(i == 26)
			return (error("error: to many tetrimino's"));
		str[SIZE] = '\0';
		if (!tetriminocheck(str))
			return (error("error: bad hash format"));
		storepoints(&pieces, str, i);
		i++;
	}
	if (i == 0)
		return (error("error: no content"));
	close(fd);
	return (pieces);
}

char	**build_board(unsigned int size)
{
	unsigned int	i;
	char			**board;

	i = 0;
	board = (char**)malloc(sizeof(char*) * (size + 1));
	while (i < size)
	{
		board[i] = ft_strnew(size + 1);
		board[i] = ft_memset(board[i], '.', size);
		i++;
	}
	board[i] = 0;
	return (board);
}

int		get_size(t_hash *lst)
{
	unsigned int	size;
	unsigned int	i;

	size = ft_hashcount(&lst);
	size *= 4;
	i = 0;
	while (!i)
	{
		i = find_sqrt(1, size);
		size++;
	}
	return (i);
}

int		main(int argc, char **argv)
{
	t_hash			*tmp;
	char			**board;
	unsigned int	done;
	unsigned int	size;

	done = 0;
	if (argc != 2)
		return ((int)error("usage: ./fillit target_file"));
	tmp = storepieces(argv[1]);
	if (!tmp)
		return (0);
	size = get_size(tmp);
	while (!done)
	{
		board = build_board(size);
		done = fill_it_solve(size, 0, board, &tmp);
		if (!done)
			size++;
	}
	ft_hashdel(&tmp, &ft_hashdelone);
	print_board(board, size);
	return (1);
}
