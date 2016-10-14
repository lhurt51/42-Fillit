/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 14:31:15 by lhurt             #+#    #+#             */
/*   Updated: 2016/10/02 14:31:16 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define SIZE 20

static char *TESTER[] = {"#..##..#", "##...##", "#...##..#","#..###","#..##...#",
"###..#","#...##...#","##.##","##..##","#.###","##...#...#","###.#","#...#...##","###...#","##..#...#",
"#...###","#...#..##","####","#...#...#...#"};

typedef struct		s_hash
{
	int				*x;
	int				*y;
	char			type;
	struct s_hash	*next;
}					t_hash;

void				ft_putendl(char const *s);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

void				*error(char *msg);
int					find_sqrt(int n, int nb);
void				print_board(char **board, unsigned int size);
int					ft_hashcount(t_hash **bgnlst);
void				ft_addhash(t_hash **bgnlst, t_hash *lst);
t_hash				*ft_newhash(unsigned int i, int	*x, int *y);
void				ft_hashdelone(t_hash **alst, void (*del)(void**));
void				ft_hashdel(t_hash **alst, void (*del)(t_hash**, void (*del)(void**)));
int					tetriminocheck(char *str);
void				storepoints(t_hash **bgnlst, char *str, unsigned int i);
int					fill_it_solve(int n, int row, char **board, t_hash **bgnlst);

#endif
