/*
** EPITECH PROJECT, 2018
** MyRPG
** File description:
** By Luis Angel Macias de la Cruz
*/

#include "../list.h"

gameover_t	set_gameover(sfVideoMode mode, gameover_t over)
{
        over.text = draw_over(mode);
	over.retry = draw_retry(mode);
        over.exit = draw_game_exit(mode);
	return (over);
}
