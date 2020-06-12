/*
** EPITECH PROJECT, 2017
** operator
** File description:
** 
*/

#include <stdio.h>
#include <stdlib.h>
#include "test.h"

void factor2(char **ptr, long number, long *result, char mem)
{
        long    number2;
        int     i;
        char    sign;
	char    *str;

        str = (*ptr);
        i = 0;
        while (str[0] == '*' || str[0] == '/' || str[0] == '%')
	{
                sign = str[0];
                str = str+1;
	        number2 = strtol(str, &str, 10);
		if (i == 0)
                        multiplynb(sign, &number, number2);
                else
                        multiplynb(sign, &number, number2);
                i++;
        }
        (*ptr) = str;
        sums(mem, result, number);
}

void subdivision(char mem, char sign, char **ptr, long number, long *result)
{
        char *str = (*ptr);
        long result2 = (*result);

	if(sign == '*' || sign == '/' || sign == '%')
        {
                if(mem == '-')
	                mem = '+';
                if(str[1] == '(')
                        factor3(&str, number, &result2, \
                                mem);
                else
                        factor2(&str, number, &result2, \
                                mem);
                sign = str[0];
        }
        else
                sums(mem, &result2, number);
        (*ptr) = str;
        (*result) = result2;
}

void move_string(char sign, char **ptr)
{
	char *str = (*ptr);

	if (sign == '*' || sign == '/' || sign == '%')
		 str = str+1;
	(*ptr) = str;
}

void move_string2(char **ptr)
{
	char *str = (*ptr);

	if (str[0] == '*' || str [0] == '/' || str[0] == '%')
		str = str+1;
	else if ((str[0] == '+' || str[0] == '-')&& str[1] == '(')
		str = str+1;
	(*ptr) = str;
}

long operator2(char **str)
{
        long    number;
        char    *ptr;
	int     i;
        char    sign;
        long    result;
	char    mem;

        ptr = (*str);
        i = 0;
        result = 0;
        while (ptr[0] != '\0')
        {
                mem = sign;
                number = strtol(ptr, &ptr, 10);
                if (ptr[0] == '(')
		{
                        ptr = ptr+1;
                        number = operator2(&ptr);
                }
                sign = ptr[0];
	        if (i == 0)
                {
                        result = number;
			move_string(sign, &ptr);
		}
                else if (mem == '*' || mem == '/' || mem == '%')
                        multiply(mem, &result, number);
                else if (mem == '+' || mem == '-')
			subdivision(mem, sign, &ptr, number, &result);
		move_string2(&ptr);
		i++;
		if (ptr[0] == ')')
                {
                        ptr = ptr+1;
                        (*str) = ptr;
                        return(result);
	        }
        }
	printf("%ld\n", result);
        return(result);
}

