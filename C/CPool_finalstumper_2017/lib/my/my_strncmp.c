/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task05
*/

int     my_strlen(char const *str);
int	my_strncmp(char const *s1, char const *s2, int n)
{
	int	i;
	i = 0;
	while (i < n)
	{
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		else if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
