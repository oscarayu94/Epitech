/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Network.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "stats.h"

#ifndef LIST_H_
#define LIST_H_

typedef struct text_s {
	sfText *text;
	sfFont *font;
}text_t;

typedef struct scroll_s {
	int i;
	int speed;
	int enter;
}scroll_t;

typedef struct button_s {
	sfRectangleShape *rect;
	sfTexture *texture;
}button_t;

typedef struct framebuffer_s {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
}framebuffer_t;

typedef struct render_s {
	sfRenderWindow *window;
	sfEvent event;
	sfWindow *screen;
	sfVideoMode mode;
	sfTexture *texture;
	sfTexture *texture2;
	sfSprite *sprite;
	sfSprite *sprite2;
	int alpha;
	int num;
	int count;
	sfVector2i center;
	sfVector2i center2;
	sfVector2i faster;
	sfVector2i more_faster;
}render_t;

typedef struct count_s {
	sfClock *clock;
	sfTime time;
	float sec;
}count_t;

typedef struct title_s {
	sfRectangleShape *load;
	sfRectangleShape *start;
	sfRectangleShape *exit;
	sfRectangleShape *title;
	sfRectangleShape *invi;
}title_t;

typedef struct load_s {
	sfRectangleShape *empty;
	sfRectangleShape *table;
	sfRectangleShape *save1;
	sfRectangleShape *save2;
	sfRectangleShape *save3;
	sfRectangleShape *lreturn;
	sfRectangleShape *invi;
	text_t text;
	sfVector2f offmov;
	sfVector2f set;
	count_t clock;
}load_t;

typedef struct intro_s {
	text_t intro;
	count_t clock;
	char *ptr;
	sfSprite *bg;
	sfRectangleShape *plume;
	scroll_t mov;
	text_t skip;
	sfVector2f plume_pos;
	sfVector2f text_pos;
	int end;
}intro_t;

typedef struct game_s {
	sfSprite *bg;
	sfRectangleShape *mc;
	sfVector2f mov;
	sfView *view;
	sfFloatRect vset;
	sfImage *collide;
	count_t clock;
	sfIntRect frame;
} game_t;

typedef struct transition_s {
	sfRectangleShape *tran;
	sfVector2f mov;
	sfVector2f pos;
	text_t battle;
	count_t clock;
	sfVector2f battle_pos;
	int counter;
	int scroll;
}transition_t;

typedef struct pause_s {
	sfRectangleShape *pause;
	sfRectangleShape *invi;
	sfRectangleShape *skills;
	sfRectangleShape *inv;
	sfRectangleShape *party;
	sfRectangleShape *save;
	sfRectangleShape *loadrect;
	sfRectangleShape *preturn;
	sfRectangleShape *header;
	sfRectangleShape *slots;
	sfRectangleShape *hud;
	sfRectangleShape *slot1;
	sfRectangleShape *slot2;
	sfRectangleShape *slot3;
	sfRectangleShape *sloti;
	sfRectangleShape *helm;
	sfRectangleShape *chest;
	sfRectangleShape *legs;
	sfRectangleShape *arms;
	sfRectangleShape *weapon;
	sfRectangleShape *eqin;
	sfRectangleShape *bpa;
	sfRectangleShape *bpai;
	sfRectangleShape *stat;
	sfRectangleShape *istat;
	sfRectangleShape *heal;
	sfRectangleShape *hnum;
	sfRectangleShape *hnumf;
	sfRectangleShape *empty;
	sfRectangleShape *empty2;
	sfRectangleShape *empty3;
	sfRectangleShape *empty4;
	sfRectangleShape *empty5;
	sfRectangleShape *empty6;
	sfRectangleShape *maintenance;
	sfView *pview;
	sfFloatRect pvset;
	text_t text;
	text_t text2;
}pause_t;

typedef struct escape_s {
	sfRectangleShape *back;
	sfRectangleShape *exit;
	sfRectangleShape *empty;
	sfRectangleShape *invi;
	text_t title;
	sfView *view;
	sfFloatRect pview;
}escape_t;

typedef struct animation_s {
	sfIntRect frame;
	sfIntRect frame2;
	sfIntRect frame3;
	sfIntRect frame4;
	sfIntRect frame5;
	sfIntRect frame6;
}animation_t;

typedef struct combat_bar_s {
	sfVector2f hp_bar;
	sfVector2f enemy_bar;
	sfVector2f mp_bar;
}combat_bar_t;

typedef struct combat_s {
	sfRectangleShape *enemy;
	sfRectangleShape *mc;
	sfRectangleShape *atk;
	sfRectangleShape *skl;
	sfRectangleShape *pineapple;
	sfRectangleShape *mint;
	sfRectangleShape *item;
	sfRectangleShape *run;
	sfRectangleShape *hp;
	sfRectangleShape *mp;
	sfRectangleShape *invc;
	combat_bar_t bar;
	stats_t rowena;
	stats_t draco;
	text_t name;
	text_t turn_name;
	sfView *view;
	sfFloatRect pview;
	int enemy_hp;
	int item1;
	int item2;
	int turn;
	int shield;
	count_t clock;
	count_t anim;
	sfRectangleShape *atk_anim;
	sfRectangleShape *atk2_anim;
	sfRectangleShape *skl_anim;
	sfRectangleShape *skl2_anim;
	sfRectangleShape *hp_bar;
	sfRectangleShape *potion;
	sfRectangleShape *mana;
	sfRectangleShape *skl1;
	sfRectangleShape *dust;
	sfRectangleShape *skl2;
	sfRectangleShape *itemset;
	animation_t animate;
	sfIntRect draco_frame;
}combat_t;

typedef struct gameover_s {
	text_t text;
	sfRectangleShape *retry;
	sfRectangleShape *exit;
}gameover_t;

typedef struct all_s {
	int a;
	title_t title;
	load_t load;
	game_t game;
	pause_t pause;
	escape_t esc;
	transition_t trans;
	intro_t intro;
	combat_t combat;
	gameover_t over;
	framebuffer_t *element;
	framebuffer_t *element2;
	int *s_slash;
	int *s_snow;
}all_t;

render_t	*set_render(render_t *rndr);
render_t	create_window(render_t rndr, char *str);
sfVector2i	mouse_detection(render_t rndr, sfVector2i click);
int	mouse_rect(sfRectangleShape *rect, sfVector2i click);
sfRectangleShape	*rect_texture(sfRectangleShape *rect, char *str);
char	*pineapple_description(void);
char	*mint_tea_description(void);
char	*plume_description(void);
char	*crimson_helmet(void);
char	*crimson_chest(void);
char	*crimson_arm(void);
char	*crimson_leg(void);
char	*dane_axe(void);
all_t	*intro_scenario(all_t *all, render_t rndr, sfVector2i click, char *str);
all_t	*game_scenario(all_t *all, render_t rndr, sfVector2i click);
all_t	*combat_scenario(all_t *all, render_t rndr, sfVector2i click);
all_t	*menu_scenario(all_t *all, render_t rndr, sfVector2i click);
sfRectangleShape	*draw_start(sfVideoMode mode);
sfRectangleShape	*draw_load(sfVideoMode mode);
sfRectangleShape	*draw_exit(sfVideoMode mode);
sfRectangleShape	*invi(sfVideoMode mode);
sfRectangleShape	*draw_gametitle(sfVideoMode mode);
sfRectangleShape	*draw_mc(sfVideoMode mode);
sfSprite	*draw_bg(sfVideoMode mode);
sfRectangleShape	*draw_table(sfVideoMode mode);
sfRectangleShape	*draw_emptiness(sfVideoMode mode);
sfRectangleShape	*draw_save_one(sfVideoMode mode);
sfRectangleShape	*draw_save_two(sfVideoMode mode);
sfRectangleShape	*draw_save_three(sfVideoMode mode);
sfRectangleShape	*draw_lreturn(sfVideoMode mode);
sfRectangleShape	*draw_pause(sfVideoMode mode);
void	outline_rect(sfRectangleShape *button, sfVector2i click, sfColor color);
int	move_key(sfRectangleShape *invi, render_t rndr, title_t title, int a);
int	move_pause_key(sfRectangleShape *invi, render_t rndr,
		       pause_t pause, int a);
int	move_key_slots(sfRectangleShape *invi, render_t rndr,
		       pause_t pause, int a);
int	detect_rect(sfRectangleShape *rect, sfRectangleShape *rect2);
text_t	draw_title(sfVideoMode mode);
text_t	draw_loadtitle(sfVideoMode mode);
void	close_window(render_t rndr);
int	analyse_menu(render_t rndr, title_t title, int a);
int	analyse_load(render_t rndr, load_t load, int a);
int	analyse_pause(render_t rndr, pause_t pause, int a);
int	analyse_slots(render_t rndr, pause_t pause, int a);
int	analyse_escape(render_t rndr, escape_t esc, int a);
all_t	*analyse_combat(render_t rndr, all_t *all, int a);
int	analyse_ingame(render_t rndr, int a);
int	analyse_gameover(render_t rndr, int a);
int	analyse_intro(render_t rndr, int a, scroll_t scroll);
void	exit_button(sfRectangleShape *exit, sfVector2i click, render_t rndr);
int	start_button(sfRectangleShape *start, sfVector2i click,
		     render_t rndr, int a);
int	load_button(sfRectangleShape *load, sfVector2i click,
		    render_t rndr, int a);
int	return_button(sfRectangleShape *load, sfVector2i click,
		      render_t rndr, int a);
int	game_button(sfRectangleShape *button, sfVector2i click,
		    render_t rndr, int a);
int	title_input(sfRectangleShape *invi, render_t rndr,
		    title_t title, int a);
int	load_input(sfRectangleShape *invi, render_t rndr,
		   load_t load, int a);
int	load_anim(count_t clock_anim, load_t load, int a);
int	load_anim_event(int a, render_t rndr, load_t load, count_t clock);
title_t	set_title(sfVideoMode mode, title_t title);
load_t	set_load(sfVideoMode mode, load_t load);
transition_t	set_transition(transition_t trans);
game_t	set_game(sfVideoMode mode, game_t game);
pause_t	set_pause(sfVideoMode mode, pause_t pause);
gameover_t	set_gameover(sfVideoMode mode, gameover_t over);
game_t	mov_char(game_t game, int nb);
all_t	*combat_event(render_t rndr, all_t *all, sfVector2i click, int a);
sfRectangleShape	*invi_load(sfVideoMode mode);
int	move_key_load(sfRectangleShape *invi, render_t rndr,
		      load_t load, int a);
int	pause_key(int a);
int	escape_game(int a);
int	return_game(int a);
int	escape_return(int a);
void	render_screen(render_t rndr, title_t title);
void	render_load(render_t rndr, load_t load);
void	render_gameover(render_t rndr, gameover_t over);
void	render_escape(render_t rndr, escape_t esc);
game_t	render_game(render_t rndr, game_t game);
void	render_pause(render_t rndr, pause_t pause);
void	render_backpack(render_t rndr, pause_t pause);
void	render_items(render_t rndr, pause_t pause);
void	render_status(render_t rndr, pause_t pause);
void	render_transition(render_t rndr, transition_t trans);
sfRectangleShape	*draw_invi(sfVideoMode mode);
sfRectangleShape	*draw_skills(sfVideoMode mode);
sfRectangleShape	*draw_save(sfVideoMode mode);
sfRectangleShape	*draw_loadrect(sfVideoMode mode);
sfRectangleShape	*draw_party(sfVideoMode mode);
sfRectangleShape	*draw_preturn(sfVideoMode mode);
sfRectangleShape	*draw_header(sfVideoMode mode);
sfRectangleShape	*draw_esc_emptiness(sfVideoMode mode);
sfRectangleShape	*draw_esc_return(sfVideoMode mode);
sfRectangleShape	*draw_esc_exit(sfVideoMode mode);
text_t	draw_escape_title(sfVideoMode mode);
int	title_button(sfRectangleShape *start, sfVector2i click,
		     render_t rndr, int a);
escape_t	set_escape(sfVideoMode mode, escape_t esc);
intro_t	set_intro(intro_t intro, sfVideoMode mode, char *str);
sfRectangleShape	*draw_name_square(sfVideoMode mode);
sfRectangleShape	*draw_name_emptiness(sfVideoMode mode);
sfRectangleShape	*draw_type_name(sfVideoMode mode);
sfRectangleShape	*draw_select(sfVideoMode mode);
sfRectangleShape	*draw_nreturn(sfVideoMode mode);
text_t	draw_naming_text(sfVideoMode mode);
int	screen_event(int a, render_t rndr, title_t title, sfVector2i click);
int	load_event(int a, render_t rndr, load_t load, sfVector2i click);
int	pause_event(int a, render_t rndr, pause_t pause, sfVector2i click);
int	backpack_event(int a, render_t rndr, pause_t pause, sfVector2i click);
int	items_event(int a, render_t rndr, pause_t pause, sfVector2i click);
int	status_event(int a, render_t rndr, pause_t pause, sfVector2i click);
int	maintenance_event(int a, render_t rndr,
			  pause_t pause, sfVector2i click);
int	gameover_event(int a, render_t rndr, gameover_t over, sfVector2i click);
void	outline_screen(title_t title, sfVector2i click);
void	outline_load(load_t load, sfVector2i click);
void	outline_pause(pause_t pause, sfVector2i click);
void	outline_combat(combat_t combat, sfVector2i click);
void	render_intro(render_t rndr, intro_t intro);
text_t	draw_intro(void);
text_t	draw_skip(sfVideoMode mode);
sfSprite	*draw_background(void);
sfRectangleShape	*draw_enemy(sfVideoMode mode);
sfRectangleShape	*draw_plume(void);
sfRectangleShape	*draw_transition(void);
text_t	draw_battle_begins(void);
scroll_t	text_move(intro_t intro, sfVideoMode mode, char *str);
count_t	clock_config(count_t clock);
int	intro_event(int a, render_t rndr, intro_t intro, char *str);
sfRectangleShape	*draw_combat(sfVideoMode mode);
scroll_t	text_speed(intro_t intro, sfVideoMode mode,
			   char *str, float nb);
void	plume_anim(intro_t intro);
intro_t	intro_interaction(intro_t intro);
intro_t	text_anim(intro_t intro, render_t rndr, char *str);
intro_t	intro_section(intro_t intro, render_t rndr, char *str);
int	escape_event(int a, render_t rndr, escape_t esc, sfVector2i click);
sfRectangleShape	*invi_pause(sfVideoMode mode);
combat_t	set_combat(sfVideoMode mode, combat_t combat);
int	move_key_pause(sfRectangleShape *invi, render_t rndr,
		       escape_t esc, int a);
void	outline_escape(escape_t esc, sfVector2i click);
int	pause_input(sfRectangleShape *invi, render_t rndr, escape_t esc, int a);
transition_t	transition_pos(transition_t trans, game_t game);
void	destroy_title(title_t title);
void	destroy_load(load_t load);
void	destroy_intro(intro_t intro);
void	destroy_escape(escape_t esc);
int	random_encounter(game_t game, transition_t trans);
sfRectangleShape	*draw_attack(sfVideoMode mode);
sfRectangleShape	*draw_atk_anim(void);
sfRectangleShape	*draw_atk2_anim(void);
sfRectangleShape	*draw_skl_anim(void);
sfRectangleShape	*draw_skl2_anim(void);
sfRectangleShape	*draw_dust(void);
sfRectangleShape	*draw_skill(sfVideoMode mode);
sfRectangleShape	*draw_skill1(sfVideoMode mode);
sfRectangleShape	*draw_skill2(sfVideoMode mode);
sfRectangleShape	*draw_items(sfVideoMode mode);
sfRectangleShape	*draw_items2(sfVideoMode mode);
sfRectangleShape	*draw_pineapple(sfVideoMode mode);
sfRectangleShape	*draw_potion(sfVideoMode mode);
sfRectangleShape	*draw_mint(sfVideoMode mode);
sfRectangleShape	*draw_run(sfVideoMode mode);
sfRectangleShape	*draw_hp(sfVideoMode mode);
sfRectangleShape	*draw_fiend_hp(sfVideoMode mode);
sfRectangleShape	*draw_mp(sfVideoMode mode);
combat_t	slash_anim(combat_t combat);
combat_t	shield_anim(combat_t combat);
combat_t	azure_slash_anim(combat_t combat);
combat_t	claw_anim(combat_t combat);
combat_t	potion_anim(combat_t combat);
combat_t	mana_anim(combat_t combat);
combat_t	run_anim(combat_t combat);
combat_t	combat_animations(combat_t combat);
combat_t	select_item(combat_t combat, sfVector2i click);
combat_t	select_skill(combat_t combat, sfVector2i click);
combat_t	player_turn(combat_t combat, sfVector2i click);
combat_t	enemy_turn(combat_t combat);
combat_t	combat_scenarios(combat_t combat, sfVector2i click);
int	return_slots(int a);
int	return_equip(int a);
text_t	draw_name(sfVideoMode mode);
text_t	draw_over(sfVideoMode mode);
text_t	draw_turn(sfVideoMode mode);
void	render_combat(render_t rndr, combat_t combat);
sfRectangleShape	*draw_retry(sfVideoMode mode);
sfRectangleShape	*draw_game_exit(sfVideoMode mode);
sfRectangleShape	*draw_hud(sfVideoMode mode);
sfRectangleShape	*draw_inv(sfVideoMode);
sfRectangleShape	*draw_slot1(sfVideoMode mode);
sfRectangleShape	*draw_slot2(sfVideoMode mode);
sfRectangleShape	*draw_slot3(sfVideoMode mode);
sfRectangleShape	*draw_invi_slot(sfVideoMode mode);
combat_t	combat_mode(combat_t combat, sfVector2i click);
void	destroy_all(all_t *all, render_t rndr);
int	slots_input(sfRectangleShape *invi, render_t rndr,
		    pause_t pause, int a);
combat_t	draco_anim(combat_t combat);
combat_t	combat_bars(combat_t combat);
int	get_white_pixels(sfImage *collide, sfVector2f mov,
			 sfRectangleShape *mc);
all_t	*set_all(sfVideoMode mode, all_t *all, render_t *rndr, char *str);
all_t	*game_event(all_t *all, render_t rndr, sfVector2i click);
all_t	*transition_event(all_t *all, render_t rndr, sfVector2i click);
int	return_menu(int a);
sfRectangleShape	*draw_helm(sfVideoMode mode);
sfRectangleShape	*draw_chest(sfVideoMode mode);
sfRectangleShape	*draw_legs(sfVideoMode mode);
sfRectangleShape	*draw_arms(sfVideoMode mode);
sfRectangleShape	*draw_weapon(sfVideoMode mode);
sfRectangleShape	*draw_eqin(sfVideoMode mode);
int	analyse_equip(render_t rndr, pause_t pause, int a);
sfRectangleShape	*draw_backpack(sfVideoMode mode);
sfRectangleShape	*draw_backpacki(sfVideoMode mode);
int	move_key_back(sfRectangleShape *bpai, render_t rndr,
		      pause_t pause, int a);
int	analyse_status(render_t rndr, pause_t pause, int a);
sfRectangleShape	*draw_status(sfVideoMode mode);
sfRectangleShape	*draw_istat(sfVideoMode mode);
int	analyse_stree(render_t rndr, pause_t pause, int a);
int	move_key_status(sfRectangleShape *invi, render_t rndr,
			pause_t pause, int a);
sfRectangleShape	*draw_healty(sfVideoMode mode);
sfRectangleShape	*draw_hnumber(sfVideoMode mode);
sfRectangleShape	*draw_hnumberf(sfVideoMode mode);
sfRectangleShape	*draw_empty(sfVideoMode mode);
sfRectangleShape	*draw_empty2(sfVideoMode mode);
sfRectangleShape	*draw_empty3(sfVideoMode mode);
sfRectangleShape	*draw_empty4(sfVideoMode mode);
sfRectangleShape	*draw_empty5(sfVideoMode mode);
sfRectangleShape	*draw_empty6(sfVideoMode mode);
sfRectangleShape	*draw_maintenance(void);
text_t	desc_slots(sfVideoMode mode);
text_t	desc_backpack(sfVideoMode mode);
int	my_strcmp(char *pwd, char *line);
int	my_strlen(char *str);
sfRectangleShape	*invi_combat(sfVideoMode mode);
all_t	*move_key_combat(sfRectangleShape *invc, render_t rndr,
			 all_t *all, int a);
all_t	*combat_input(sfRectangleShape *invi, render_t rndr, all_t *all, int a);
sfRectangleShape	*escape_back(sfRectangleShape *invc);
framebuffer_t	*framebuffer_create(unsigned int width, unsigned int height);
void	my_put_pixel(framebuffer_t *element, int pos, int alpha, int color);
void	my_put_slash(framebuffer_t *element, int pos, int alpha, int color);
void	prototype_one(int y, int x, render_t *rndr,
		      sfVector2i center, framebuffer_t *element);
void	prototype_moon(int y, int x, render_t *rndr,
		       sfVector2i center, framebuffer_t *element);
void	print_balls(render_t *rndr, framebuffer_t *element, int *s_snow);
void	print_moon(render_t *rndr, framebuffer_t *element, int *s_snow);
void	draw_moon(framebuffer_t *element, render_t *rndr,
		  sfVector2i center, int *s_snow);
void	draw_black(framebuffer_t *element, render_t *rndr, sfVector2i center);
void	draw_snow(framebuffer_t *element, render_t *rndr,
		  sfVector2i center, int *s_snow);
sfVector2i	position(sfVector2i center, render_t *rndr, int nb, int nb2);
sfVector2i	move_moon(sfVector2i center, render_t *rndr);
int	*start_snow(render_t *rndr);
void	render_snow(render_t *rndr, framebuffer_t *element, int *s_snow);
void	render_slash(render_t *rndr, framebuffer_t *element2, int *s_slash);

#endif
