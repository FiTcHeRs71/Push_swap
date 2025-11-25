#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	split_chunk(t_build *data, t_chunck *to_chunck, t_bucket *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max;
	int	next;

	init_size(&dest->low, &dest->mid, &dest->high);
	setup_loc_split(to_chunck->loc, &dest->low, &dest->mid, &dest->high);
	setup_pivots(to_chunck->loc, to_chunck->size, &pivot_1, &pivot_2);
	max = setup_max_size(data, to_chunck);
	while (to_chunck->size--)
	{
		next = chunck_the_value(data, to_chunck, 1);
		if (next > max - pivot_2)
		{
			dest->high.size += change_stack(data, to_chunck->loc, dest->high.loc);
		}
		else if (next > max - pivot_1)
		{
			dest->mid.size += change_stack(data,to_chunck->loc, dest->mid.loc);
		}
		else
		{
			dest->low.size += change_stack(data, to_chunck->loc, dest->low.loc);
		}
	}

}

void	init_size(t_chunck *low, t_chunck *mid, t_chunck *high)
{
	low->size = 0;
	mid->size = 0;
	high->size = 0;
}

void	setup_loc_split(t_loc loc, t_chunck *low, t_chunck *mid, t_chunck *high)
{
	if (loc == TOP_A)
	{
		low->loc = BOT_B;
		mid->loc = TOP_B;
		high->loc = BOT_A;
	}
	else if (loc == BOT_A)
	{
		low->loc = BOT_B;
		mid->loc = TOP_B;
		high->loc = TOP_A;
	}
	else if (loc == TOP_B)
	{
		low->loc = BOT_B;
		mid->loc = BOT_A;
		high->loc = TOP_A;
	}
	else if ( loc == BOT_B)
	{
		low->loc = TOP_B;
		mid->loc = BOT_A;
		high->loc = TOP_A;
	}
}

void	setup_pivots(t_loc loc, int max_size, int *pivot_1, int *pivot_2)
{
	*pivot_2 = max_size / 3;
	if (loc == TOP_A || loc == BOT_A)
	{
		*pivot_1 = 2 * max_size / 3;
	}
	if (loc == TOP_B || loc == BOT_B)
	{
		*pivot_1 = max_size / 2;
	}
}
