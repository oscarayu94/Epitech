#include <ncurses.h>

int main(void)
{
int     getx;
int     gety;
int	ancho;
int	largo;
int	medioa;
int	mediol;

medioa = 0;
mediol = 0;
ancho = 0;
largo = 0;

	initscr();

getmaxyx(stdscr, getx, gety);
ancho = gety;
largo = getx;
medioa = ancho/2;
mediol = largo/2;

WINDOW *field = newwin(900, 800, 0, 0);
mvwprintw(field, 0, 0, "size.%d %d", medioa, mediol);
getch();
        endwin();
}

