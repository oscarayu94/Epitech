/*
** EPITECH PROJECT, 2017
** day06
** File description:
** task03
*/
int     my_strlen(char const *str);
char    *my_revstr(char *str)
{
        int     i;
        int     len;
        char    tmp;
        int     fin;
        len = my_strlen(str);
        i = 0;
        fin = len / 2;
        while(len != fin)
        {
                tmp = str[i];
                str[i] = str[len - 1];
                str[len - 1] = tmp;
                len--;
                i++;
        }
        return (str);
}
