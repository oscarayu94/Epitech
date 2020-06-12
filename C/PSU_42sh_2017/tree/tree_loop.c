/*
** EPITECH PROJECT, 2018
** by oriolo
** File description:
** treelipo
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

int	create_separ(list_t *a)
{
	char	**str = NULL;

	if (a == NULL)
		return (0);
	str = get_path_array(a->name, ' ');
	if (str[0] == NULL) {
		return (0);
	}
	a->separ = get_pieces_space(str);
	return (1);
}

char	**execute_instruction(char **env, char **pwd, char *real_pwd,
			list_t *a)
{
	if (my_strcmp(a->name, "\0") == 1)
		return (env);
	if (a->you_are == 'm')
		env = options(env, pwd, a, real_pwd);
	if (a->left != NULL && a->right != NULL) {
		execute_instruction(env, pwd, real_pwd, a->left);
		execute_instruction(env, pwd, real_pwd, a->right);
	}
	return (env);
}
