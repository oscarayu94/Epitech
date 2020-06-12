/*
** EPITECH PROJECT, 2020
** cpp rush
** File description:
** sample main function
*/

#include "new.h"
#include "list.h"
#include <stdio.h>
#include "int.h"
#include "container.h"

int main(void)
{
    Object *list = new(List, 10, Int, 5);
    Object *it = begin(list);
    Object *it_end = end(list);
    char *s = 0;

    setval(it, 0, 42);
    setval(it, 8, 3);
    setitem(list, 9, 9);
    setitem(list, 100, 22);
    while (lt(it, it_end)) {
        s = str(getval(it));
        printf("%s\n", s);
        incr(it);
        free(s);
    }
    delete(list);
    delete(it);
    delete(it_end);
    return (0);
}