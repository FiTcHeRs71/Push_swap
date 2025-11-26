#include "../include/checker_bonus.h"

bool	exec_push(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 3))
	{
		push_a(data);
	}
	else if (ft_strncmp(cmd, "pb", 3))
	{
		push_b(data);
	}
	else 
	{
		return (false);
	}
	return (true);
}

bool	exec_reverse_rotate(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "rra", 4))
	{
		reverse_rotate_a(data);
	}
	else if (ft_strncmp(cmd, "rrb", 4))
	{
		reverse_rotate_b(data);
	}
	else if (ft_strncmp(cmd, "rrr", 4))
	{
		reverse_rotate_a_b(data);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	exec_rotate(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "ra", 3))
	{
		rotate_a(data);
	}
	else if (ft_strncmp(cmd, "rb", 3))
	{
		rotate_b(data);
	}
	else if (ft_strncmp(cmd, "rr", 3))
	{
		rotate_a_b(data);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	exec_swap(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 3))
	{
		swap_a(data);
	}
	else if (ft_strncmp(cmd, "sb", 3))
	{
		swap_b(data);
	}
	else if ((ft_strncmp(cmd, "ss", 3)))
	{
		swap_a_b(data);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	execute_instruction(t_build *data, char *cmd)
{
	if (exec_swap(data, cmd))
	{
		return (true);
	}
	if (exec_rotate(data, cmd))
	{
		return (true);
	}
	if (exec_reverse_rotate(data, cmd))
	{
		return (true);
	}
	if (exec_push(data, cmd))
	{
		return (true);
	}
	return (false);
}