/*
** EPITECH PROJECT, 2018
** by oriol
** File description:
** epetinp
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

char	**emptyy(char **env, int i)
{
	for (i = i; env[i] != NULL; i++) {
		env[i] = env[i + 1];
	}
	return (env);
}

char	*get_variable(char *env)
{
	int     i;
	char	*str;
	str = copy(env);
	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '=')
			str[i] = '\0';
	return (str);
}

char	**delete_unsetenva(space_t *a, char **env, int g)
{
	for (g = g; g > 0 && a != NULL; g--, a = a->next)
		for (int i = 0; env[i] != NULL; i++)
			if (my_strcmpe(a->name, get_variable(env[i])) == 1) {
				env = emptyy(env, i);
			}
	return (env);
}

char	**unsetenva(list_t *b, space_t *a, char **env)
{
	int	g;

	if (my_strcmp(a->name, "unsetenv") == 1) {
		g = arguments_after(a);
		b->number = 0;
		if (g == 0) {
			b->truee = 0;
			my_putstr_error("unsetenv: Too few arguments.\n");
		}
		else
			env = delete_unsetenva(a->next, env, g);
	}
	return (env);
}

char *add_n(char *str)
{
	int	i;
	char	*ptr;

	i = my_strlen(str);
	ptr = malloc(sizeof(char) * (i + 2));
	for (i = 0; str[i] != '\0'; i++)
		ptr[i] = str[i];
	ptr[i] = '\0';
	if (ptr[i - 1] != '\n') {
		ptr[i] = '\n';
		ptr[i + 1] = '\0';
	}
	return (ptr);
}
