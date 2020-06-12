/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "list.h"

void	show_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    {
      if (tab[i + 1])
	printf("%s\n", tab[i]);
      else
	printf("%s", tab[i]);
      i++;
    }
}

void	parse_opt(int argc, char **argv)
{
  if (my_strcmp(argv[1], "-h") == 0 && argc == 2)
    {
      printf("%s\n", "USAGE");
      printf("%s\n", "\twrite instruction to the standard output\
until the END instruction");
      exit (0);
    }
  if (argc > 3)
    exit (84);
}

int	main(int argc, char **argv)
{
  char	*str;
  char	**tab;
  t_employee	*list;

  if (argc == 2)
	  parse_opt(argc, argv);
  str = get_file(0);
  tab = get_employee(my_strtowordtab(str, '\n'));
  list = put_employee(tab);
  if (list == NULL)
    printf("No file input\n");
  print_list(list);
  return (0);
}
