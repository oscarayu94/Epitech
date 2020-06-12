/*
** EPITECH PROJECT, 2018
** str_cpy
** File description:
** Made by Oscar Ayuso
*/

char	*my_strcpy(char *dest, char *src)
{
	int	x;

	x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}
	return (dest);
}	
