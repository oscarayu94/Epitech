// Cualquier valor de 0 a 100, puede decirte si es multiplo de 3 o de 5, o de los dos.

int	main(int i)
{
	i = my_multiple(0,100);
}

int	my_multiple(int a, int b)
{
	while (a <= b)
	{

		if (a%3 == 0 && a%5 == 0)
                {
                        write (1,"Fizz Buzz\n",10);
                }
		else if (a%3 == 0 || a%5 == 0)
		{
			if (a%3 == 0)
			{	
				write (1,"Fizz\n",5);
			}
			else if (a%5 == 0)
			{
				write (1,"Buzz\n",5);
			}	
		}
		else if (a%3 != 0 && a%5 != 0)
		{	
			printf("%d\n",a);
		}	
		a++;
	}	
}
	
