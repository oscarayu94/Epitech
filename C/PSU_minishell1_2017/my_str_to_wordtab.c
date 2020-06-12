/*
** EPITECH PROJECT, 2018
** my_str_to_word_tab
** File description:
** String to words, now with proper name
*/

#include <stdlib.h>
#include <stdio.h>

int	my_count_char(char *str, int s)
{
	int cnt = 0;
	int i = 0;
	int tmp = 0;

	while (tmp != s)
	{
		while (str[i] == ' ')
		{
			i++;
		}
		tmp++;
	}
	while (str[i] != ' ' && str[i] != '\0')
	{
		cnt++;
		i++;
	}
	return (cnt);
}

int	my_count_word(char *str)
{
	int cnt;
	int i;

	i = 0;
	cnt = 1;

       	while (str[i]!='\0' && str[i]!=' ')
	{
		//Should check if there's a space after.
	       	if (str[i] == ' ')
			i++;
		cnt++;
		i++;
	}	
	return (cnt);
}

char **my_str_to_wordtab(char *str)
{
	int nb_space = my_count_word(str);
	char **tabx;
	tabx = malloc(sizeof(char *) * nb_space + 1);
	//Usar dos contadores
	/*Incrementar el primero en respuesta a un espacio, incrementar el segundo en respuesta a
	  una letra. Ir enviando al tablero*/
	int a = 0;
	int s = 0;
	int l;
	
	while (str[a] != '\0')	       
	{
		l = 0;
		tabx[s] = malloc(my_count_char(str, s) * sizeof(char));
		while (str[a] != '\0' && str[a] != ' ')
		{
			tabx[s][l] = str[a];
			l++;
			a++;
		}
		while (str[a] == ' ')
			a++;

		tabx[s][l] = '\0';
		s++;
	}
	tabx[s] = NULL;
	return (tabx);
}
