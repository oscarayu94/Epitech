/*
** EPITECH PROJECT, 2018
** input_red
** File description:
** by oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

int	change_fd_not_create(list_t *a, char *name)
{
	if (a->left == NULL || a->right == NULL)
		return (0);
	a->left->fd = open(a->right->name, O_RDONLY);
	if (a->left->fd == -1) {
		close(a->left->fd);
		a->fd = dup(1);
		my_putstr_error(a->right->name);
		my_putstr_error(": No such file or directory.\n");
	}
	else {
		if (dup2(a->fd, 0) == -1) {
			my_putstr_error("Error using dup2");
			return (0);
		}
	}
	return (1);
}
