/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/
#include "test.h"

void factor3(char **ptr, long number, long *result, char mem)
{
 	long number2;
        int i;
        char sign;
        char *str;

	i = 0;
	str = (*ptr);
        while(str[0] == '*' || str[0] == '/')
        {
                sign = str[0];
                str = str+2;
                number2 = operator2(&str);
                if(i == 0)
			multiplynb(sign, &number, number2);
		else
			multiplynb(sign, &number, number2);
                i++;
        }
        (*ptr) = str;
	sums(mem, result, number);
}

