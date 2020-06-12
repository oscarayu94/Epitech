/*
** EPITECH PROJECT, 2018
** poke skills
** File description:
** poke
*/
#include "list.h"

int     my_strlen(char const *str)
{
	int     i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	write_skills(poke_t pokemon){
	printf("Pokemon %s has %d attack, %d defense, %d speed and %d health\n",
	       pokemon.name, pokemon.attack, pokemon.defense, pokemon.speed, pokemon.health);
	return (0);
}

int	battle(poke_t pokemon1, poke_t pokemon2)
{
	int	attack_value_pk1 = rand()%pokemon1.attack;

	printf("%d", attack_value_pk1);
	
	//printf("%s attacks for %d", pokemon1.name, attack_value);
	return (0);
}

poke_t	new_pokemon(char* str, char* champion1, char* champion2, int t){
	poke_t	pokemon;
	poke_t	pokemontest;
	int	i = 0;
	int	y = 0;
	int	semi_colon = 0;
	char	num[2];

	strcpy(pokemontest.name, "null");
	while(str[i] != '\0'){
	      	if (str[i] == ';'){
			semi_colon++;
		}
		if (semi_colon == 0){
			pokemon.name[y] = str[i];
			y++;
		}
		else if(semi_colon == 1 && str[i] != ';'){
			num[0] = str[i];
			num[1] = str[i + 1];
			pokemon.attack = atoi(num);
			i++;
		}
		else if(semi_colon == 2 && str[i] != ';'){
			num[0] = str[i];
			num[1] = str[i + 1];
			pokemon.defense = atoi(num);
			i++;
		}
		else if(semi_colon == 3 && str[i] != ';'){
			num[0] = str[i];
			num[1] = str[i + 1];
			pokemon.speed = atoi(num);
			i++;
		}
		else if(semi_colon == 4 && str[i] != ';'){
			num[0] = str[i];
			num[1] = str[i + 1];
			pokemon.health = atoi(num);
			i++;
		}
		i++;
       	}
	if (t == 1)
		write_skills(pokemon);
	else if (t == 2){
		if (strcmp(pokemon.name, champion1) == 0 || strcmp(pokemon.name, champion2))
		    return (pokemon);
		    }
	return (pokemontest);	
}

int	write_pokemon_skills(char* str, char* champion1, char* champion2, int t)
{
	int	found = 0;
	int	i = 0;
	int	x = 0;
	char*	string;
	poke_t	pokemon1;
	poke_t	pokemon2;
	
	string = malloc(sizeof(char) * my_strlen(str));
	while (i < strlen(str)){
		if (str[i] == '\n' && found == 0){
			found++;
			i++;
		}
		else if (str[i] != '\n' && found == 0){
			i++;
		}
		else if (found > 0){
			while(str[i] != '\n'){
				string[x] = str[i];
				i++;
				x++;
			}
			string[x] = '\0';
		        	pokemon1 = new_pokemon(string, champion1, champion2, t);
			
		        	pokemon2 = new_pokemon(string, champion1, champion2, t);
			i++;
		}
		x = 0;
	}
	battle(pokemon1, pokemon2);
	return (0);
}
