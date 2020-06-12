/*
** EPITECH PROJECT, 2018
** count_spaces
** File description:
** made by oscar ayuso
*/

int	count_spaces(char *str)
{
	int	i;
	int	space = 0;
	
	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')
			space++;
	}
	return (space);
}	
