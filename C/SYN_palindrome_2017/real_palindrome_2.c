/*
** EPITECH PROJECT, 2018
** real_palindrome_2
** File description:
** Contains more code of palindrome to keep on with norm
*/

#include "list.h"

int	check_palindrome(int nb)
{
	char	*str = int_to_str(nb);
	char	*new_str;
	int	i = (strlen(str) - 1);
	int	j = 0;

	new_str = malloc(sizeof(char) * strlen(str));
        while(str[j] !='\0'){
		new_str[j] = str[i];
                i--;
                j++;
	}
	if (my_strcmp(new_str, str) == 0)
		return (0);
	else
		return (1);
}

char	*int_to_str(int nb)
{
	char	*str;

	str = malloc(sizeof(char) * 10);
	sprintf(str, "%d", nb);
	return(str);
}	

void	keep_parsing(char **tab, flag_t *flags)
{
	int i = 0;

	while (tab[i] != NULL)
		i++;
	if ((i -1) > ((flags->total_flags) * 2))
		my_putstr("invalid argument\n");
	else if (i == 8)
		my_putstr("invalid argument\n");
	else
		if (flags->pfl == 1){
			int i = 0;
			while (my_strcmp(tab[i],"-p") != 0)
				i++;
			if (check_number(tab[i + 1]) == 0){
				flags->repeat = 0;
				p_procedure(tab[i + 1], flags);
			}	
			else
				my_putstr("invalid argument\n");
		}
}

void	p_procedure(char *str, flag_t *flags)
{
	int	end = atoi(str);
	int	i = 0;
	while (i < end){
		flags->first_number_p = end;
		calc_p(i, flags);
		i++;
	}
}	

int	calc_p(int nb, flag_t *flags)
{
	char	*str = int_to_str(nb);
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
		printf("%d leads to %d in %d iterations in base 10\n", flags->first_number_p,
		rslt, flags->repeat);
	if (check_palindrome(rslt) != 0){
		flags->last_number_p = (rslt);
		calc_p(flags->last_number_p, flags);
        }
	return(rslt);
}
