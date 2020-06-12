/*
** EPITECH PROJECT, 2018
** next_line
** File description:
** Bootstrap next line
*/


char	*read_next_n_bytes(int fd, int n)
{
	int	size;
	char	*BUFFER;
	
	BUFFER = malloc(sizeof(char)*n);
	size = read(fd, BUFFER, n);

}

int main()
{
	int	fd;
	fd = open("namefile", O_RDONLY);
	read_next_n_bites(fd, 5);
}
	
