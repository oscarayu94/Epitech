/*
** EPITECH PROJECT, 2018
** maths
** File description:
** 
*/

#include "list.h"

void CilBody(int *v, int *p, int r)
{
        float   a = (v[0]*v[0] + v[1]*v[1]);
        float   b = 2 * v[0]*p[0] + 2*v[1]*p[1];
        float   c = (- r*r + p[0]*p[0] + p[1]*p[1]);
        float   g;
        float   m;
	float   alpha = b * b -4 * a *c;

        if (alpha < 0)
                printf("No intersection point.\n");
        else if (a == 0)
                printf("There is an infinite number of intersection points.\n");
        if (alpha == 0)
        {
                g = -(b/(2 * a));
		if (g >= 0 || g < 0)
                {
                        printf("1 intersection point :\n");
                        printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],  \
                               p[1]+ g * v[1], p[2]+ g * v[2]);
                }
                else
                        printf("No intersection point.\n");
        }
        if (alpha > 0)
        {
                printf("2 intersection points :\n");
                g = (-b - sqrt (alpha)) / (2 * a);
                m = (-b + sqrt (alpha)) / (2 * a);
                printf("(%.3f, %.3f, %.3f)\n", p[0]+ m * v[0],  \
                       p[1]+ m * v[1], p[2]+ m * v[2]);
                printf("(%.3f, %.3f, %.3f)\n", p[0]+ g * v[0],  \
                       p[1]+ g * v[1], p[2]+ g * v[2]);
        }
}

int err(int ac)
{
        if (ac != 9)
                return (0);
        return (1);
}

void sphere(char **av)
{
        printf("sphere of radius: ");
        printf("%d\n", atoi(av[8]));
}

void cilinder(char **av)
{
        printf("cylinder of radius ");
        printf("%d\n", atoi(av[8]));
}

void line(int *v, int *p)
{
        printf("Straight line going through the (%d,%d,%d) ",\
               p[0],p[1],p[2]);
        printf("Point and of direction vector (%d,%d,%d)\n",\
               v[0],v[1],v[2]);
}

