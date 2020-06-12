/*
** EPITECH PROJECT, 2018
** initialize_tree
** File description:
** BY PETER ft ORIOL
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

char	*initialize_mem(void)
{
	char *memo = malloc(sizeof(char) * 5);

	if (memo == NULL)
		exit(84);
	for (int i = 0; i != 4; i++)
		memo[i] = '0';
	memo[4] = '\0';
	return (memo);
}

void	initialize_char(list_t *list, char **character)
{
	for (int i = 0; character[i] != NULL; i++) {
		if (my_strcmp(character[i], list->name))
			list->you_are = 'm';
	}
	if (list->left != NULL && list->right != NULL) {
		initialize_char(list->left, character);
		initialize_char(list->right, character);
	}
}

void	initialize_some_var(list_t *list)
{
	list->fd = 1;
	list->name = delete_enter(list->name);
	list->name = delete_lateral_space(list->name);
	list->have_passed = 0;
	list->number = 1;
	list->truee = 1;
	if (list->left != NULL && list->right != NULL) {
		initialize_some_var(list->left);
		initialize_some_var(list->right);
		list->left->you_are = 'l';
		list->right->you_are = 'r';
	}
}
