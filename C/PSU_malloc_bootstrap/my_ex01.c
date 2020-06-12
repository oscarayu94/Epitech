/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

#include <unistd.h>

void	my_putchar(char c)
{
	write(1, &c, 1);
}

int	my_putstr(char *str)
{
	int	i = 0;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		my_putchar(str[i]);
	return (1);
}

int	my_strlen(char *str)
{
  int	y;
  
  y = 0;
  while (str[y] != '\0')
    y++;
  return(y);
}