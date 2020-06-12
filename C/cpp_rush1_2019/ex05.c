/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdio.h>
#include "array.h"
#include "int.h"
#include "new.h"

int main(void)
{
    Object *array = new(Array, 10, Int, 1);
    Object *it = begin(array);
    Object *it_end = end(array);

    printf("array size: %zu\n", len(array));
    setitem(array, 5, 12);
    setitem(array, 9, 13);
    while (lt(it, it_end)) {
        char *s = str(getval(it));
        printf("%s\n", s);
        free(s);
        incr(it);
    }
    delete(it);
    delete(it_end);
    delete(array);
    return (0);
}