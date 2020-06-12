/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct
{
    Container base;
    Class *_type;
    size_t _size;
    node_t *_head;
}   ListClass;

typedef struct {
    Iterator    base;
    ListClass  *_list;
    size_t      _idx;
}   ListIteratorClass;

static void ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_idx = va_arg(*args, int);
}

static bool ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void ListIterator_incr(ListIteratorClass *this)
{
    this->_idx += 1;
}

static Object *ListIterator_getval(ListIteratorClass *this)
{
    return ((*((Container *)this->_list)->__getitem__)((Container *)this->_list, this->_idx));
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list args;
    node_t *tmp;
    unsigned int index;
    unsigned int i = 0;

    va_start(args, this);
    index = va_arg(args, int);
    if (index >= this->_list->_size)
        return;
    for (tmp = this->_list->_head; tmp && i != index; tmp = tmp->next, i++);
    delete(tmp->data);
    tmp->data = va_new(this->_list->_type, &args);
    va_end(args);
}

static const ListIteratorClass ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._idx = 0
};

static const Class *ListIterator = (const Class *)&ListIteratorDescr;

static node_t *create_node(Object *data)
{
    node_t *node = malloc(sizeof(node_t));

    if (!node)
        raise("Error: could not allocate node");
    node->data = data;
    node->next = 0;
    return (node);
}

static void List_ctor(ListClass *this, va_list *args)
{
    va_list tmp_arg;
    node_t *head = 0;
    node_t *tmp_node = 0;
    unsigned int i;

    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    if (this->_size <= 0)
        return;
    va_copy(tmp_arg, *args);
    head = create_node(va_new(this->_type, &tmp_arg));
    tmp_node = head;
    for (i = 1; tmp_node && i < this->_size; i++) {
        va_copy(tmp_arg, *args);
        tmp_node->next = create_node(va_new(this->_type, &tmp_arg));
        va_end(tmp_arg);
        tmp_node = tmp_node->next;
    }
    this->_head = head;
}

static void List_dtor(ListClass *this)
{
    node_t *tmp;
    node_t *list = this->_head;

    while ((tmp = list) != 0) {
        list = list->next;
        delete(tmp->data);
        free(tmp);
    }
}

static size_t List_len(ListClass *this)
{
    return (this->_size);
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, 0));
}

static Iterator *List_end(ListClass *this)
{
    return (new(ListIterator, this, this->_size));
}

static Object *List_getitem(ListClass *this, ...)
{
    va_list args;
    size_t index = 0;
    node_t *tmp;

    va_start(args, this);
    index = va_arg(args, size_t);
    va_end(args);
    if (index >= this->_size)
        return (0);
    tmp = this->_head;
    for (unsigned int i = 0; tmp && i < index; i++)
        tmp = tmp->next;
    return (tmp->data);
}

static void List_setitem(ListClass *this, ...)
{
    va_list args;
    size_t index = 0;
    node_t *tmp;

    va_start(args, this);
    index = va_arg(args, size_t);
    if (index >= this->_size)
        return;
    tmp = this->_head;
    for (unsigned int i = 0; tmp && i < index; i++)
        tmp = tmp->next;
    delete(tmp->data);
    tmp->data = va_new(this->_type, &args);
    va_end(args);
}

static const ListClass _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._head = NULL
};

const Class *List = (const Class *)&_descr;