/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

#ifndef LIST_H_
#define LIST_H_

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list.h>

typedef struct flag_s
{
	int	nfl;
	int	pfl;
	int	bfl;
	int	minfl;
	int	maxfl;
	int	total_flags;
	int	first_number_p;
	char	*first_number;
	int	last_number_p;
	char	*last_number;
	int	repeat;
}flag_t;	

void	my_putchar(char c);
int	my_putstr(char const *str);
int	my_strcmp(char *s1, char *s2);
int	check_number(char *str);
int	check_palindrome(int nb);
char	*int_to_str(int nb);
void	keep_parsing(char **tab, flag_t *flags);
void	p_procedure(char *str, flag_t *flags);
int	calc_p(int nb, flag_t *flags);

#endif
