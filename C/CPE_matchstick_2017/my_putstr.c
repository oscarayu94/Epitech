/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include "list.h"

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
