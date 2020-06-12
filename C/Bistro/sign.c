/*
** EPITECH PROJECT, 2017
** Signs
** File description:
** 
*/

#include "test.h"

void multiplynb(char mem, long *number, long number2)
{
        if (mem == '*')
                (*number) = (*number) * number2;
        else if (mem == '/')
                (*number) = (*number) / number2;
        else if (mem == '%')
                (*number) = (*number) % number2;
}

void multiply(char mem, long *result, long number)
{
        if (mem == '*')
                (*result) = (*result) * number;
        else if (mem == '/')
                (*result) = (*result) / number;
        else if (mem == '%')
                (*result) = (*result) % number;
}

void sums(char mem, long *result, long number)
{
        if (mem == '+')
                (*result) = (*result) + number;
        if (mem == '-')
        {
                if (number < 0)
			(*result) = (*result) + number;
                else
                        (*result) = (*result) - number;
        }
}

