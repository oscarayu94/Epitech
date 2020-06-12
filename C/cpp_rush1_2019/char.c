/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** char
*/

#include <stdio.h>
#include "char.h"
#include "new.h"

typedef struct
{
    Class base;
    char c;
}   CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    this->c = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
}

static CharClass *Char_add(const CharClass *this, const CharClass *other)
{
    return ((CharClass *)new(Char, this->c + other->c));
}

static CharClass *Char_sub(const CharClass *this, const CharClass *other)
{
    return ((CharClass *)new(Char, this->c - other->c));
}

static CharClass *Char_mul(const CharClass *this, const CharClass *other)
{
    return ((CharClass *)new(Char, this->c * other->c));
}

static CharClass *Char_div(const CharClass *this, const CharClass *other)
{
    if (other->c == 0)
        return ((CharClass *)new(Char, 0));
    return ((CharClass *)new(Char, this->c / other->c));
}

static bool Char_eq(const CharClass *this, const CharClass *other)
{
    return (this->c == other->c);
}

static bool Char_gt(const CharClass *this, const CharClass *other)
{
    return (this->c > other->c);
}

static bool Char_lt(const CharClass *this, const CharClass *other)
{
    return (this->c < other->c);
}

static char *Char_str(CharClass *this)
{
    size_t sz = 200;
    char *buffer = malloc(sizeof(char) * sz);

    if (!buffer)
        raise("Error: Char: cannot create string");
    memset(buffer, 0, sz);
    snprintf(buffer, sz, "<%s (%c)>", this->base.__name__,  this->c);
    return (buffer);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t)&Char_ctor,
        .__dtor__ = (dtor_t)&Char_dtor,
        .__str__ = (to_string_t)&Char_str,
        .__add__ = (binary_operator_t)&Char_add,
        .__sub__ = (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .c = 0,
};

const Class *Char = (const Class *)&_description;