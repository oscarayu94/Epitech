/*
** EPITECH PROJECT, 2018
** main
** File description:
** main for ls program
*/

#include "list.h"

void	ls_simple()
{
	struct dirent *dir;
	DIR *direct;
	char *str = ".";
	
        direct = opendir(str);
	dir = readdir(direct);
	while (dir != NULL){
		my_putstr(dir->d_name);
		my_putstr("\n");
		dir = readdir(direct);
	}
}

void	ls_complex(char **av)
{
	my_putstr("Actually, it doesn't work. Sorry\n");
}	
int	main(int ac, char **av)
{
	if (ac == 1)
		ls_simple();
	if (ac > 1)
		ls_complex(av);
		
	
}	
