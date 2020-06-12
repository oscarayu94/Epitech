/*
** EPITECH PROJECT, 2018
** miniehsl
** File description:
** byu oriol
*/

#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>

#ifndef LIST_H_
#define LIST_H_

typedef struct	coordin_t
{
	int	x;
	int	y;
} coordinates;

char	*delete_enter(char *str);
int	open_history(char **env);
int	to_history(char **env, char *line);
int	num_arg_string(char *str, char let);
char	**get_path_array_string(char *str, char leter);
int	signals(void);
char	*get_input(void);
void	malloca_free_str(char **str);
void	malloca_free(int num_ar, char **pwd);
char	**malloca(int num_ar);
char	*separate_semicolons(char *line);
coordinates	*feed_p(void);
char	*copy(char *pwd);
char	*get_inputs(int stream);
int	my_putstr_with_fd(char *str, int fd);
void	my_putchar_with_fd(char c, int fd);
void	my_putchar_error(char c);
char	**getpath(char **env);
char	**get_path_array(char *str, char leter);
void	ls(char **str, char **env, int g);
void	mkdir(char **str, char **env, int g);
int	my_putstr_error(char *str);
int	num_arg(char *str, char let);
char	*root(char *result);
void	previous_dir(char **pwd);
int	size_array(char **env);
int	my_strcmpe(char *pwd, char *line);
void	printprompt(int i);
char	**no_space_array(char **ptr, coordinates *p, int *g, char *str);
int	my_strcmp(char *str, char *line);
char	*my_strstr(char *pwd, char *line);
char	**get_array(char *str);
char	*two_points(char *line);
char	*get_home(char **env);
char	*get_pwd(char **env);
int	my_strlen(char *pwd);
void	error(int ac);
char	*feed_buffer(int fd, char *buffer);
char	*save_after_n(char *buffer);
char	*main_loop(int fd, int i, int count, char *str, char *buffer);
char	*put_in_str(char *ptr, char *buffer, int i);
int	is_line(char *str, int n);
int	opening(char *av);
void	my_putchar(char c);
char	*my_strcat(char *dest, char *src);
int	my_putstr(char *str);

#endif
