/*
** EPITECH PROJECT, 2018
** identify_character
** File description:
** identifies a character
*/

int flag(char **tab,int x, int y)
{
	if (tab[x][y] == 'X')
		return (1);
	else
		return (0);
}	
