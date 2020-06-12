/*
** EPITECH PROJECT, 2018
** devian
** File description:
** oriol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

void	my_putchar_with_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	my_putstr_with_fd(char *str, int fd)
{
	int     i = 0;

	while (str[i] != '\0') {
		my_putchar_with_fd(str[i], fd);
		i = i + 1;
	}
	return (0);
}
