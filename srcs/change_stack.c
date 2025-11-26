#include "../include/stack.h"
#include "../include/push_swap.h"
#include "../libft/include/libft.h"
#include "../libft/include/ft_printf.h"

int	change_stack(t_build *data, t_loc src, t_loc dest)
{
	if (src == TOP_A)
	{
		move_from_top_a(data, dest);
	}
	else if (src == TOP_B)
	{
		move_from_top_b(data, dest);
	}
	else if (src == BOT_A)
	{
		move_from_bottom_a(data, dest);
	}
	else if (src == BOT_B)
	{
		move_from_bottom_b(data, dest);
	}
	return (1);
}

void	move_from_top_a(t_build *data, t_loc dest)
{
	if (dest == TOP_B)
	{
		push_b(data);
	}
	else if (dest == BOT_A)
	{
		rotate_a(data);
	}
	else if (dest == BOT_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_build *data, t_loc dest)
{
	if (dest == TOP_A)
	{
		push_a(data);
	}
	else if (dest == BOT_B)
	{
		rotate_b(data);
	}
	else if (dest == BOT_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_build *data, t_loc dest)
{
	if (dest == TOP_A)
	{
		reverse_rotate_a(data);
	}
	else if (dest == TOP_B)
	{
		reverse_rotate_a(data);
		push_b(data);
	}
	else if (dest == BOT_B)
	{
		reverse_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_build *data, t_loc dest)
{
	if (dest == TOP_B)
	{
		reverse_rotate_b(data);
	}
	else if (dest == TOP_A)
	{
		reverse_rotate_b(data);
		push_a(data);
	}
	else if (dest == BOT_A)
	{
		reverse_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
