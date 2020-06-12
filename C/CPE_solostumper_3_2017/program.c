/*
** EPITECH PROJECT, 2018
** FuzzNozz
** File description:
** Takes two numbers, prints between following some rules.
*/

// only authorized function write, atoi, printf

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int which_multiple(int A)
{
	if ( A%2 == 0)
		write(1,"Fuzz\n",6);
	else if ( A%3 == 0)
	{
		write(1,"Bozz\n",6);
	}	
  
}	

int multiple(int A)
{
	if ( A%2 == 1 && A%3 == 1)
		printf("%d\n", A);
	if ( A%2 == 0 && A%3 == 0)
		write(1,"FuzzBozz\n",10);
	else if ( A%2 == 0 || A%3 == 0)
		which_multiple(A);
}	

int print_number(int A, int B)
{
	if ( A == B)
	{
		multiple(A);
	}
	multiple(A);
	while (A != B)
	{
		A++;
		multiple(A);
	}	
}

int main(int ac, char **av)
{
	int A;
	int B;

	if (ac != 3)
	{
		write(1,"Wrong\n",7);
		return(84);
	}

	A = atoi(av[1]);
	B = atoi(av[2]);

	if (B < A)
	{
		write(1,"The second parameter needs to be bigger than the first one\n",60);
		return(84);
	}	
	print_number(A, B);
	return(0);
}
