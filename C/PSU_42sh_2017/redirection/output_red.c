/*
** EPITECH PROJECT, 2018
** minishe
** File description:
** by Ori
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

int	change_fd(list_t *a, int i)
{
	if (a->left == NULL && a->right == NULL)
		return (0);
	if (i == 1)
		a->left->fd = open(a->right->name, O_CREAT | O_RDWR
				| O_TRUNC, 0644);
	else
		a->left->fd = open(a->right->name, O_CREAT | O_RDWR
				| O_APPEND, 0644);
	if (a->fd == -1) {
		close(a->fd);
		my_putstr_error("Error opening file\n");
		return (0);
	}
	return (1);
}
