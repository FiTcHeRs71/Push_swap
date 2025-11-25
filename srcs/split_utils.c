#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

void	max_update_adjust(t_build *data, t_chunck *high)
{
	t_stack	*stk_a;
	
	stk_a = &data->a;
	if (high->loc == TOP_A && high->size == 3 && check_consecutive(set_up_value(stk_a, 1), set_up_value(stk_a, 2), set_up_value(stk_a, 3), set_up_value(stk_a, 4)) && checking_is_already_sort(data, 4))
	{
		sort_three(data, high);
		return;
	}
	if (high->loc == TOP_A && set_up_value(stk_a, 1) == set_up_value(stk_a, 3) - 1 && checking_is_already_sort(data, 3))
	{
		swap_a(data);
		high->size--;
	}
	if (high->loc == TOP_A && checking_is_already_sort(data, 1))
	{
		high->size--;
	}
}

bool	checking_is_already_sort(t_build *data, int start)
{
	int		i;
	int		value;
	t_stack *stk_a;

	stk_a = &data->a;
	i = stk_a->top;
	while (--start)
	{
		i = next_bot(stk_a, i);
	}
	while (stk_a->stack[i] != data->a.size)
	{
		value = stk_a->stack[i];
		i = next_bot(stk_a, i);
		if (stk_a->stack[i] !=  value + 1)
		{
			return (false);
		}
	}
	return (true);
}

bool	check_consecutive(int a, int b, int c, int d)
{
	swap_three_numbers(&a, &b, &c);
	return ((b - a == 1) && (c - b == 1) && (d - c == 1));
}

void	swap_three_numbers(int *a, int *b, int *c)
{
	int	temp;

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}
	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}
}