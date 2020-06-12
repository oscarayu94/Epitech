/*
** EPITECH PROJECT, 2018
** two_letters.c
** File description:
** oscar ayuso
*/

char	*two_letters(char *str)
{
	int	i = 0;
	
	while (str[i] != ' ') {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
                i++;
        }
	return(str);
}	
