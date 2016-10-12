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

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_hash
{
	int				*x;
	int				*y;
	char			type;
	struct s_hash	*next;
}					t_hash;

void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				*ft_memset(void *b, int c, size_t len);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_atoi(const char *c);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_printlst(t_list *alst);
int					ft_lstcheck(t_list **begin, int (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_addhash(t_hash **bgnlst, t_hash *lst);
t_hash				*ft_newhash(unsigned int i, int	*x, int *y);
void				ft_hashdelone(t_hash **alst, void (*del)(void**));
void				ft_hashdel(t_hash **alst, void (*del)(t_hash**, void (*del)(void**)));
int					tetriminocheck(t_list *lst);
t_hash				*storepoints(t_list **heads);
int					fill_it_solve(int n, int row, char **board, t_hash **bgnlst);


#endif
