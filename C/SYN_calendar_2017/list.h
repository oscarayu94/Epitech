/*
** EPITECH PROJECT, 2018
** list
** File description:
** list
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_employee
{
  char			*id;
  char			*last_name;
  char			*first_name;
  char			*position;
  char			*zipcode;
  struct s_employee	*next;
}		t_employee;

typedef struct	s_meeting
{
  int			id;
  int			date;
  char			*place;
  int			zipcode;
  struct s_meeting	*next;
}		t_meeting;

#ifndef LIST_H_
#define LIST_H_

int	my_strcmp(char *s1, char *s2);
void	parse_opt(int argc, char **argv);
char	*get_file(int fd);
int	cnt_word(char *str, char end);
char	**my_strtowordtab(char *array, char end);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);
void	print_list(t_employee *first);
int	my_strarraylen(char **tab);
char	**get_employee(char **tab);
void	free_list(t_employee *first);
t_employee	*put_employee(char **tab);

#endif
