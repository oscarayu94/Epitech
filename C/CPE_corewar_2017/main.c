/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include "list.h"

void	step_3(void)
{
	FILE	*fd;
	//int	*num;
	int	a = 123456789;
	
	//num = &a;
	fd = fopen("./number_as_int.yolo.", "w+");
	fseek(fd,4,SEEK_SET);
	//fputc(num, fd);
	//fwrite(num, sizeof(int), 1, fd); //this is not the ascii
	fprintf(fd, "%d", a);
	fclose(fd);
}

void	create_file(void)
{
	FILE	*fd;
        //int	fd = 0;
	char	buffer[19];
	int	size= 0;
	buffer [18] = '\0';
	
	fd = fopen("testfile.txt", "w+");
	fputs("This is turpo", fd);
	fseek(fd,7,SEEK_SET);
	fputs("This is turpo", fd);
	printf("buffer:%s,%d\n",buffer, size);
        /*fd = open("testfile.txt",O_RDWR | O_CREAT, S_IRWXU);
	if (write(fd, "Hello bambino\n", 14) == -1)
		exit(84);
	size = read(fd,buffer,16);
        printf("buffer:%s,%d\n",buffer, size);
	if (lseek(fd,10,SEEK_SET) < 0)
		exit(84);
	
	printf("heh\n");
	size = read(fd,buffer,8);
	
	close(fd);
       */
}

void	step_4(void)
{
	FILE	*fd;
	int	a = 123456789;
	char	str[40] = "Corewar is swag!!";
	//num = &a;
	
	fd = fopen("./number_as_int.yolo.", "w+");
	fprintf(fd, "%d", a);
	fseek(fd, 1, SEEK_SET);
	
	fprintf(fd, "%d", a);
	fprintf(fd, "%c", 'b');
	//fwrite("Corewar is swag!!", sizeof(char) * 40, 17, fd);
	fprintf(fd, "%s", str);
		fclose(fd);
}
void	step_5(void)
{
	FILE	*fd;
	date	*a;
	char	*str = "Corewar is swag!!";
	char	**ptr;
	int	i;

	ptr = get_path_array(str, ' ');
	for (i = 0; ptr[i] != NULL; i++)
		printf("%s\n",ptr[i]);
	a = malloc(sizeof(date));
	for (a->num = 0; str[a->num] != '\0'; a->num++)
		a->corewar[a->num] = str[a->num];
	a->corewar[a->num] = '\0';
	a->num = 01;
	a->k = 'k';
	fd = fopen("./number_as_int.yolo.", "wb");
	
	//fprintf(fd, "%c", 'b');
	if (fd != NULL) {
		fwrite(a, sizeof(a), 4, fd);
		fclose(fd);
	}
}

char	*my_get_hexa_nbr(int nb)
{
	char	*b;
	int	remainder;
	int	divider = nb;
	int	i;

	b = malloc(sizeof(char) * 40);
	for (i = 0; divider >= 16; i++) {
		divider = nb / 16;
		remainder = nb % 16;
		if (remainder > 9 && remainder < 16)
			b[i] = 'a' + (remainder - 10);
		else
			b[i] = remainder + '0';
		nb = divider;
	}
	if (divider > 9 && divider < 16)
		b[i] = 'A' + (divider - 10 - '0');
	else
		b[i] = divider + '0';
	b[i + 1] = '\0';
	printf("hexa:%s\n", b);
	return (b);
}

int	main(int ac, char **av)
{
	char	*str;
	//int	i;
	//step_5();
	my_get_hexa_nbr(2081);
	my_get_hexa_nbr(1);
	my_get_hexa_nbr(23);
	if (ac != 2)
		return (84);
        str = get_file(av[1]);
	if (str == NULL)
		return (84);
	//printf("%s\n\n\n\n",str);
	yolotron(str);
	//create_file();
	return (0);
}
