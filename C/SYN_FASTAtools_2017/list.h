/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	my_putchar(char c);
int	my_putstr(char const *str);
void	my_print_tab(char **tab);
int	my_strcmp(char *s1, char *s2);
char	**save_letters(char **tab);

#endif
