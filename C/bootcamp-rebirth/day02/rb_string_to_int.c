/*
** EPITECH PROJECT, 2018
** rb_string_to_int.c
** File description:
** string to int
*/

int	rb_string_to_int(char *str)
{
	int	i;

	i = strlen(str);
	
		//Usar strlen para determinar el largo
		//Segun el largo, asignar un valor. 6 caracteres = 1 millon
		//multiplicar el char pasado por letra. 	       
	
}

int	main()
{
	printf("%d-%d−%d\n", rb_string_to_int("424242"),rb_string _to_int("0"), rb_string_to_int("−2147483648"));
	rb_string_to_int(NULL);
	return (0);
}	
