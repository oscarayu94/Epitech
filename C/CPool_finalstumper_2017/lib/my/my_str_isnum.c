/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task11
*/

int     my_strlen(char const *str);

int     my_str_isnum(char const *str)
{
        int     i;
        i = 0;
        if (my_strlen(str) == 0)
                return (1);
        while (i < my_strlen(str))
        {
                if (str[i] < '0' || str[i] > '9')
                        return (0);
                i++;
        }
        return (1);
}
