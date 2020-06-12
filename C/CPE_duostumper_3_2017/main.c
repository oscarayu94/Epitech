/*
** EPITECH PROJECT, 2018
** DuoStumper
** File description:
** main
*/

#include "list.h"

char*	copy(char* source)
{
	int	i = 0;
	int	y = 8;
	char*	string;

	string = malloc(sizeof(char) * (8 + strlen(source)));
	strcpy(string, "pokecfg/");
	while (i < strlen(source)){
		string[y] = source[i];
		i++;
		y++;
	}
	return (string);

}


int     main(int ac, char** av)
{
        DIR     *d;
	struct dirent *read;
	
	d = opendir("pokecfg");	
	if (d == NULL)
		return (84);
	while ((read = readdir(d)) != NULL){
		if (read->d_name[0] != '.')
			write_pokemon_skills(open_file(read->d_name), av[1], av[2], 1);
	}
	while ((read = readdir(d)) != NULL){
		if (read->d_name[0] != '.')
			write_pokemon_skills(open_file(read->d_name), av[1], av[2], 2);
	}
}

