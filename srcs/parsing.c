
#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

void	ft_parsing(t_build *data)
{
	if (data->a.size <= 1)
	{
		return;
	}
	else if (data->a.size == 3)
	{
		quick_three(data);
	}
}

void	quick_three(t_build *data)
{
	
}