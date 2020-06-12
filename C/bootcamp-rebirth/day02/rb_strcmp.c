/*
** EPITECH PROJECT, 2018
** rb_strcmp
** File description:
** strcmp rebirth
*/

#include <stdio.h>

//int	rb_xerror(

int	rb_strcmp(char *s1 , char *s2)
{
	int	i = 0;
	
	if (str == NULL || format == NULL)
	   rb_xerror("rb_strcmp: String format is NULL"); 
	while (s1[i] != '\0') {
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;		
	}
	if (s1[i] == s2[i])
		return (0);
	return (s1[i] - s2[i]);
}

int	main()
{
        printf("%d − %d − %d\n", rb_strcmp("toto", "toto") , rb_strcmp("toto", "tata"), rb_strcmp("toto","		tutu")); 
	//rb_strcmp("toto", "tata");
	return(0);
}	
