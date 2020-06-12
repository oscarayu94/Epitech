/*
** EPITECH PROJECT, 2018
** count_letters
** File description:
** made by Oscar Ayuso
*/

int	count_letters(char *str)
{
	int	i;
	int	letters = 0;

	for (i = 0; str[i] != ' '; i++) {
		letters++;
	}
	return (letters);
}	
		
