// La funcion imprime del 0 al 9 y luego da id = 42.

int	my_test(int a, int b)
{

	if (b < a)
	{
		while (a > b)
		{
			printf("%d\n",a);
			a--;
		}	
	}	
	else
	while (a < b)
	{
		printf("%d\n",a);
		a++;
	}
	return (42);
}

int	main(int ac, char **av)
{
	int i;

        i = my_test (0,10);
	printf ("id = %d\n",i);
}
