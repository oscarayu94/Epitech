/*
** EPITECH PROJECT, 2018
** no_middle_letter
** File description:
** oscar ayuso
*/

char	*no_middle_letter(char *str)
{
	int	i = 0;
	
	while (str[i] != ' ')
		i++;
        i++;
        if (str[i] >= 'a' && str[i] <= 'z')
		str[i] = str[i] - 32;
        i++;
        while (str[i] != '\0') {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] +  32;
		i++;
        }
        i = 0;
	return(str);
}
