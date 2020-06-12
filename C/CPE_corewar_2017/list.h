/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef LIST_H_
#define LIST_H_

#define BUFF 12
# define COREWAR_EXEC_MAGIC      0xea83f3 
typedef struct coordin_t
{
        int     x;
        int     y;
}coordinates;

typedef struct date_t
{
	char	corewar[40];
	char	k;
	int     num;
}date;

typedef struct asm_t
{
	coordinates num;
	int	x;
	int	y;
	int	i;
	char	**ptr;
	int	fd;
	char	**code;
	char	**regi;
	char	*a;
}asm_t;
//live
int     live_number(asm_t *a, int i);
//comands
int     put_comands(int fd, char **ptr);
int my_getnbr(char *str);
int     strcom(char *a, char *b);

char    *get_file(char  *av);
int     yolotron(char *av);
int	my_strlen(char *str);
char    *my_get_hexa_nbr(int nb);
int num_arg(char *str, char let);
char **malloco(int num_ar);

coordinates	*feed_p(void);
int	num_arg(char *str, char	let);
char	**malloco(int num_ar);
int	my_strcmp(char *pwd, char *line);
int	my_put_nbr(int nb);
char	**get_path_array(char *str, char leter);
void	my_putchar_error(char c);
int	my_get_nbr(char *str);
int	my_putstr_error(char *str);
char	**malloca(int num_ar, int cha);
int	**int_malloca(int num_ar, int cha);
int	my_strcmpe(char *pwd, char *line);
char	*my_strstr(char *pwd,char *line);
int	my_strlen(char *pwd);
void	error(int ac);
void	my_putchar(char	c);
int	my_putstr(char *str);

#endif
