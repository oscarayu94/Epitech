/*
** EPITECH PROJECT, 2018
** instructions_handle
** File description:
** BY ORIOL FT PETER
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

int	first_instruct(char *str, char *mem)
{
	char	*car = "<>|&";
	int	i;
	int	g;

	for (i = 0; str[i] != '\0'; i++)
		for (g = 0; car[g] != '\0'; g++)
			if (str[i] == car[g] && mem[i] == '0') {
				mem[i] = '1';
				return (g);
			}
	return (-1);
}

char	**characters(void)
{
	char	**character = character = malloc(sizeof(char *) * 9);

	if (character == NULL)
		exit(84);
	character[0] = "<<";
	character[1] = ">>";
	character[2] = "||";
	character[3] = "&&";
	character[4] = "<";
	character[5] = ">";
	character[6] = "|";
	character[7] = ";";
	character[8] = NULL;
	return (character);
}

int	send_to_tree_semicolon(char **str, list_t *begin, list_t *a, int i)
{
	char	**character;

	if (i < 0 || i > 6)
		return (0);
	character = characters();
	if (str[0] != NULL && str[1] != NULL
	&& str[0][0] != '\0' && str[1][0] != '\0') {
		tree_semicolon(a->prev, a, str, character[i]);
		if ((a->prev != NULL) && (a->prev->name == NULL))
			begin->name = character[i];
		tree(&begin, begin);
		free(character);
		return (1);
	}
	free(character);
	return (0);
}

void	print_it(list_t *a)
{
	int	i;

	i = my_putstr(a->name);
	if (i == 1 && a->left != NULL && a->right != NULL) {
		print_it(a->left);
		print_it(a->right);
	}
}

void	print_array(char **str)
{
	for (int i = 0; str[i] != NULL; i++) {
		my_putstr("value:");
		my_putstr(str[i]);
		my_putstr("\n");
	}
}
