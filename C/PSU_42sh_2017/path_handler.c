/*
** EPITECH PROJECT, 2018
** minsihel
** File description:
** by oriol
*/

#include	"list.h"

char	**last_char(char **ptr, coordinates *p)
{
	if (ptr[p->y][0] == '\n')
		ptr[p->y] = NULL;
	else
		ptr[p->y][p->x] = '\0';
	ptr[p->y + 1] = NULL;
	return (ptr);
}

void	only_sum(int i, char *str, char leter, int *g)
{
	if (str[(*g)] == leter) {
		while (str[(*g)] == leter)
			(*g)++;
		(*g)--;
	}
}

void	only_sum_string(int i, char *str, char leter, int *g)
{
	if (str[(*g)] == leter) {
		for (int i = 0; str[(*g)] == leter && i != 2; i++)
			(*g)++;
		(*g)--;
	}
}

char	**get_path_array_string(char *str, char leter)
{
	int		g;
	char		**ptr;
	int		num_ar = 0;
	coordinates	*p;
	int		i = 0;

	p = feed_p();
	num_ar = num_arg_string(str, leter);
	ptr = malloca(num_ar);
	for (g = 0; str[g] != '\0'; g++) {
		p->x++;
		if (str[g] == leter &&
		(str[g + 1] == leter ||
		(g != 0 && str[g - 1] == leter))) {
			ptr[p->y][p->x] = '\0';
			only_sum_string(i, str, leter, &g);
			p->x = -1;
			p->y++;
		}
		else
			ptr[p->y][p->x] = str[g];
	}
	p->x++;
	ptr = last_char(ptr, p);
	return (ptr);
}

char	**get_path_array(char *str, char leter)
{
	int		g;
	char		**ptr;
	int		num_ar = 0;
	coordinates	*p;
	int		i = 0;

	p = feed_p();
	num_ar = num_arg(str, leter);
	ptr = malloca(num_ar);
	for (g = 0; str[g] != '\0'; g++) {
		p->x++;
		if (str[g] != leter) {
			i = 1;
			ptr[p->y][p->x] = str[g];
		}
		else {
			if (i != 0)
				ptr[p->y][p->x] = '\0';
			only_sum(i, str, leter, &g);
			p->x = -1;
			p->y++;
		}
	}
	p->x++;
	ptr = last_char(ptr, p);
	return (ptr);
}
