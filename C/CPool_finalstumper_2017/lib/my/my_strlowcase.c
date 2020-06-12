/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task07
*/
int     my_strlen(char const *str);
char	*my_strlowcase(char *str)
{
	int	i;
	i = 0;
	while (i < my_strlen(str))
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}
