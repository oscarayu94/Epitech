/*
** EPITECH PROJECT, 2018
** minishel
** File description:
** by oriol
*/

#include	"../list.h"

char	*add_semicolon_space(char *line, int i, char simbol)
{
	int	num;
	char	*second;
	int	b;

	for (num = 0; line[num] != '\0'; num++);
	second = malloc(sizeof(char) * num + 2);
	for (num = 0, b = 0; line[num] != '\0'; num++, b++) {
		second[b] = line[num];
		if (b == i) {
			second[b] = ' ';
			second[b + 1] = simbol;
			second[b + 2] = ' ';
			b = b + 2;
		}
	}
	free(line);
	second[b] = '\0';
	return (second);
}

char	*separate_semicolons(char *line)
{
	for (int i = 1; line[i] != '\0'; i++)
		if ((line[i] == ';' || line[i] == '|' ||
		(line[i] == '<' && line[i + 1] != '<' &&
		line[i - 1] != '<') || (line[i] == '>' &&
					line[i + 1] != '>' &&
					line[i - 1] != '>')) &&
		(line[i - 1] != ' ' || line[i + 1] != ' ')) {
			line = add_semicolon_space(line, i, line[i]);
			i = 0;
		}
	return (line);
}

int	num_arg_string(char *str, char let)
{
	int	g;
	int	i = 0;

	for (g = 0; str[g] != '\0'; g++)
		if (str[g] == let && str[g + 1] == let)
			i++;
	return (i);
}

int num_arg(char *str, char let)
{
	int	g;
	int	i = 0;

	for (g = 0; str[g] != '\0'; g++)
		if (str[g] != let && str[g + 1] == let)
			i++;
	return (i);
}

coordinates	*feed_p(void)
{
	coordinates	*p;

	p = malloc(sizeof(p));
	p->x = -1;
	p->y = 0;
	return (p);
}
