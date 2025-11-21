#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	reverse_rotate(t_stack *stk)
{

	stk->top = next_top(stk, stk->top);
	stk->stack[stk->top] = stk->stack[stk->bot];
	stk->stack[stk->bot] = 0;
	stk->bot = next_top(stk, stk->bot);
}

void	reverse_rotate_a(t_build *data)
{
	reverse_rotate(&data->a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_build *data)
{
	reverse_rotate(&data->b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_build *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	ft_printf("rrr\n");
}