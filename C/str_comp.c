/*
** EPITECH PROJECT, 2018
** str_comp
** File description:
** str_comp?
*/

#include <stdio.h>

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

int main (void)
{
	char string1[] = "abcdef";
	char string2[] = "abcdea";
	printf("strcmp() = %d\n", strcmp(string1, string2));
	printf("strncmp() = %d\n", strncmp(string1, string2, 4));
	return(0);
}

/*EOF main*/
/* Compare two strings */

int strcmp(const char *s1, const char *s2)
{
	int i;
	int n1 = 0;
	int n2 = 0;

	for (i = 0; s1[i] != '\0'; i++) {
		if (s1[i] != s2[i])
			return (1);
	}
	
	return (0);
}

	
	
