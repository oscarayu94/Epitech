/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdio.h>
#include "point.h"
#include "new.h"

typedef struct {
    Class base;
    int x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
}

static PointClass *Point_add(const PointClass *this, const PointClass *other)
{
    return ((PointClass *)new(Point, this->x + other->x, this->y + other->y));
}

static PointClass *Point_sub(const PointClass *this, const PointClass *other)
{
    return ((PointClass *)new(Point, this->x - other->x, this->y - other->y));
}

static char *Point_str(PointClass *this)
{
    size_t sz = 200;
    char *buffer = malloc(sizeof(char) * sz);

    if (!buffer)
        raise("Error: Point: cannot create string");
    memset(buffer, 0, sz);
    snprintf(buffer, sz, "<%s (%d, %d)>",
            this->base.__name__, this->x, this->y);
    return (buffer);
}

static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_str,
        .__add__ = (binary_operator_t)&Point_add,
        .__sub__ = (binary_operator_t)&Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;