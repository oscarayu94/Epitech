/*
** EPITECH PROJECT, 2018
** tools
** File description:
** A compilation of useful mini-programs alias tools
*/

#include "list.h"

int	my_strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0'; i++){
		if (s1[i] != s2[i])
			return (1);
	}
	return (0);
}	

char	*my_strcpy(char *dest, char *src)
{
	int	x;

	x = 0;

	while (src[x] != '\0'){
		dest[x] = src[x];
		x++;
	}
	return (dest);
}

char *my_strdup(char *str)
{
	int	i;
	char	*str2;
	
	i = my_strlen(str);
	str2 = malloc(sizeof(char) * (i + 1));
	for (i = 0; str[i] != '\0'; i++)
		str2[i] = str[i];
	str2[i] = '\0';
	return (str2);
}	

char	*my_str_concatenate_equal(char *str, char *scr)
{
	char	*sjr;
	int	i = 0;
	int	j = 0;

	sjr = malloc(sizeof(char) * (strlen(str) + strlen(scr) + 1));
	while (str[i] != '\0'){
		sjr[i] = str[i];
		i++;
	}
	sjr[i] = '/';
	i++;
	while (scr[j] != '\0'){
		sjr[i] = scr[j];
		i++;
		j++;
	}
	printf("%s\n", sjr);
	return (sjr);
}

