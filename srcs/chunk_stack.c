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

	define_new_top(data, to_chunck);
	check_quick_sort(data, to_chunck);
	if (to_chunck->size <= 3)
	{
		if (to_chunck->size == 3)
		{
			sort_three(data, to_chunck);
		}
		else if (to_chunck->size == 2)
		{
			sort_two(data, to_chunck);
		}
		else if (to_chunck->size == 1)
		{
			sort_one(data,to_chunck);
		}
		return;
	}
	split_chunk(data, to_chunck, &dest);
	go_to_chunck(data, &dest.high);
	go_to_chunck(data, &dest.mid);
	go_to_chunck(data, &dest.low);
}
void	sort_one(t_build *data, t_chunck *to_chunck)
{
	if (to_chunck->loc == BOT_A || to_chunck->loc == BOT_B || to_chunck->loc == TOP_B)
	{
		change_stack(data, to_chunck->loc, TOP_A);
	}
	to_chunck->size -= 1;
}

void	sort_two(t_build *data, t_chunck *to_chunck)
{
	if (to_chunck->loc == BOT_A || to_chunck->loc == BOT_B || to_chunck->loc == TOP_B)
	{
		change_stack(data, to_chunck->loc, TOP_A);
		change_stack(data, to_chunck->loc, TOP_A);
	}
	if (set_up_value(&data->a, 1) > set_up_value(&data->a, 2))
	{
		swap_a(data);
	}
	to_chunck->size -= 2;
}