/*
** EPITECH PROJECT, 2018
** 42sh
** File description:
** Aimane Belhassane
*/

int	echo_flags(space_t *separ, int *flags)
{
	if (separ->next != NULL) {
		if (my_strcmp(separ->next->name, "-n") == 1)
			flags[0] = 1;
		if (my_strcmp(separ->next->name, "-e") == 1)
			flags[1] = 1;
	}
	if (separ->next->next != NULL && (flags[0] == 1 || flags[1] == 1)) {
		if (my_strcmp(separ->next->next->name, "-n") == 1)
			flags[0] = 1;
		if (my_strcmp(separ->next->next->name, "-1") == 1)
			flags[1] = 1;
	}
	return (0);
}

int	my_echo(list_t *a, space_t *separ, int fd)
{
	int	flags[2];

	flags[0] = 0;
	flags[1] = 0;
	if (my_strcmp(separ->name, "echo") == 1) {
		echo_flags(separ, flags);
		if (flags[0] == 0 && flags [1] == 0){
			my_putstr_with_fd()
		}
		a->number = 0;
	}
}
