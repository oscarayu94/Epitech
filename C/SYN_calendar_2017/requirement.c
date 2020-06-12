/*
** EPITECH PROJECT, 2018
** requirement
** File description:
** requirement
*/

#include <stdlib.h>

typedef struct list
{
	void	*data;
	struct list	*next;
}t_list;

int	my_revlist_synthesis(t_list **begin)
{

	t_list	*tmp;
	t_list	*actual;
	t_list	*next;

	tmp = NULL;
	next = NULL;
	if (begin != NULL)
		actual = *begin;
	while (actual)
	{
		next = actual->next;
		actual->next = tmp;
		tmp = actual;
		actual = next;
	}
	*begin = tmp;
	return (0);
}

t_list	*my_findnodeeqinlist_synthesis(t_list *begin, void *data_ref, 
				       int (*cmp) (void*, void *))
{
	while (begin != NULL) {
		if (cmp(begin->data, data_ref) == 0)
			return (begin);
		begin = begin->next;
	}
	return (begin);
}	
