/*
** EPITECH PROJECT, 2018
** rb_strisinformat
** File description:
** strisinformat rebirth
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	rb_print_error(char *c)
{
	int     i = 0;

	while ( c[i] != '\0') {
		write (2, &c[i], 1);
		i++;
	}
}

int	my_strlen(char *c)
{
	int	i = 0;

	while (c[i] != '\0')
		i++;
	return (i);
}

void	rb_xerror(char *c)
{
	write (2, "Error:", 6);
	rb_print_error(c);
	write (2, "\n", 1);
	exit(84);
}

int	rb_strisinformat(char *str , char *format)
{
	int	i;
	int	j = 0;
	int	flagp = 0;

	if (str == NULL || format == NULL)
		rb_xerror("rb_strisinformat: String pointer is NULL");
	for (i = 0 ; str[i] != '\0'; i++) {
		j = 0;
		flagp = 0;
		while (format[j] != '\0') {
			if (format[j] != str[i])
				flagp++;
			j++;
		}
		if (flagp == strlen(format))
			return (0);
	}
	return (1);
}
