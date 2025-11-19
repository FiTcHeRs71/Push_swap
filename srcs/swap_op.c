#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	swap(t_stack *stk)
{
	int	temp;

	temp = stk->stack[stk->top];
	stk->stack[stk->top] = stk->stack[next_top_free(stk, stk->top)];
	stk->stack[next_top_free(stk, stk->top)] = temp;
}
void	swap_b(t_build *data)
{
	swap(&data->b);
	ft_printf("sb\n");
}

void	swap_a(t_build *data)
{
	swap(&data->a);
	ft_printf("sa\n");
}

void	swap_a_b(t_build *data)
{
	swap(&data->a);
	swap(&data->b);
	ft_printf("ss\n");
}

//checker si a ou b empty