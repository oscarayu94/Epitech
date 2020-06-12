/*
** EPITECH PROJECT, 2018
** list
** File description:
** Ejemplo de como crear una list para citar funciones de otros archivos.
*/

#ifndef LIST_H_
#define LIST_H_

#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>

typedef struct poke_t
{
	char	name[10];
	int	attack;
	int	defense;
	int	speed;
	int	health;
}poke_t;

int write_pokemon_skills(char* str, char* str1, char* str2, int t);
char** separate(char* str);
#endif
