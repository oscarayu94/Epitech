/*
** EPITECH PROJECT, 2018
** yolotron
** File description:
** by ORIOL
*/

#include "list.h"
 
void	add(char **str, int fd, int num)
{
	if (my_strcmp(str[0], "add") == 1 && num == 3) {
		num = 1128;
		write(fd, &num, sizeof(char));
                num = my_get_nbr(str[1]) + my_get_nbr(str[2]);
		printf("numerosum:%d\n",num);
		write(fd, &num, sizeof(int));
		write(fd, "\n", 1);
		//fwrite("\n", sizeof(char), 1, fd);
        }
}

void	sub(char **str, int fd, int num)
{
	if (my_strcmp(str[0], "sub") == 1 && num == 3) {
		num = 2;
		write(fd, &num, sizeof(char));
		num = my_get_nbr(str[1]) - my_get_nbr(str[2]);
		write(fd, &num, sizeof(int));
		write(fd, "\n", 1);
		//fprintf(fd, "%c", '\n');
	}
}

void	put(char **str, int fd, int num)
{
	if (my_strcmp(str[0], "put") == 1) {
		num = 4;
		write(fd, &num, sizeof(char));
		for (num = 1; str[num] != NULL; num++)
			write(fd, str[num], my_strlen(str[num]));
		write(fd, "\n", 1);
		//fwrite("\n", sizeof(char), 1, fd);
		//fprintf(fd, "%c", '\n');
	}
}

int     yolotron_asm(char *av, int fd)
{
	char    **str;
        int     num = 0;
	
	printf("hehe\n");
        str = get_path_array(av, ' ');
	for (num = 0; str[num] != NULL; num++);
	printf("num:%d\n",num);
	add(str, fd, num);
	sub(str, fd, num);
	put(str, fd, num);
	free(str);
	return (0);
}
//separate the string betwen the \n
int	times_to_put_null(int	num)
{
	int	count = num / 16;

	count = count + 2;;
	if (num % 16 != 0)
		count++;
	count = count * 16;
	return (count);
	
}

int	print_comment(int i, char **str, int fd, char b)
{
	int	x;
	int	y = 0;
	int	num = 0;
	int	number;
	//b = 17;
	for (x = 0; str[i][x] != '"'; x++);
	for (y = x + 1; str[i][y] != '"' && str[i][y] != ' '; y++);
	y = y - x;
	for (x = x; str[i][x] != '"'; x++);
	for (y = y; y < 17; y++, num++)
		write(fd, &b, sizeof(char));
	for (x = x + 1; str[i][x] != '"'; x++) {
		write(fd, &str[i][x], sizeof(char));
		num++;
	}
	number = times_to_put_null(num);
	printf("number:%d\n", number);
	printf("numinprintcoment:%d\n", num);
	for (num = num, b = '\0'; num != number; num++)
		write(fd, &b, sizeof(char));
	printf("numinprintcoment:%d\n", num);
	return (0);
}

int	comment(int fd, char **str, int i)
{
	int	x;
	int	num = 4;
	char	b = '\0';
	int	number;

	for ((i) = 0; str[i][0] == '#'; i++);
	for (x = 0; str[i][x] != '"'; x++);
	for (x = x + 1; str[i][x] != '"'; x++, num++)
		write(fd, &str[i][x], sizeof(char));
	number = times_to_put_null(num);
	//printf("number:%d, num%d\n",number, num);
	for (num = num; num != number; num++)
		write(fd, &b, sizeof(char));
	print_comment(i + 1, str, fd, b);
	//printf("num:%d\n", num);
        
	return (0);
}

char	**get_str(char **str, char *av)
{
	int	num_ar = 0;
	char	**ptr;
	int	i;
	int	g;

	num_ar = num_arg(av, '\n');
	ptr = malloco(num_ar);
	for (i = 0; str[i] != NULL; i++) {
		for (g = 0; str[i][g] != '\0'; g++)
			ptr[i][g] = str[i][g];
		ptr[i][g] = '\0';
	}
	ptr[i] = NULL;
	free(str);
	return (ptr);
}
int     yolotron(char *av)
{
        char    **str;
        int     i = 0;
	int	fd;
	int	num = COREWAR_EXEC_MAGIC;
	char	**ptr;
	
        str = get_path_array(av, '\n');
	ptr = get_str(str, av);
        free(av);
	ptr[2][4] = '#';
	for (i = 0; ptr[i] != NULL; i++)
		printf("%s\n", ptr[i]);
	fd = open("example.dytecode", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (0);
	write(fd, &num, sizeof(int));
	i = comment(fd, ptr, i);
	put_comands(fd, ptr);
	close(fd);
        return (i);
}

char	*num_caracters(int size, int i, char *av)
{
	char    buff[1];
	char	*result;
	int	fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	for (size = read(fd, buff, 1); size > 0;
             size = read(fd, buff, 1))
		i++;
	close(fd);
	result = malloc(sizeof(char) * i + 2);
	return (result);
}
char    *get_file(char  *av)
{
        char    buff[1];
        char    *result;
        int     size = 0;
        int     i = 0;
	int	fd;

	result = num_caracters(size, i, av);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	for (size = read(fd, buff, 1); size > 0;
             size = read(fd, buff, 1)) {
                result[i] = buff[0];
                i++;
        }
	result[i] = '\0';
	close(fd);
        return (result);
}
