/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task02
*/

int     my_strlen(char const *str);

char	*my_strncpy(char *dest, char const *src, int n)
{
	int	i;

	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	if (n > my_strlen(dest))
		dest[i] = '\0';
	return (dest);
}
