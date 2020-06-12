/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef LIST_H
# define LIST_H

# include "container.h"

typedef struct node_s {
    Object *data;
    struct node_s *next;
} node_t;

extern const Class  *List;

#endif
