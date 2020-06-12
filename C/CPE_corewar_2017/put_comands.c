/*
** EPITECH PROJECT, 2018
** 
** File description:
** corewar comands
*/

#include "list.h"

int	binary(int k)
{		
	if (k == 0)
		return (0);
	if (k == 1)
		return (1);
	k = (k % 2) + 10 * binary(k / 2);
	//my_put_nbr(k);
	return (k);
}

int	strcom(char *a, char *b)
{
	int	i;

	for (i = 0; a[i] != '\0'; i++)
		if (a[i] != b[i])
			return (0);
	if (b[i] != '\0')
		return (0);
	return (1);
}

int	strcom_dif_size(char *a, char *b)
{
	int	i;

	for (i = 0; a[i] != '\0'; i++)
		if (a[i] != b[i])
			return (0);
	return (1);
}

char	**feed_with_comands(void)
{
	char	**ptr;

	ptr = malloco(16);
	ptr[0] = NULL;
	ptr[1] = "live";
	ptr[2] = "ld";
	ptr[3] = "st";
	ptr[4] = "add";
	ptr[5] = "sub";
	ptr[6] = "and";
	ptr[7] = "or";
	ptr[8] = "xor";
	ptr[9] = "zjmp";
	ptr[10] = "ldi";
	ptr[11] = "sti";
	ptr[12] = "fork";
	ptr[13] = "lld";
	ptr[14] = "lldi";
	ptr[15] = "lfork";
	ptr[16] = "aff";
	ptr[17] = NULL;
	return (ptr);
}

char	**registers(void)
{
	char	**ptr;

	ptr = malloco(16);
	ptr[0] = NULL;
	ptr[1] = "r1";
	ptr[2] = "r2";
	ptr[3] = "r3";
	ptr[4] = "r4";
	ptr[5] = "r5";
	ptr[6] = "r6";
	ptr[7] = "r7";
	ptr[8] = "r8";
	ptr[9] = "r9";
	ptr[10] = "r10";
	ptr[11] = "r11";
	ptr[12] = "r12";
	ptr[13] = "r13";
	ptr[14] = "r14";
	ptr[15] = "r15";
	ptr[16] = "r16";
	ptr[17] = NULL;
	return (ptr);
}
	
int	*feed_with_comands_num(void)
{
	int	*ptr;

	ptr = malloc(sizeof(int) * 18);
	ptr[0] = -84;
	ptr[1] = 0;
	ptr[2] = 208;
	ptr[3] = 112;
	ptr[4] = 84;
	ptr[5] = 84;
	ptr[6] = 100;
	ptr[7] = 100;
	ptr[8] = 100;
	ptr[9] = 0;
	ptr[10] = 228;
	ptr[11] = 104;
	ptr[12] = 0;
	ptr[13] = 0;
	ptr[14] = 228;
	ptr[15] = 0;
	ptr[16] = 64;
	ptr[17] = -84;
	return (ptr);
}

int	percentage(int fd, char *a)
{
	int	i = 0;
	int	num;

	if (strcom(a, "%") == 1) {
		write(fd, &i, sizeof(int));
		return (1);
	}
	else if (a[0] == '%') {
		for (i = 1; a[i] != '\0'; i++)
			if (i < '0' || i > '9')
				return (0);
		num = my_getnbr(&a[1]);
		printf("num:%d\n", num);
	}	
	return (0);
}

int	is_a_number(int fd, char *a)
{
	int	i;
	
	for (i = 0; a[i] != '\0'; i++)
		if (i < '0' || i > '9')
			return (0);
	i = my_getnbr(a);
	if (i != -84)
		write(fd, &i, sizeof(int));
	return (0);
}

int	is_code_in_ptr(asm_t *a)
{
	int	i;
	int	*code_num;

	if (is_a_number(a->fd, a->a) == 1 ||
	    percentage(a->fd, a->a) == 1)
		return (0);
	code_num  = feed_with_comands_num();
	for (i = 1; a->code[i] != NULL; i++)
	{
		if (strcom(a->a, a->regi[i]) == 1) {
			printf("enteryiyi:a:%s\n",a->a);
			//write(fd, &regi[1][2], sizeof(char));
			write(a->fd, &i, sizeof(char));
		}
		if (strcom(a->a, a->code[i]) == 1) {
			printf("enter:a:%s\n",a->a);
			write(a->fd, &i , sizeof(char));
			write(a->fd, &code_num[i] , sizeof(char));
		}
	}
	return (0);
}

int	write_comand(char *ptr, asm_t *a)//int fd, char **all, int pos)
{
	int	i;
	int	b = 0;
	//int	live_num;

	a->regi = registers();
	for (i = 0; ptr[i] != '\0'; i++, b++) {
		a->a[b] = ptr[i];
		if (ptr[i] == ' ' || ptr[i] == ',' || ptr[i] == '\n' ||
		    (ptr[i] == ':' && ptr[i + 1] != 'l' && ptr[i + 2] != 'i')) {
			a->a[b] = '\0';
			is_code_in_ptr(a);
			//if (strcom_dif_size(a->a, "%:live") == 1)
			if (strcom(a->a, "%:live") == 1)
				live_number(a, i);
			printf("a:%s\n",a->a);
			b = -1;
		}
	}
	//free(a);
	return (0);
}

int	put_comands(int fd, char **ptr)
{
	asm_t	*a;

	a = malloc(sizeof(asm_t));
	a->fd = fd;
	a->ptr = ptr;
	a->a = malloc(sizeof(char)* 50);
	a->code = feed_with_comands();

	for(a->i = 0; ptr[a->i][0] == '#' || ptr[a->i][0] == '.' ||
		    ptr[a->i][0] == ' '; a->i++);
	printf("ptr[i]:%s\n", ptr[a->i]);
	printf("ptr[i]:%s\n", ptr[a->i + 1]);
	for (a->i = a->i + 1; ptr[a->i] != NULL; a->i++)
		write_comand(ptr[a->i],a);
	a->i = 34;
	write(fd, &a->i , sizeof(int));
	write(fd, &a->i , sizeof(char));
	return (0);
}
