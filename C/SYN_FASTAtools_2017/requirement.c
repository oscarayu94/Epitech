/*
** EPITECH PROJECT, 2018
** requirement 2
** File description:
** retake on requirement
*/

char	*check_special(char *str, int i)
{	
	if (( i == 0) && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
	if ((str[i - 1] == '+') && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
	if ((str[i - 1] == '-') && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
	return(str);
}

char	*my_strcapitalize_synthesis (char *str)
{
	int i = 0;

        while (str[i] != '\0'){
		if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
			if(str[i - 1] > '0' && str[i - 1] < '9'){
				while (str[i] != ' '){
					if((str[i] >= 'A' && str[i] <= 'Z'))
						str[i] = str[i] + 32;
					i++;
				}
			}
			if ((str[i - 1] == ' ') && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - 32;
			if ((str[i - 1] != ' ') && (str[i] >= 'A' && str[i] <= 'Z'))
				str[i] = str[i] + 32;
		}
		check_special(str, i);
                printf("%s", str);
		i++;		
	}
	return (str);
}
