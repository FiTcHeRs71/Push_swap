#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"


void	chunck_stack(t_build *data)
{
	t_chunck all_chunck;

	all_chunck.loc = TOP_A;
	all_chunck.size = data->a.size;
	go_to_chunck(data, &all_chunck);
}

void	go_to_chunck(t_build *data, t_chunck *to_chunck)
{
	t_bucket	dest;

	
}