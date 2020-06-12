int indent1 (int ac, char **av);
int indent2 ( int ac, char ***av);	

int	main(int ac, char **av)
{
	indent1(ac, av);
	indent2(ac, &av);
}	
