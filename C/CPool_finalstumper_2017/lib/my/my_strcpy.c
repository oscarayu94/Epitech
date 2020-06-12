/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task01
*/

char	*my_strcpy(char *dest, char const *src)
{
	int	i;
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
