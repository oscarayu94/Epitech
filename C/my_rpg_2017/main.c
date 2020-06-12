/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "list.h"

int	error(int ac, char **av)
{
	int	count = 0;

	if (ac > 1 || av == NULL)
		return (0);
	for (int i = 0; av[i] != NULL; i++)
		if (my_strcmp(av[i], "DISPLAY") == 1)
			count++;
	if (count == 0)
		return (0);
	return (1);
}

all_t	*particle_title(all_t *all, render_t *rndr, sfVector2i click)
{
	if (all->a == 0) {
		render_snow(rndr, all->element, all->s_snow);
		all->a = screen_event(all->a, *rndr, all->title, click);
	}
	return(all);
}

all_t	*particle_combat(all_t *all, render_t *rndr, sfVector2i click)
{
	if (all->a == 5) {
		combat_event(*rndr, all, click, all->a);
		all->combat = combat_mode(all->combat, click);
		if (all->combat.turn == -2)
			render_slash(rndr, all->element2, all->s_slash);
		if (all->combat.turn == -8) {
			all->a = 2;
			all->combat.turn = 0;
		}
	}
	return (all);
}

void	render_display(render_t *rndr, sfVector2i click, char *str)
{
	all_t	*all;

	set_render(rndr);
	all = malloc(sizeof(*all));
	set_all(rndr->mode, all, rndr, str);
	*rndr = create_window(*rndr, "MyRPG");
	while (sfRenderWindow_isOpen((*rndr).window)) {
		click = mouse_detection(*rndr, click);
		particle_title(all, rndr, click);
		particle_combat(all, rndr, click);
		intro_scenario(all, *rndr, click, str);
		game_scenario(all, *rndr, click);
		combat_scenario(all, *rndr, click);
		menu_scenario(all, *rndr, click);
	}
	destroy_all(all, *rndr);
}

int	main(int ac, char **av, char **env)
{
	render_t	*rndr;
	sfVector2i	click;
	int	fd = open("Script/intro", O_RDONLY);
	char	str[3000];

	if (error(ac, env) == 0)
		return (84);
	read(fd, str, sizeof(str));
	rndr = malloc(sizeof(*rndr));
	render_display(rndr, click, str);
	return (0);
}
