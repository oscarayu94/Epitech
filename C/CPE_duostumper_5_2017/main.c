/*
** EPITECH PROJECT, 2018
** Duostumper
** File description:
** text_count main
*/

int	main(int ac, char **av)
{
	int	r = 0;
	int	t = 0;
	int	second_string = 0;
	
	if (ac < 2){
		return (84);
	}
	if (strcmp(av[1], "-r") == 0 || strcmp(av[2], "-r") == 0){
		r = 1;
	}
	if (strcmp(av[1], "-t") == 0 || strcmp(av[2], "-t") == 0){
		t = 1;
	}
	if (((r == 1 && t == 1 && ac == 5)) || (((r == 1 && t == 0) ||
						(r == 0 && t == 1)) && ac == 4)
	    || (r == 0 && t == 0 && ac == 3)){
		second_string == 1;
	}
	else
	


}
