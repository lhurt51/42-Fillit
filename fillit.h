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
	int 			found;
	struct s_hash	*next;
	struct s_hash	*prev;
}					t_hash;

void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int nb);
void				*ft_memset(void *b, int c, size_t len);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
int					ft_atoi(const char *c);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *s);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t l);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_printlst(t_list *alst);
int					ft_lstcheck(t_list **begin, int (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
int					tetriminocheck(t_list *lst);
int					fill_it_solve(int n,char **board, t_hash **bgnlst);
void				del(void *str);
void				my_lstdelone(t_hash **alst, void (*del)(void*));
void				ft_addhash(t_hash **bgnlst, t_hash *lst);
t_hash				*ft_newhash(unsigned int i, int	*x, int *y);


#endif
