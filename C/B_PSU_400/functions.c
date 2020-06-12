/*
** EPITECH PROJECT, 2020
** B_PSU_400
** File description:
** functions
*/

#include <unistd.h>
#include <stdio.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}


int	my_putstr(char *str)
{
  int	y;
  
  y = 0;
  while (str[y] != '\0')
    {
      my_putchar(str[y]);
      y++;
    }
  return(0);
}

int	my_strlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0'){
		i++;
	}
	return (i);
}	

// void *malloc(size_t size)
// {
//   write(2, "Flying cats are the best!!!\n", 28);
//   return NULL;
// }