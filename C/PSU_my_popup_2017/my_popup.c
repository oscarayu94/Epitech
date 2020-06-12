/*
** EPITECH PROJECT, 2017
** my_popup
** File description:
** Finds the center of the terminal and writes a line in it
*/

#include <ncurses.h>

int main(void)
{
   int mx=0, my=0;

   initscr();
   getmaxyx(stdscr, mx, my);
   endwin();

   printf("%d %d", mx, my);

   return 0;
}
