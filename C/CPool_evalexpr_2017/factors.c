/*
** EPITECH PROJECT, 2017
** factors
** File description:
** 
*/

#include <stdlib.h>
#include <stdio.h>

char check_sign(char *str)
{
	int i;

	while (str[i] != '\0')
	{
		if (str[i] > '9' || str[i] < '0')
		{
			return (str[i]);
		}
		i++;
	}
}

int factors(char *str, char **av)
{
	float result;
	char *ptr;
	char sign;
	long number;
	int i;

	i = 0;
	ptr = str;
	result = 1;
	while (ptr[i] != '\0')
	{
		sign = check_sign(av[1]);
		number = strtol(ptr, &ptr, 10);
		result = str[2] - 48;
		sign = ptr[0];
		if (sign == '*')
		{
			result = result * number;
		}
		else if (sign == '/')
		{
			printf("%f\n", result);
			printf("divided by ;");
			printf(" %d\n", number);
			result = number / result;
		}
		ptr = ptr + 1;
		i++;
	}
	printf("Result:%f\n", result);
	return(result);
}

int main(int ac, char **av)
{
	factors(av[1], av);


	int i = atoi("12324"); // i is an int equal to 12324
	// "80*90"
	// nb = atoi("80") -------- nb2 = atoi("90")
	// nb * nb2
}
