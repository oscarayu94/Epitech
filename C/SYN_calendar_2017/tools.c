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
	int	i;

	i = 0;
	while (src[i]){
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_strdup(char *str)
{
	char	*cpy;
	
	if ((cpy = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
		return (NULL);
	my_strcpy(cpy, str);
	return (cpy);
}

int	my_strarraylen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char    **my_strtowordtab(char *array, char end)
{
  char  **tab;
  int   i;
  int   m;
  int   l;

  i = 0;
  m = 0;
  l = 0;
  if ((tab = malloc(sizeof(char *) * (cnt_word(array, end) + 1))) == NULL)
    return (NULL);
  while (l < cnt_word(array, end))
    {
      if ((tab[l] = malloc(sizeof(char) + strlen(array))) == NULL)
        return (NULL);
      while (array[i] == end)
        i++;
      while (array[i] != end && array[i])
        tab[l][m++] = array[i++];
      tab[l][m] = '\0';
      m = 0;
      l++;
      i++;
    }
  tab[l] = NULL;
  return (tab);
}
