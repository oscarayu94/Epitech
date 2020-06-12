/*
** EPITECH PROJECT, 2018
** countwords
** File description:
** Detects number of occurrences of a word
*/

// Authorized functions: write, malloc, free, printf

#include <stdio.h>
#include <unistd.h>

int put_character(char c)
{
	write (1,&c,1);
	return (0);
}	

int read_string(char *str)
{
	int i;	
	i = 0;
	
	if (str[i] != '\0')
	{
		put_character(str[i]);
		i++;
	}	
}	

int cpy_str(char *dest, char *src)
	{
	int fc;

	fc = 0;
	while (src[fc] != '\0')
	{
		dest[fc] = src[fc];
		fc++;
	}
	return(*dest);
	printf("%c\n",dest);
}

int main (int ac, char **av)
{
	char a = '1';
	put_character(a);
	read_string("ehenjjnej");
	//cpy_str("JDAJKDWJSI", "DWAJDJWns");
	
}
