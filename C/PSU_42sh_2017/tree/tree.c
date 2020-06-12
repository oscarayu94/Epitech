/*
** EPITECH PROJECT, 2018
** tree
** File description:
** by oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

list_t	*tree_semicolon(list_t *prev, list_t *a, char **str,
			char *semicolon)
{
	a->name = semicolon;
	a->prev = prev;
	if (str[1] == NULL) {
		a->name = str[0];
		a->left = NULL;
		a->right = NULL;
		return (a);
	}
	a->left = malloc(sizeof(list_t));
	a->right = malloc(sizeof(list_t));
	if (a->left == NULL || a->right == NULL)
		exit(84);
	a->left->prev = a;
	a->left->name = str[0];
	a->left->left = NULL;
	a->left->right = NULL;
	tree_semicolon(a, a->right, &str[1], semicolon);
	return (a);
}

char	*delete_lateral_space(char *name)
{
	int	i = 0;
	int	g = 0;

	for (i = 0; name[i] == ' '; i++);
	if (i != 0) {
		for (g = 0; name[i] != '\0'; g++, i++)
			name[g] = name[i];
		name[g] = '\0';
	}
	for (i = 0; name[i] != '\0'; i++);
	for (i = i - 1; name[i] == ' '; i--)
		name[i] = '\0';
	return (name);
}

void	delete_this_value(char **str, char *a)
{
	int	g = 0;
	int	i;

	for (i = 0; str[i] != NULL; i++)
		if (my_strcmp(str[i], a) == 1)
			for (g = i; str[g] != NULL; g++)
				str[g] = str[g + 1];
	for (i = 0; str[i] != NULL; i++);
	if (str[i - 1] != NULL && str[i - 1][0] == '\0')
		str[i - 1] = NULL;
}

void	tree(list_t **begin, list_t *a)
{
	char	**str;
	int	pass = 0;
	char	*character = "<>|&";
	char	*mem = initialize_mem();
	int	g = 0;

	for (int i = 0; character[i] != '\0' && pass == 0 &&
		a->name != NULL; i++) {
		g = first_instruct(a->name, mem);
		if (g != -1)
			i = g;
		str = get_path_array_string(a->name, character[g]);
		pass = send_to_tree_semicolon(str, *begin, a , g);
		str = get_path_array_string(a->name, character[g]);
		pass = send_to_tree_semicolon(str, *begin, a , g + 4);
		str = get_path_array_string(a->name, character[i]);
		pass = send_to_tree_semicolon(str, *begin, a, i);
		str = get_path_array(a->name, character[i]);
		pass = send_to_tree_semicolon(str, *begin, a, i + 4);
	}
	if (a->right != NULL && a->left != NULL && pass == 0) {
		tree(begin, a->left);
		tree(begin, a->right);
	}
}

list_t	*tree_start(list_t *a, char *list)
{
	char	**str = get_path_array(list, ';');
	char	**character = characters();

	tree_semicolon(NULL, a, str, ";");
	tree(&a, a);
	a->you_are = 'm';
	initialize_some_var(a);
	initialize_char(a, character);
	return (a);
}
