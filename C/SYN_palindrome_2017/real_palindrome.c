/*
** EPITECH PROJECT, 2018
** real_palindrome
** File description:
** real one
*/

#include "list.h"

void	display_help()
{
	my_putstr("\nUSAGE\n\t"); 
	my_putstr("./palindrome -n number -p palindrome [-b base] [-imin i] [-imax i]");
	my_putstr("\n\nDESCRIPTION\n\t");
	my_putstr("-n n\tinteger to be transformed(>=0)\n\t-p pal\tpalindromic number");
	my_putstr(" to be obtained (incompatible with the -n option) (>=0)\n");
	my_putstr("\t\tif defined, all fitting values of n will be output\n");
	my_putstr("\t-b base\tbase in which the procedure will be executed (1<b<=10) [def: 10]");
	my_putstr("\n\t-imin i\tminimum number of iterations, included (>=0) [def:0]\n");
	my_putstr("\t-imax i\tmaximum number of iterations, included (>=0) [def: 100]\n\n");
}	

int	calc_int(char *str, flag_t *flags)
{
	char	*rvrsd_str;
	int	i = (strlen(str) - 1);
	int	j = 0;

	flags->repeat = flags-> repeat + 1;
	rvrsd_str = malloc(sizeof(char) * strlen(str));
	while(str[j] !='\0'){
		rvrsd_str[j] = str[i];
		i--;
		j++;
	} 
	int	c1 = atoi(str);
	if (c1 < 0) {
		my_putstr("invalid number\n");
		return (84);
	}	
	int	c2 = atoi(rvrsd_str);
	int	rslt = c1 + c2;
	if (check_palindrome(c1) == 0){
		printf("%d leads to %d in 0 iterations in base 10\n", c1, c1);
		return (c1);
	}	
	if (check_palindrome(rslt) == 0)
		printf("%s leads to %d in %d iterations in base 10\n", flags->first_number,
		       rslt, flags->repeat);
	if (check_palindrome(rslt) != 0){
		flags->last_number = strdup(int_to_str(rslt));
		calc_int(flags->last_number, flags);
	}
	return(rslt);
}

void	flag_it(char **tab, flag_t *flags)
{
	int	i = 0;

	flags->total_flags = 0;
	while (tab[i] != NULL)
	{
		if (my_strcmp(tab[i], "-n") == 0){
			flags->nfl = 1;
			flags->total_flags = flags -> total_flags + 1;
		}
		if (my_strcmp(tab[i], "-p") == 0){
			flags->pfl = 1;
			flags->total_flags = flags -> total_flags + 1;
		}	
		if (my_strcmp(tab[i], "-b") == 0){
			flags->bfl = 1;
			flags->total_flags = flags -> total_flags + 1;
		}	
		if (my_strcmp(tab[i], "-imin") == 0){
			flags->minfl = 1;
			flags->total_flags = flags -> total_flags + 1;
		}	
		if (my_strcmp(tab[i], "-imax") == 0){
			flags->maxfl = 1;
			flags->total_flags = flags -> total_flags + 1;
		}	
		i++;
	}	
}

void	parser(char **tab, flag_t *flags)
{
	int i = 0;
		
	while (tab[i] != NULL)
		i++;
	if (i == 2){
		if (my_strcmp(tab[1], "-h") == 0)
			display_help();
		else
			my_putstr("invalid argument\n");
	}
	if (i == 3){
		if ((my_strcmp(tab[1], "-n") == 0) && (check_number(tab[2]) == 0)){
			flags->repeat = 0;
			flags->first_number = strdup(tab[2]);
			calc_int(tab[2],flags);
		}	
	}
	if (i > 3 && i <= 9){
		flag_it(tab, flags);
		if (flags->nfl == 1 && flags->pfl ==1)
			my_putstr("invalid argument\n");
		else
			keep_parsing(tab,flags);
	}	
	if (i > 9)
		my_putstr("Too many arguments\n");
	
	
}

int	main(int ac, char **av)
{
	flag_t *flags;

	flags = malloc(sizeof(*flags));
	if (ac < 2)
		return (84);
	else
		parser(av, flags);
}	
