/*
** EPITECH PROJECT, 2018
** several_letters
** File description:
** oscar ayuso
*/

char	*several_letters(char *str)
{
	int	i = 0;

	for (i = 1; str[i] != ' '; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] +  32;
        }
	return(str);
}	
