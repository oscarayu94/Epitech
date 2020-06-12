/*
** EPITECH PROJECT, 2018
** list
** File description:
** made by oscar ayuso
*/

#ifndef LIST_H_
#define LIST_H_

char	**maze_perfect(char *cor_x, char *cor_y);
char	**maze_imperfect(char *cor_x, char *cor_y);
int	my_strcmp(char *s1, char *s2);
void	my_putchar(char c);
int	my_putstr(char const *str);
void	my_print_tab(char **tab);
char	**tab(char **tab, int ver, int hor);

#endif 
