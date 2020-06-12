/*
** EPITECH PROJECT, 2018
** hex_dec
** File description:
** By Luis Angel Macias de la Cruz
*/

#include <stdio.h>
#include <stdlib.h>

/*int	hex_dec(char *str)
{
	int	len;
	int	base = 1;
	int	dec_val = 0;
	int	i;

	len = my_strlen(str);
	for (i = len - 1; i >= 0; i--) {
		if (str[i] >= '0' && str[i] <= '9') {
			dec_val += (str[i] - '0') * base;
			base = base * 16;
		}
		else if (str[i] >= 'A' && str[i] <= 'F') {
			dec_val += (str[i] - 55) * base;
			base = base * 16;
		}
	}
	return (dec_val);
}
*/
char	*dec_hex(int a)
{
	char	*hex;
	int	i = 0;
	int	temp;

	hex = malloc(sizeof(char*) * a);
	while (a != 0) {
		temp = 0;
		temp = a % 16;
		if (temp < 10) {
			hex[i] = temp + 48;
			i++;
		}
		else {
			hex[i] = temp + 55;
			i++;
		}
		a = a / 16;
	}
	return (hex);
}

int	main(int ac, char **av)
{
	char	*str;

	str = dec_hex(atoi(av[1]));
	printf("%s\n", str);
}
