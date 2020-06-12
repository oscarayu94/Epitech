/*
** EPITECH PROJECT, 2017
** summands
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>

int summands(char *str)
{
	long c;
	long result = 0;
	char sign;
	char mem;

	while (str[0] != '\0')
	{
		c = strtol(str, &str, 10);
		sign = str[0];
		if (sign == '-' || sign == '+')
			mem = sign;
		if (mem == '+')
			result = result + c;
		if (mem == '-')
			result = result + c;
	}
	printf("Result:%ld\n", result);
	return(result);

}


int main(int ac, char **av)
{
	summands(av[1]);
}
