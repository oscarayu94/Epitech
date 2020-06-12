/*
** EPITECH PROJECT, 2020
** cpp rush 1
** File description:
** new.c
*/

#include <stdarg.h>
#include "new.h"
#include "player.h"

Object *va_new(const Class *class, va_list *ap)
{
    Class *instance = malloc(class->__size__);

    if (!instance)
        raise("Error: could not allocate class");
    memcpy(instance, class, class->__size__);
    if (class->__ctor__)
        class->__ctor__(instance, ap);
    return (instance);
}

Object *new(const Class *class, ...)
{
    Class *instance = 0;
    va_list args;

    if (!class)
        raise("Error: null pointer");
    va_start(args, class);
    instance = va_new(class, &args);
    va_end(args);
    return (instance);
}

void delete(Object *ptr)
{
    Class *instance = ptr;

    if (!ptr)
        raise("Error: null pointer");
    else if (instance->__dtor__)
        instance->__dtor__(instance);
    free(instance);
    instance = 0;
}