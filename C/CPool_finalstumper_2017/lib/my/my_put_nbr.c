/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task07
*/
void	my_putchar(char c);

int	my_put_nbr(int nb)
{
	int	tmp;
	int	printedVar;
	int	envers;
	tmp = nb;
	if (nb == 0)
	{
		my_putchar('0');
		return (0);		
	}
	if (nb < 0)
	{	
		my_putchar('-');
		tmp = tmp * -1;
	}
	envers = tmp % 10;
	tmp = tmp / 10;
	while (tmp != 0)
	{
		envers = (tmp % 10) + (envers * 10);
		tmp = tmp / 10;
	}		
	while (envers != 0)
	{
		printedVar = envers % 10;
		my_putchar(printedVar + '0');
		envers = envers / 10;
	}
	return (0);
}
