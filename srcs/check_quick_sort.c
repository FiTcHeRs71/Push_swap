#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	check_quick_sort(t_build *data, t_chunck *to_chunck)
{
	while (to_chunck->loc != TOP_A && to_chunck->size)
	{
		if (set_up_value(&data->a, 1) == chunck_value(data, to_chunck, 1) + 1
			&& to_chunck->size > 0)
			{
				sort_one(data, to_chunck);
			}
		else if (set_up_value(&data->a, 1) == chunck_value(data, to_chunck, 2) + 1
			&& to_chunck->size > 1)
			{
				quick_sort_second(data, to_chunck);
			}
		else	
		{
			break;
		}
	}
}

void	quick_sort_second(t_build *data, t_chunck *to_chunck)
{
	if (to_chunck->loc == TOP_B)
	{
		process_top_b(data, to_chunck);
	}
	else if (to_chunck->loc == BOT_A)
	{
		process_bot_a(data, to_chunck);
	}
	else if (to_chunck->loc == BOT_B)
	{
		process_bot_b(data, to_chunck);
	}
	to_chunck->size--;
}

void	process_top_b(t_build *data, t_chunck *to_chunck)
{
	swap_b(data);
	push_a(data);
	if (set_up_value(&data->b, 1) == set_up_value(&data->a, 1) - 1)
	{
		push_a(data);
		to_chunck->size--;
	}
}

void	process_bot_a(t_build *data, t_chunck *to_chunck)
{
	reverse_rotate_a(data);
	reverse_rotate_a(data);
	swap_a(data);
	if (set_up_value(&data->a, 1) == set_up_value(&data->a, 2) - 1)
	{
		to_chunck->size--;
	}
	else
	{
		rotate_a(data);
	}
}

void	process_bot_b(t_build *data, t_chunck *to_chunck)
{
	reverse_rotate_b(data);
	reverse_rotate_b(data);
	push_a(data);
	if (set_up_value(&data->b, 1) == set_up_value(&data->a, 1) - 1)
	{
		push_a(data);
		to_chunck->size--;
	}
	else
	{
		rotate_b(data);
	}
}