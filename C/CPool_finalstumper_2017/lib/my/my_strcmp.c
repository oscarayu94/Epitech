/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task05
*/

int     my_strlen(char const *str);
int	my_strcmp(char const *s1, char const *s2)
{
	int	i;
	i = 0;
	while (i < my_strlen(s1) && i < my_strlen(s2))
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
