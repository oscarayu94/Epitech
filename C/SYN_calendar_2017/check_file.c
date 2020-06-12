/*
** EPITECH PROJECT, 2018
** check_file
** File description:
** gets a file and reads it
*/

#include "list.h"

char    *get_file(int fd)
{
  char  *buffer;
  int   i;
  char  c;

  i = 0;
  if ((buffer = malloc(sizeof(char))) == NULL)
    return (NULL);
  while (read(fd, &c, 1) > 0){
      buffer[i] = c;
      i++;
      if ((buffer = realloc(buffer, ((i  + 2) * sizeof(char)))) == NULL)
        return (NULL);
  }
  buffer[i] = '\0';
  return (buffer);
}

int     cnt_word(char *str, char end)
{
  int   i;
  int   cnt;

  i = 0;
  cnt = 0;
  while (str[i])
    {
      if (str[i] == end)
        cnt++;
      i++;
    }
  if (str[0] != end)
    cnt++;
  return (cnt);
}

/*
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
*/
