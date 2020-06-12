/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** int
*/

#include <stdio.h>
#include "int.h"
#include "new.h"

typedef struct
{
    Class   base;
    int     num;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    this->num = va_arg(*args, int);
}

static void Int_dtor(IntClass *this)
{
}

static IntClass *Int_add(const IntClass *this, const IntClass *other)
{
    return ((IntClass *)new(Int, this->num + other->num));
}

static IntClass *Int_sub(const IntClass *this, const IntClass *other)
{
    return ((IntClass *)new(Int, this->num - other->num));
}

static IntClass *Int_mul(const IntClass *this, const IntClass *other)
{
    return ((IntClass *)new(Int, this->num * other->num));
}

static IntClass *Int_div(const IntClass *this, const IntClass *other)
{
    if (other->num == 0)
        return ((IntClass *)new(Int, 0));
    return ((IntClass *)new(Int, this->num / other->num));
}

static bool Int_eq(const IntClass *this, const IntClass *other)
{
    return (this->num == other->num);
}

static bool Int_gt(const IntClass *this, const IntClass *other)
{
    return (this->num > other->num);
}

static bool Int_lt(const IntClass *this, const IntClass *other)
{
    return (this->num < other->num);
}

static char *Int_str(IntClass *this)
{
    size_t sz = 200;
    char *buffer = malloc(sizeof(char) * sz);

    if (!buffer)
        raise("Error: Int: cannot create string");
    memset(buffer, 0, sz);
    snprintf(buffer, sz, "<%s (%d)>", this->base.__name__,  this->num);
    return (buffer);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .num = 0,
};

const Class *Int = (const Class *)&_description;