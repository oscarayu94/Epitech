/*
** EPITECH PROJECT, 2018
** pipe
** File description:
** Does the same function of a pipe, provided the path is given and stuff
*/

char	**read(char **tab)
{
	int	pipefd[2];
	pid_t	pid;
	char	buffer[13];

	pipe(pipefd);
	pid = fork();

	if (pid == 0)
	{
		close(pipefd[0]);
		write(
	}	
}	

int	main(int ac, char **av)
{
	if (ac < 3)
		exit(84);
	else
		reader(av);
}
