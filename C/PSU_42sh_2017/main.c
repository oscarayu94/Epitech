/*
** EPITECH PROJECT, 2018
** by deoel
** File description:
** dkerko
*/

#include "list.h"
#include "linked_list_stuff/linked_list.h"

char	*delete_first_spaces(char *line)
{
	int	i;

	for (i = 0; line[i] == ' '; i++);
	line = &line[i];
	return (line);
}

int	red_not_pipe(char *str)
{
	char	pipe = '|';
	char	red = '>';
	char	semi = ';';
	int	flag = 0;

	for (int i = 0; str[i] != '\0'; i++)
		if (red == str[i])
			for (i = i; str[i] != '\0'; i++) {
				if (semi == str[i])
					flag = 1;
				if (pipe == str[i] && flag == 0) {
					printf("Ambiguous output redirect\n");
					return (0);
				}
			}
	return (1);
}

int	parce_line(char *line)
{
	int	i;

	if (line == NULL || line[0] == '\n' || line[0] == ';')
		return (0);
	for (i = 0; line[i] != '\0'; i++)
		if (line[i] == '\t')
			line[i] = ' ';
	for (i = i -1; line[i] == ' ' || line[i] == '\n' ||
		line[i] == '\t'; i--)
		line[i] = '\0';
	line = delete_first_spaces(line);
	if (red_not_pipe(line) == 0)
		return (0);
	return (1);
}

int	infinite_loop(char **env, char *pwd, char *real_pwd)
{
	list_t	*a = NULL;
	int     i = 0;
	char	*line;

	a = malloc(sizeof(list_t));
	if (a == NULL)
		exit(84);
	signals();
	while (i == 0 || i == 1) {
		if (i == 1) {
			line = get_input();
			to_history(env, line);
			if (parce_line(line) == 1) {
				a = tree_start(a, line);
				env = execute_instruction(env, &pwd,
							real_pwd, a);
			}
			my_putstr("42sh> ");
		}
		if (i == 0)
			my_putstr("42sh> ");
		i = 1;
	}
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	*pwd;
	char	*home;
	char	*real_pwd;

	signals();
	if (ac != 1)
		return (84);
	pwd = get_pwd(env);
	real_pwd = get_pwd(env);
	if (pwd == NULL || real_pwd == NULL)
		return (84);
	if ((home = get_home(env)) == NULL)
		exit(84);
	infinite_loop(env, pwd, real_pwd);
	return (0);
}
