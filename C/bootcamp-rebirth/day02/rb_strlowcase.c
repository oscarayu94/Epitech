/*
** EPITECH PROJECT, 2018
** rb_strlowcase
** File description:
** strlowcase rebirth
*/

#include <unistd.h>
#include <stdlib.h>

void	rb_print_error(char *c)
{
	int	i;

	i = 0;
	while ( c[i] != '\0') {
		write (2, &c[i], 1);
		i++;
	}
}

void	rb_xerror(char *c)
{
	write (2, "Error:", 6);
	rb_print_error(c);
	write (2, "\n", 1);
	exit (84);
}

void	my_putchar(char c)
{
	write(1, &c, 1);
}

void	rb_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i] !='\0') {
		my_putchar(c[i]);
		i++;
	}
}

char	*rb_strlowcase(char *str)
{
	int	i;
	char	*c = "rb_strlowcase : String pointer is NULL";
	
	if (str == NULL)
		rb_xerror(c);
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = str[i] + 32;
		}
	}
	return (str);
}
