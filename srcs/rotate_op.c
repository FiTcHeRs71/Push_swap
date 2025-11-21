#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	rotate(t_stack *stk)
{
	stk->bot = next_bot(stk, stk->bot);
	stk->stack[stk->bot] = stk->stack[stk->top];
	stk->stack[stk->top] = 0;
	stk->top = next_bot(stk, stk->top);
}

void	rotate_a(t_build *data)
{
	rotate(&data->a);
	ft_printf("ra\n");
}

void	rotate_b(t_build *data)
{
	rotate(&data->b);
	ft_printf("rb\n");
}
void	rotate_a_b(t_build *data)
{
	rotate(&data->a);
	rotate(&data->b);
	ft_printf("rr\n");
}