/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task09
*/
int     my_strlen(char const *str);

char    *my_strlowcase(char *str)
{
        int     i;
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


char	*my_strcapitalize(char *str)
{
	int	i;
	i = 0;
	my_strlowcase(str);
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
	i++;
	while (i < my_strlen(str))
	{
		if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] >= ' ' && str[i - 1] <= '@') || (str[i - 1] >= '[' && str[i - 1] <= 96))
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}
