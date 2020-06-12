/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "list.h"
#include "linked_list_stuff/linked_list.h"

int	open_history(char **env)
{
	char	*str = get_home(env);
	int	fd;

	str = my_strstr(str, "/");
	str = my_strstr(str, ".bash_history");
	fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
	return (fd);
}

void	take_history(char **env, int fd, int buff)
{
	char	result;
	char	buffer[1];

	for (int size = read(fd, buffer, 1); fd != -1 && size > 0;
	size = read(fd, buffer, 1)) {
		result = buffer[0];
		write(buff, &result, 1);
	}
	close(fd);
}

void	history_command(list_t *b, space_t *a, char **env)
{
	int	fd;

	if (my_strcmp(a->name, "history") == 1) {
		b->number = 0;
		if (arguments_after(a) != 0)
			my_putstr_error("history: Too many arguments\n");
		else {
			fd = open_history(env);
			take_history(env, fd, b->fd);
			close(fd);
		}
	}
}

int	to_history(char **env, char *line)
{
	int	fd;

	fd = open_history(env);
	if (line == NULL || fd == -1)
		return (0);
	my_putstr_with_fd(line, fd);
	close(fd);
	return (0);
}
