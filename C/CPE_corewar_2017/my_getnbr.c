/*
** my_getnbr.c for  in /home/walbec_h/Piscine_C_J04
** 
** Made by hugo walbecq
** Login   <walbec_h@epitech.net>
** 
** Started on  Thu Oct  2 16:00:58 2014 hugo walbecq
** Last update Mon Jan 29 15:11:34 2018 Hugo
*/

#include "list.h"

int my_getnbr(char *str)
{
	double	x = 0;
	int	y = 0;
	int	z = 1;

	while (str[y]== '-' || str[y] == '+' || str[y] < '0' || str[y] > '9') {
		if (str[y] == '-')
			z *= -1;
		y++;
	}
	while (str[y] !='\0' && str[y] >= '0' && str[y] <= '9') {
		x = (x * 10);
		x = (str[y] - 48) + x;
		y++;
	}
	if (z == -1)
		x *= -1;
	if (x < -2147483648 || x > 2147483647)
		return (-84);
	x = (int)x;
	return (x);
}
