/*
** EPITECH PROJECT, 2020
** PSU_2019_malloc
** File description:
** test_program
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(void) 
{
    char *string = NULL;
    string = malloc(5*sizeof(char));
    string[0]='H';
    string[1]='o';
    string[2]='l';
    string[3]='a';
    string[4]='\n';
    my_putstr(string);
    return(0);
}
