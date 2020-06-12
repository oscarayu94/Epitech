/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task10
*/

int     my_strlen(char const *str);

int	my_str_isalpha(char const *str)
{
	int	i;
	i = 0;
	if (my_strlen(str) == 0)
		return (1);
	while (i < my_strlen(str))
	{
		if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}
