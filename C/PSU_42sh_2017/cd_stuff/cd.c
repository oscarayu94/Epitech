/*
** EPITECH PROJECT, 2018
** doritose
** File description:
** dexter
*/

#include	"../list.h"
#include	"../linked_list_stuff/linked_list.h"

void	put_error(char *line)
{
	if (line != NULL) {
		my_putstr_error(line);
		my_putstr_error(": No such file or directory");
		my_putstr_error("\n");
	}
}

void	comands(char **pwd, char *pwdmem, space_t *a, char **env)
{
	char	*result;

	if (my_strcmp(a->name, "-") == 1 && pwdmem != NULL)
		*pwd = pwdmem;
	else if (my_strcmp(a->name, ".."))
		previous_dir(pwd);
	else {
		result = my_strstr("/", a->name);
		result = my_strstr(*pwd, result);
		*pwd = result;
	}
}

void	go_home(int i, char **env, char **pwd)
{
	char	*home;

	if (i == 0) {
		home = get_home(env);
		if (home != NULL)
			*pwd = home;
	}
}

int	get_cd(char **env, list_t *a, char **pwd, char *pwd_mem)
{
	int	i = 1;
	space_t	*b = a->separ;

	if (my_strcmp(b->name, "cd") == 1) {
		a->number = 0;
		i = arguments_after(b);
		if (i != 1 && i != 0) {
			a->truee = 0;
			my_putstr_error("cd: Too many arguments.\n");
			return (0);
		}
		go_home(i, env, pwd);
		if (i == 1)
			comands(pwd, pwd_mem, b->next, env);
		if (chdir(*pwd) == -1) {
			a->truee = 0;
			put_error(b->next->name);
		}
	}
	return (0);
}
