/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** ex02
*/

#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"
#include "player.h"

int main(void)
{
    Object *point = new(Point, 42, -42);
    Object *vertex = new(Vertex, 0, 1, 2);

    char *pt = str(point);
    char *pt2 = str(vertex);

    printf("point = %s\n", pt);
    printf("vertex = %s\n", pt2);

    free(pt);
    free(pt2);
    delete(point);
    delete(vertex);
    return (0);
}