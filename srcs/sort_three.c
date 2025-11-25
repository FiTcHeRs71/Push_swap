#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	sort_three(t_build *data, t_chunck *to_chunck)
{
	t_stack	*stk;
	int		max;

	stk = loc_to_stack(data, to_chunck->loc);
	max = setup_max_size(data, to_chunck);
	if (to_chunck->loc == TOP_A)
	{
		process_three_top_a(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == BOT_A)
	{
		process_three_bot_a(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == TOP_B)
	{
		process_three_top_b(data, to_chunck, stk, max);
	}
	else if (to_chunck->loc == BOT_B)
	{
		process_three_bot_b(data, to_chunck, stk, max);
	}
}

void	process_three_top_a(t_build *data, t_chunck *to_chunck, t_stack *stk, int max)
{
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stk->stack[next_bot(stk, stk->top)] == max)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}

void	process_three_top_b(t_build *data, t_chunck *to_chunck, t_stack *stk, int max)
{
	push_a(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		swap_a(data);
	}
	else if (stk->stack[next_bot(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		swap_a(data);
	}
	else
	{
		push_a(data);
	}
	push_a(data);
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);

}

void	process_three_bot_a(t_build *data, t_chunck *to_chunck, t_stack *stk, int max)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	if (stk->stack[stk->top] == max)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if (stk->stack[next_bot(stk, stk->top)] == max)
	{
		reverse_rotate_a(data);
	}
	else
	{
		push_b(data);
		reverse_rotate_a(data);
		swap_a(data);
		push_a(data);
	}
	to_chunck->loc = TOP_A;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}

void	process_three_bot_b(t_build *data, t_chunck *to_chunck, t_stack *stk, int max)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	if (stk->stack[stk->top] == max)
	{
		push_a(data);
		reverse_rotate_b(data);
	}
	else if (stk->stack[next_bot(stk, stk->top)] == max)
	{
		swap_b(data);
		push_a(data);
		reverse_rotate_b(data);
	}
	else
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	to_chunck->loc = TOP_B;
	to_chunck->size -= 1;
	sort_two(data, to_chunck);
}
