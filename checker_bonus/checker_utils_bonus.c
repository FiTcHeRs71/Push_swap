#include "../include/checker_bonus.h"

bool	is_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while(i > stk->size) // + 1?
	{
		if (stk->array[i] > stk->array[i])
		{
			return (false);
		}
		i++;
	}
	return (true);
}