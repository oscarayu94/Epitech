/*
** EPITECH PROJECT, 2017
** my_popup_test
** File description:
** File designed to test different shit about centering
*/

#include <ncurses.h>



/* int getx (void) */
/* { */
/* 	int mx = 0; */

/* 	initscr(); */
/* 	getmaxx(stdscr, mx); */
/* 	endwin(); */

/* 	printf("%d\n", mx); */

/* 	return 0; */
/* } */

/* int gety (void) */
/* { */
/* 	int my = 0; */

/*         initscr(); */
/*         getmaxy(stdscr, my); */
/*        	endwin(); */

/*         printf("%d\n", my); */

/* 	return 0; */
/* } */

int main(void)
{
int	getx;
int	gety;


	initscr();

getmaxyx(stdscr, getx, gety);
mvprintw(0, 0, "size. %d %d", gety, getx);
getch();
	endwin();
}
