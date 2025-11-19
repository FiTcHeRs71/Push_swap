#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

int	current_size(t_stack *stk)
{
	if (stk->top == stk->bot && stk->stack[stk->top] == 0)
	{
		return (0);
	}
	if (stk->top > stk->bot)
	{
		return ((stk->size - stk->top) + (stk->bot + 1));
	}
	else
	{
		return (stk->bot - stk->top + 1);
	}
}

int	next_top_free(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
	{
		return (index);
	}
	if (index == 0)
	{
		return (stk->size - 1);
	}
	else
	{
		return (index - 1);
	}
}

int	next_bot_free(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
	{
		return (index);
	}
	if (index == stk->size - 1)
	{
		return (0);
	}
	else
	{
		return (index + 1);
	}
}

