/*
** EPITECH PROJECT, 2017
** eval_expr
** File description:
** short calculator
*/

void my_putchar(char c)
{
        write (1,&c,1);
}

int     my_put_nbr(int nb)
{
        int i;
        int a;

        i = 0;
        a = 0;
        while ( i != nb)
        {
                i++;
        }
        while (a != 0)
        {
                a = nb/10;
                a = a/10;
                printf("%d",a);

        }
}

int    eval_expr(char *str)
{
        int     i;
        int     n;

        i = 0;
        n = 0;
       
        while (str[i] != '\0')
        {
                if ((str[i] < '0' || str[i] > '9'))
                {
                        printf("There must be only numbers in the string\n");
                        n = n + str[i] - 48;
                        i++;
		}	
                else if ((str[i] >= '0' || str[i] <= '9'))
                {
			if ((str[i] == '('))
			{
				while (str[i] != ')')
				{
					while (str[i] != '*' || str[i] != '/' || str[i] != '%')
					{
						if (str[i] == '*')
						{
						
						}
						else if (str[i] == '/')
						{
						
						}
						else if (str[i] == '%')
						{

						}
						i++;
					}	
					if (str[i] == '+' || str[i] == '-')
					{
						if (str[i] == '+')
						{
						
						}
						if (str[i] == '-')
						{
						
						}
					}
					i++;
				}
			}
			else
			{
				while (str[i] != '*' || str[i] != '/' || str[i] != '%')
  					{
					        if (str[i] == '*')
					        {

			                        }
                                                else if (str[i] == '/')
			                        {

						}
                                                else if (str[i] == '%')
			                        {

                                                }
                                                i++;
                                        }
        				if (str[i] == '+' || str[i] == '-')
					{
                                                if (str[i] == '+')
                                                {

                                                }
                                                if (str[i] == '-')
                                                {

                                                }
					}
		   	}	
		}        
		i++;
	}
}


