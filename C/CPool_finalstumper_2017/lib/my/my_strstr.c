/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task04
*/

int     my_strlen(char const *str);
char	*my_strstr(char const *str, char const *to_find)
{
	int	len_tf;
	int	i;
	int	y;
	int	localisation;
	localisation = -1;
	y = 0;
	i = 0;
	len_tf = my_strlen(to_find);		
	while (i < my_strlen(str) && y < len_tf)
	{
		if (str[i] == to_find[y] && localisation == -1)
		{
			y++;
			localisation = i;
		}
		else if (str[i] == to_find[y])
			y++;
		else if (str[i] != to_find[y] && y != 0)
		{
			y = 0;
			localisation = -1;
			i--;
		}
		i++;
	}
	if (len_tf == y)
		return (&str[localisation]);
	return (0);
}
