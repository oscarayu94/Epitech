/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task05
*/
int     my_strlen(char const *str);

int	my_getnbr(char const *str)
{
	int	len;
	int	i;
	double	nbr;
	int	neg;
	int	fin;
	double	mult;
	int	ret;
	mult = 1;
	neg = 0;
	nbr = 0;
	i = 0;
	len = my_strlen(str);

	while ((i < len) && (str[i] < '0' || str[i] > '9'))
		i++;
	fin = i;
	if (str[i-1] == '-')
		neg = 1;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while (i >= fin)
	{
		nbr = nbr + ((str[i] - '0') * mult);
		mult = mult * 10;
		i--;
	}
	if (neg == 1)
	{
		if(nbr > 2147483647)
			return (0);
	        else
			nbr = nbr * -1;
	}
	if (nbr > 2147483647)
		return (0);
	else
	{
		ret = nbr;
		return (ret);
	}
}
