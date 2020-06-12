/*
** EPITECH PROJECT, 2017
** rush2
** File description:
** Reads letters
*/

#include <unistd.h>
#include <stdio.h>


int	lectura(int a, char **b)
{
	int i;
	int j;
	int d;

	d = 2;
	j = 0;
	i = 0;
	while (d < a)
	{	
		if(b[d][0] >= 97 && b[d][0] <= 122)
		{	
			while(b[1][i] != '\0')
			{
				if(b[d][0] == b[1][i] || b[d][0] == b[1][i] || b[d][0] - 32 == b[1][i])
				{
					j++; 	
				}
				i++;
			}
			printf("%c:",b[d][0]);
			printf("%d\n",j);
		}
		else if(b[d][0] >= 65 && b[d][0] <= 90)
		{
			while(b[1][i] != '\0')
			{
				if(b[d][0] == b[1][i] || b[d][0] == b[1][i] || b[d][0] + 32 == b[1][i])
				{
					j++;
				}
				i++;
			}
			printf("%c:",b[d][0]);
			printf("%d\n",j);
		}
		else
		{
			write(1,"Invalid character\n",19);
		}
		d++;
	}
}

int	main(int a, char **b)
{
	lectura (a, b);
}	
