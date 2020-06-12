/*
** EPITECH PROJECT, 2018
** main
** File description:
** main for proj tester
*/

#include "list.h"

void	make_tree(char *str)
{
	struct dirent *dir;
	DIR *direct;

	my_putstr("make tree\n");
	my_putstr(str);
	my_putstr("\n");
	direct = opendir(str);
	if (direct == NULL)
		exit (84);
	dir = readdir(direct);
	while (dir != NULL){
		if ((dir->d_type == DT_DIR) && (my_strcmp(".",str)!= 0)){
			str = my_str_concatenate_equal(str, dir->d_name);
			make_tree(str);
		}
		if (my_strcmp(".",str) != 0){
			my_putstr(dir->d_name);
			my_putstr("\n");
		}	
		dir = readdir(direct);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		make_tree(av[1]);
}
