/*
** EPITECH PROJECT, 2018
** signal
** File description:
** by oriiol
*/

#include "../list.h"
#include "../linked_list_stuff/linked_list.h"

void    handle_signal(int signal, siginfo_t *siginfo, void *context)
{
	if (signal == 30 || signal == 10 || signal == 16);
	else if (signal == 31 || signal == 12 || signal == 17);
}

int	signals(void)
{
	struct sigaction	*new_action;
	int			signals[9] = {17, 16, 3, 10, 12, 30, 31, 84};

	new_action = malloc(sizeof(struct sigaction));
	if (new_action == NULL)
		exit(84);
	new_action->sa_sigaction = &handle_signal;
	new_action->sa_flags = SA_SIGINFO;
	for (int i = 0; signals[i] != 84; i++)
		if (sigaction(signals[i], new_action, NULL) < 0)
			return (0);
	return (1);
}
