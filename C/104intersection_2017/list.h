/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef LIST_H_
#define LIST_H_

void    my_putchar(char c);
int     my_putstr(char *str);
int     my_get_nbr(char *str);
int     get_t_num(int alpha, int *v, int *p, int r);
int     Int_numbers (char *av);
void	nbrHandle(int ac, char **av);
int	    DivideNbr(int nb);
int	    PositiveNbr (char *av);
int     my_put_nbr(int nb);
int	    err(int ac);
void	sphere(char **av);
void	cilinder(char **av);
void	CilBody(int *v, int *p, int r);
void	line (int *v, int *p);
void	intersection(int *v, int *p, int r);
void	create_alpha (char **av);

#endif
