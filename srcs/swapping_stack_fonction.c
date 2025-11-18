#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
void	swap(t_stack *stk)
{
	int	temp;

	temp = stk->top;
	stk->top = stk->bot;
	stk->bot = temp;
}
void	swap_b(t_build *data)
{
	swap(&data->b);
}

void	swap_a(t_build *data)
{
	swap(&data->a);
}


