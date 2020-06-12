/*
** EPITECH PROJECT, 2017
** day07
** File description:
** task03
*/
int     my_strlen(char const *str);

char	*my_strncat(char *dest, char const *src, int nb)
{
	int	i;
	int	y;
	y = 0;
	i = 0;

	while (dest[i] != '\0')
		i++;

	while (y < nb && y < my_strlen(src))
	{
		dest[i] = src[y];
		y++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
