#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

int	chunck_value(t_build *data, t_chunck *chunck, int n)
{
	t_loc	loc;
	t_stack	*stk;
	int		i;

	loc = chunck->loc;
	stk = loc_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
	{
		i = stk->top;
		while (--n > 0)
		{
			i = next_bot(stk, i);
		}
	}
	else if (loc == BOT_A || loc == BOT_B)
	{
		i = stk->bot;
		while (--n > 0)
		{
			i = next_top(stk, i);
		}
	}
	return (stk->stack[i]);
}

t_stack	*loc_to_stack(t_build *data, t_loc loc)
{
	if (loc == TOP_A || loc == BOT_B)
	{
		return (&data->a);
	}
	else
	{
		return (&data->b);
	}
}