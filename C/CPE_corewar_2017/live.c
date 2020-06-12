 /*
** EPITECH PROJECT, 2018
** luisillillos xd
** File description:
** live part
*/

#include "list.h"

void	register_part(asm_t *a, int *live_num, int x, int i)
{
	for (i = 1; a->regi[i] != NULL; i++) {
		if (strcom(a->a, a->regi[i]) == 1) {
			if ((*live_num) > 60000)
				(*live_num)--;
			else
				(*live_num)++;
		}
	}
}

int	is_code_there(asm_t *a, int *live_num, int x)
{
	int	i = 1;

	printf("a->num.x:%d\n", a->num.x);
	register_part(a, live_num, x, i);
	if (a->y == a->i && a->x == x && strcom(a->a, "%:live") == 1) {
		if ((*live_num) > 60000)
			return ((*live_num) - 3);
		(*live_num) = 3;
	} else if (strcom(a->a, "%:live") == 1) {
		if ((*live_num) > 60000)
			(*live_num) = (*live_num) - 3;
		else
			(*live_num) = (*live_num) + 3;
	} else {
		for (i = 0; a->a[i] != '\0'; i++) {
			if (a->a[i] == '%' && (*live_num) > 60000
			    && a->num.x != 0)
				(*live_num) = (*live_num) - 4;
			else if (a->a[i] == '%' && (*live_num) < 60000)// && a->num.x != 0)
				(*live_num) = (*live_num) + 4;
		}
	}
	return (0);
}

int	find_live(asm_t *a, int i, int *live_num)
{
	if (strcom(a->a, "live") == 1 && a->x == 4) {
		if (a->i < a->y)
			return (1);
		if (a->i == a->y && a->x > i)
			printf("hoho\n");
		if (a->i > a->y) {
			a->num.x = 0;
			(*live_num) = 65535;
		}
	}
	return (0);
}

void	start_after_comilla(asm_t *a)
{
	for(a->y = 0; a->ptr[a->y][0] == '#' || a->ptr[a->y][0] == '.' ||
	            a->ptr[a->y][0] == ' '; a->y++);
}

int	live_number(asm_t *a, int i)// char *str)//, char *str)
{
	//int	i = 0;
	int	b = 0;
	int	live_num = 0;
	printf("a->a:%s\n", a->a);
	printf("a->i:%d,i:%d\n", a->i, i);
	start_after_comilla(a);
	a->num.x = 1;
	for (a->y = a->y; a->ptr[a->y] != NULL; a->y++) {
		for (a->x = 0; a->ptr[a->y][a->x] != '\0'; a->x++, b++) {
			a->a[b] = a->ptr[a->y][a->x];
			if (a->ptr[a->y][a->x] == ' ' ||
			    a->ptr[a->y][a->x] == ',' ||
			    a->ptr[a->y][a->x] == '\n' ||
			    a->ptr[a->y][a->x + 1] == '\0' ||
			    (a->ptr[a->y][a->x] == ':' &&
			     a->ptr[a->y][a->x + 1] != 'l' &&
			     a->ptr[a->y][a->x + 2] != 'i')) {
				if (a->ptr[a->y][a->x + 1] != '\0')
					a->a[b] = '\0';
				else
					a->a[b + 1] = '\0'; 
				if (find_live(a, i, &live_num) == 1)
					return (live_num);
				if (is_code_there(a, &live_num, i) != 0)
					return (live_num);
				printf("live_num:%d, %s\n", live_num, a->a);
				b = -1;
			}
		}
		a->num.x++;
	}
	return (i);
}
