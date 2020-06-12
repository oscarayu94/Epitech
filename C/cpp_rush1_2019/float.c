/*
** EPITECH PROJECT, 2020
** cpp_rush1_2019
** File description:
** float
*/

#include <stdio.h>
#include "float.h"
#include "new.h"

typedef struct
{
    Class base;
    float num;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    this->num = va_arg(*args, double);
}

static void Float_dtor(FloatClass *this)
{
}

static FloatClass *Float_add(const FloatClass *this, const FloatClass *other)
{
    return ((FloatClass *)new(Float, this->num + other->num));
}

static FloatClass *Float_sub(const FloatClass *this, const FloatClass *other)
{
    return ((FloatClass *)new(Float, this->num - other->num));
}

static FloatClass *Float_mul(const FloatClass *this, const FloatClass *other)
{
    return ((FloatClass *)new(Float, this->num * other->num));
}

static FloatClass *Float_div(const FloatClass *this, const FloatClass *other)
{
    if (other->num == 0)
        return ((FloatClass *)new(Float, 0));
    return ((FloatClass *)new(Float, this->num / other->num));
}

static bool Float_eq(const FloatClass *this, const FloatClass *other)
{
    return (this->num == other->num);
}

static bool Float_gt(const FloatClass *this, const FloatClass *other)
{
    return (this->num > other->num);
}

static bool Float_lt(const FloatClass *this, const FloatClass *other)
{
    return (this->num < other->num);
}

static char *Float_str(FloatClass *this)
{
    size_t sz = 200;
    char *buffer = malloc(sizeof(char) * sz);

    if (!buffer)
        raise("Error: Float: cannot create string");
    memset(buffer, 0, sz);
    snprintf(buffer, sz, "<%s (%.6f)>", this->base.__name__,  this->num);
    return (buffer);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ = (binary_operator_t)&Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .num = 0,
};

const Class *Float = (const Class *)&_description;