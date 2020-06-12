/*
** EPITECH PROJECT, 2018
** d
** File description:
** dk
*/

#include "../list.h"
#include "linked_list.h"

void	free_space(space_t *a)
{
	space_t	*b;

	while (a) {
		b = a->next;
		free(a);
		a = b;
	}
}

void	print_space(space_t *a)
{
	while (a) {
		my_putstr(a->name);
		my_putstr("\n");
		a = a->next;
	}
}

int     place_dir_name_space(space_t **list, space_t *a, char *dir_name)
{
	space_t	*tmp;
	space_t	*new;

	new = malloc(sizeof(space_t));
	if (new == NULL)
		exit(84);
	new->name = dir_name;
	new->next = NULL;
	tmp = (*list);
	if (*list == NULL) {
		*list = new;
		return (0);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (0);
}

space_t	*get_pieces_space(char **str)
{
	space_t	*a = NULL;

	for (int i = 0; str[i] != NULL; i++) {
		if (my_strcmp("\0", str[i]) != 1)
			place_dir_name_space(&a, a, str[i]);
	}
	return (a);
}
