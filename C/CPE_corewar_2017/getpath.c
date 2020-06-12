/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "list.h"

char  **next_line(coordinates *p, int *g, char *str, char leter, char **ptr)
{
	while (str[(*g)] == leter) {
		//p->x = -1;
		(*g)++;
	}
	(*g)--;
	ptr[p->y][p->x] = '\0';
	p->y++;
	return (ptr);
}

char **last_char(char **ptr, coordinates *p)
{
	p->x++;
	if (ptr[p->y][0] == '\n')
		ptr[p->y] = NULL;
	else
		ptr[p->y][p->x] = '\0';
	ptr[p->y + 1] = NULL;
	return (ptr);
}

int only_sum(int i, char *str, char leter, int g, coordinates *p)
{
	if (i == 0) {
		while (str[g] == leter) {
			g++;
		}
		g--;
	}
	return (g);
}

char **get_path_array(char *str, char leter)
{
 	int		g;
	char		**ptr;
	int		num_ar = 0;
	coordinates	*p;
	int		i = 0;

	p = feed_p();
	num_ar = num_arg(str, leter);
	ptr = malloco(num_ar);
	for (g = 0; str[g] != '\0'; g++) {
		p->x++;
		if (str[g] != leter) {
			i = 1;
			ptr[p->y][p->x] = str[g];
		}
		else {
			g = only_sum(i, str, leter, g, p);
			if (i != 0)
				ptr = next_line(p, &g, str, leter, ptr);
			p->x = -1;
		}
	}
	ptr = last_char(ptr, p);
	return (ptr);
}

char **getpath(char **env)
{
	int	i;
	char	**path;
	for (i = 0; env[i] != NULL; i++)
	{
		if (env[i][0] == 'P' && env[i][1] == 'A'\
		    && env[i][2] == 'T' && env[i][3] == 'H') {
			path = get_path_array(&env[i][5], ':');
			return (path);
		}
	}
	return (NULL);
}
