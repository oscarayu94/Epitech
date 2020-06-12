##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## By Luis Angel Macias de la Cruz
##

SRC	=	Animations/character_move.c	\
		Animations/claw.c	\
		Animations/combat_animations.c	\
		Animations/combat_bars.c	\
		Animations/draco_anim.c	\
		Animations/load_anim.c	\
		Animations/mana.c	\
		Animations/plume_anim.c	\
		Animations/potion.c	\
		Animations/run.c	\
		Animations/shield.c	\
		Animations/slash.c	\
		Config/armoury.c	\
		Config/clock.c	\
		Config/collision.c	\
		Config/description.c	\
		Config/detect_rect.c	\
		Config/framebuffer.c	\
		Config/mouse.c	\
		Config/particle.c	\
		Config/rect_mouse.c	\
		Config/texture.c	\
		Config/window.c	\
		Destroy_assets/destroy_all.c	\
		Destroy_assets/escape.c	\
		Destroy_assets/intro.c	\
		Destroy_assets/load.c	\
		Destroy_assets/title.c	\
		Events/mouse_event.c	\
		Events/second_mouse_event.c	\
		Events/analyse_events.c	\
		Events/second_analyse_events.c	\
		Events/outline_events.c	\
		Events/escape.c	\
		Events/screen.c	\
		Events/load.c	\
		Events/intro.c	\
		Events/pause.c	\
		Events/game.c	\
		Events/combat_scenarios.c	\
		Events/combat.c	\
		Events/gameover.c	\
		Events/backpack.c	\
		Events/items.c	\
		Events/status.c	\
		Events/maintenance.c	\
		Events/scenarios.c	\
		Game_assets/title_screen.c	\
		Game_assets/game_screen.c	\
		Game_assets/load_screen.c	\
		Game_assets/second_load_screen.c	\
		Game_assets/pause_screen.c	\
		Game_assets/pause_slots.c	\
		Game_assets/escape_screen.c	\
		Game_assets/intro_screen.c	\
		Game_assets/combat_screen.c	\
		Game_assets/second_combat_screen.c	\
		Game_assets/third_combat_screen.c	\
		Game_assets/fourth_combat_screen.c	\
		Game_assets/fifth_combat_screen.c	\
		Game_assets/trans_screen.c	\
		Game_assets/gameover_screen.c	\
		Game_assets/equipment.c	\
		Game_assets/backpack.c	\
		Game_assets/status.c	\
		Game_assets/second_status.c	\
		Game_assets/third_status.c	\
		Game_assets/particles.c	\
		Key_input/keyboard.c	\
		Key_input/keyboard_combat.c	\
		Key_input/keyboard_load.c	\
		Key_input/keyboard_menu.c	\
		Key_input/keyboard_pause.c	\
		Key_input/load_key_input.c	\
		Key_input/pause_key.c	\
		Key_input/second_pause_key.c	\
		Key_input/title_key_input.c	\
		Render/screen.c	\
		Render/load.c	\
		Render/intro.c	\
		Render/escape.c	\
		Render/combat.c	\
		Render/game.c	\
		Render/pause.c	\
		Render/transition.c	\
		Render/gameover.c	\
		Render/backpack.c	\
		Render/items.c	\
		Render/status.c	\
		Render/snow.c	\
		Render/slash.c	\
		Set_assets/set_title_assets.c	\
		Set_assets/set_load_assets.c	\
		Set_assets/set_game_assets.c	\
		Set_assets/set_pause_assets.c	\
		Set_assets/set_escape_assets.c	\
		Set_assets/set_combat_assets.c	\
		Set_assets/set_intro_assets.c	\
		Set_assets/set_gameover_assets.c	\
		Set_assets/set_transition_assets.c	\
		Set_assets/set_all_assets.c	\
		Set_assets/set_render_assets.c	\
		my_puts.c	\
		main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

all	:	$(NAME)	

$(NAME)	:	$(OBJ)
	gcc -g -Werror -Wall -o $(NAME) $(SRC) -l c_graph_prog

clean	:
	rm -f $(OBJ)

fclean	:	 clean
	rm -f $(NAME)

re	:	fclean all

