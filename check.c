#include "fillit.h"
#include <stdio.h>
 

int		findspace(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '.' || s[i] == '\n')
		i++;
	return (i);
}

char	*ft_tertrim(char const *s)
{
	unsigned	i;
	unsigned	start;
	unsigned	end;
	char		*new;

	i = findspace((char*)s);
	start = i;
	while (s[i])
		i++;
	while ((s[i] == '.' || s[i] == '\n' || s[i] == '\0') && i > start)
		i--;
	end = i;
	new = ft_strnew(end - start + 1);
	i = 0;
	if (!new)
		return (NULL);
	while (start <= end)
	{
		if (s[start] == '\n')
			start++;
		else
		{
			new[i] = s[start];
			start++;
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

int		tetriminocheck(t_list *lst)
{
	char *str;
	int i;

	str = lst->content;
	str = (ft_tertrim(str));
	i = 0;
	while(TESTER[i])
	{
		if(ft_strcmp(TESTER[i],str) == 0)
			return (1);
		else
			i++;
	}
	return(0);
}
