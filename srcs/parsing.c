
#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"

void	ft_parsing(t_build *data)
{
	if (data->a.size <= 1)
	{
		return;
	}
	else if (data->a.size == 3)
	{
		quick_three(data);
	}
	else if (data->a.size == 5)
	{
		quick_five(data);
	}
	else
	{
		chunck_stack(data);
	}
	print_stack(&data->a);
}

void	quick_three(t_build *data)
{
	int	first;
	int	second;
	int	third;

	first = set_up_value(&data->a, 1);
	second = set_up_value(&data->a, 2);
	third = set_up_value(&data->a, 3);
	if (first > second && third > second && third > first) // 2 1 3
	{
		swap_a(data);
	}
	else if (first > second && first > third && second < third) // 3 1 2
	{
		rotate_a(data);
	}
	else if (first < second && first > third && second > third) // 2 3 1
	{
		reverse_rotate_a(data);
	}
	else if (first < second && first < third && second > third) // 1 3 2
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first > second && first > third && second > third) // 3 2 1
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
}

void	quick_five(t_build *data)
{
	while (current_size(&data->a) > 3)
	{
		if (set_up_value(&data->a, 1) == 1 || set_up_value(&data->a, 1) == 2)
		{
			push_b(data);
		}
		else
		{
			rotate_a(data);
		}
	}
	quick_three(data);
	push_a(data);
	push_a(data);
	if (set_up_value(&data->a, 1) == 2)
	{
		swap_a(data);
	}
}
