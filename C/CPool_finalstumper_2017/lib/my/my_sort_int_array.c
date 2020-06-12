/*
** EPITECH PROJECT, 2017
** emacs
** File description:
** task06
*/
void my_sort_int_array(int *array, int size)
{
	int	tmp;
	int	i;
	int	y; 
	i = 0;
	y = 0;
	while(y < size)
	{
		i = 0;
		while(i < size-1)
		{
	        	if (array[i] > array[i+1])
			{
				tmp = array[i];
				array[i] = array[i+1];
				array[i+1] = tmp;
			}
			i++;	
		}
		y++;
	}
}
