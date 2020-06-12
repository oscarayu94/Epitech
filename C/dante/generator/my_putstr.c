/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** 
*/

#include "list.h"

int     my_putstr(char const *str)
{
        int i;

        i = 0;
        while (str[i] != '\0')
        {
                my_putchar(str[i]);
                i++;
        }
	return(0);
}
   
	      
	
