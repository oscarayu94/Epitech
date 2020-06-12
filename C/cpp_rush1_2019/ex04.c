/*
** EPITECH PROJECT, 2020
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdio.h>
#include "new.h"
#include "int.h"

void compareAndDivide(Object *a, Object *b)
{
    Object *div = 0;
    char *str_tmp = NULL;

    if (gt(a, b))
        printf ("a > b\n");
    else if (lt(a, b))
        printf ("a < b\n");
    else
        printf ("a == b\n");
    div = division(b, a);
    str_tmp = str(div);
    printf ("b / a = %s\n", str_tmp);
    delete(div);
    free(str_tmp);
}

int main(void)
{
    Object *p1 = new(Int, 0);
    Object *p2 = new(Int, 2);

    compareAndDivide(p1, p2);

    delete(p1);
    delete(p2);
    return (0);
}