/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task13
*/

int     my_strlen(char const *str);

int     my_str_isupper(char const *str)
{
        int     i;
        i = 0;
        if (my_strlen(str) == 0)
                return (1);
        while (i < my_strlen(str))
        {
                if (str[i] < 'A' || str[i] > 'Z')
                        return (0);
                i++;
        }
        return (1);
}
