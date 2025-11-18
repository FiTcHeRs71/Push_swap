
#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

void	free_node(t_build *data)
{
	if (data->a.stack)
	{
		free (data->a.stack);
	}
	if (data->b.stack)
	{
		free (data->b.stack);
	}
}

void	ft_error(t_build *data)
{
	free_node(data);
	exit(EXIT_FAILURE);
}
