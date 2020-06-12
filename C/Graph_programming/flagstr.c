int     my_putchar(char c)
{
        write(1,&c,1);
	return (0);
}

int	ngtvflag(char const *str, char const *to_find)
{
	int     c;

        c = 0;
        while(str[c] != '\0')
	{
		if (*str = *to_find)
		{
			return(1);
		}
		else
		{
			return(2);
		}
		c++;
	}
}	

int     main()
{
 	char    str[]= "Hello";
	char    to_find[]= "el";

	ngtvflag(str, to_find);
	return(0);
}
	
