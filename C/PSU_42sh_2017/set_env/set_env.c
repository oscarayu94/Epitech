/*
** EPITECH PROJECT, 2018
** epitech
** File description:
** by oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

char	*empty(char *env)
{
	int	i;

	for (i = 0; env[i] != '\0'; i++)
	{
		if (env[i] == '=')
			env[i + 1] = '\0';
	}
	return (env);
}

char	*change_value(char *env, char *str)
{
	int	i;
	int	g;
	char	*result;

	i = my_strlen(env) + my_strlen(str);
	result = malloc(sizeof(char) * i);
	for (i = 0; env[i] != '='; i++)
		result[i] = env[i];
	result[i] = '=';
	i++;
	for (g = 0; str[g] != '\0'; g++, i++)
		result[i] = str[g];
	result[i] = '\0';
	return (result);
}

int	exist_variable(char **env, space_t *a, int ins)
{
	for (int i = 0; env[i] != NULL; i++)
		if (my_strcmpe(a->name, env[i]) == 1) {
			if (ins == 1) {
				env[i] = empty(env[i]);
				return (0);
			}
			if (ins == 2) {
				env[i] = change_value(env[i], a->next->name);
				return (0);
			}
		}
	return (1);
}

char	**add_variable(char **env, space_t *a, int ins)
{
	int	i = size_array(env);
	int	l;
	char	**pwd;
	char	*str;

	if (exist_variable(env, a, ins) == 0)
		return (env);
	pwd = malloca(i + 1);
	for (i = 0; env[i] != NULL; i++) {
		for (l = 0; env[i][l] != '\0'; l++)
			pwd[i][l] = env[i][l];
		pwd[i][l] = '\0';
		l = 0;
	}
	str = my_strstr(a->name, "=");
	if (ins == 2)
		str = my_strstr(str, a->next->name);
	pwd[i] = str;
	pwd[i + 1] = NULL;
	return (pwd);
}

char	**set_env(list_t *b, space_t *a, char **env)
{
	int	i;

	if (my_strcmp(a->name, "setenv") == 1) {
		i = arguments_after(a);
		if (i == 0) {
			a->name = "env";
			return (env);
		}
		else if (i > 2) {
			b->truee = 0;
			my_putstr_error("setenv: Too many arguments.\n");
			return (env);
		}
		else {
			env = add_variable(env, a->next, i);
			b->number = 0;
		}
	}
	return (env);
}
