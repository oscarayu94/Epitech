/*
** EPITECH PROJECT, 2017
** day07
** File description:
** task02
*/

char	*my_strcat(char *dest, char const *src)
{
	int	i;
	int	y;
	y = 0;
	i = 0;

	while (dest[i] != '\0')
		i++;

	while (src[y] != '\0')
	{
		dest[i] = src[y];
		y++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
