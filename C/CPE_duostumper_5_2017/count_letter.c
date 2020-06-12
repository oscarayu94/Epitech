/*
** EPITECH PROJECT, 2018
** count_letter
** File description:
** counts a letter
*/

int	count_letter(char *str, char c)
{
	int i;
	int conter = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == c)
			conter++;
	}
	return (conter);
}
	
