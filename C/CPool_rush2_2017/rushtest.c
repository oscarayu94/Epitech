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
        float r;
	char s;
	char p;
	char v;

	s = ' ';
	p = '(';
	v = ')';
	j = 0;
	i = 0;
	d = 2;
	while(d < a )
	{
		if(b[d][0] >= 65 && b[d][0] <= 90)
		{	
			while(b[1][i] != '\0')
			{
				if(b[d][0] == b[1][i] || b[d][0] == b[1][i] || b[d][0] + 32 == b [1][i])
				{
					j++; 	
				}
				i++;
			}
			printf("%c:",b[d][0]);
			printf("%d",j);
			printf("%c",s);
			printf("%c",p);
			r = (j/i)*100;
		     	printf("%d", r);
			printf("%c\n",v);
		}
		else if(b[d][0] >= 97 && b[d][0] <= 122 || b[d][0] == b[1][i] || b[d][0] - 32 == b [1][i])
		{
			while(b[1][i] != '\0')
			{
				if(b[d][0] == b[1][i])
				{
					j++;
				}
				i++;
			}
			printf("%c:",b[d][0]);
			printf("%d",j);
			printf("%c",s);
			printf("%c",p);
			r = (j/i)*100;
			printf("%d",r);
			printf("%c\n",v);
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
