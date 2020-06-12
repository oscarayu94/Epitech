/*
** EPITECH PROJECT, 2020
** cpp rush 1
** File description:
** vertex class
*/

#include "new.h"
#include "vertex.h"
#include <stdio.h>

typedef struct {
    Class base;
    int x;
    int y;
    int z;
} VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
}

static VertexClass *Vertex_add(const VertexClass *this,
                                const VertexClass *other)
{
    return ((VertexClass *)new(Vertex, this->x + other->x,
                                this->y + other->y, this->z + other->z));
}

static VertexClass *Vertex_sub(const VertexClass *this,
                                const VertexClass *other)
{
    return ((VertexClass *)new(Vertex, this->x - other->x,
                                this->y - other->y, this->z - other->z));
}

static char *Vertex_str(VertexClass *this)
{
    size_t sz = 200;
    char *buffer = malloc(sizeof(char) * sz);

    if (!buffer)
        raise("Error: Point: cannot create string");
    memset(buffer, 0, sz);
    snprintf(buffer, sz, "<%s (%d, %d, %d)>",
                this->base.__name__, this->x, this->y, this->z);
    return (buffer);
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_str,
        .__add__ = (binary_operator_t)&Vertex_add,
        .__sub__ = (binary_operator_t)&Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0
};

const Class *Vertex = (const Class *)&_description;