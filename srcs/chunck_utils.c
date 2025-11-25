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
	if (loc == TOP_A || loc == BOT_A)
	{
		return (&data->a);
	}
	else
	{
		return (&data->b);
	}
}

void	define_new_top(t_build *data, t_chunck *to_chunck)
{
	if (to_chunck->loc == BOT_B && current_size(&data->b) == to_chunck->size)
	{
		to_chunck->loc = TOP_B;
	}
		if (to_chunck->loc == BOT_A && current_size(&data->a) == to_chunck->size)
	{
		to_chunck->loc = TOP_A;
	}
}

/*int	chunck_max_value(t_build *data, t_chunck *chunck)
{
	t_stack	*stk;
	int		size;
	int		max;
	int		i;

	stk = loc_to_stack(data, chunck->loc);
	size = chunck->size;
	max = 0;
	if (chunck->loc == TOP_A || chunck->loc == TOP_B)
	{
		i = stk->top;
	}
	else if (chunck->loc == BOT_A || chunck->loc == BOT_B)
	{
		i = stk->bot;
	}
	while (size--)
	{
		if (stk->stack[i] > max)
			max = stk->stack[i];
		if (chunck->loc == TOP_A || chunck->loc == TOP_B)
		{
			i = next_down(stk, i);
		}
		else if (chunck->loc == BOT_A || chunck->loc == BOT_B)
		{
			i = next_up(stk, i);
		}
	}
	return (max);
}*/

int	setup_max_size(t_build *data, t_chunck *chunck)
{
	t_stack	*stk;
	int		size;
	int		max;
	int		i;

	stk = loc_to_stack(data, chunck->loc);
	size = chunck->size;
	max = 0;
	if (chunck->loc == TOP_A || chunck->loc == TOP_B)
	{
		i = stk->top;
	}
	else if (chunck->loc == BOT_A || chunck->loc == BOT_B)
	{
		i = stk->bot;
	}
	while (size--)
	{
		if (stk->stack[i] > max)
		{
			max = stk->stack[i];
		}
		if (chunck->loc == TOP_A || chunck->loc == TOP_B)
		{
			i = next_bot(stk, i);
		}
		else if(chunck->loc == BOT_A || chunck->loc == BOT_B)
		{
			i = next_top(stk, i);
		}
	}
	return (max);
}

int	chunck_the_value(t_build *data, t_chunck *chunck, int n)
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
