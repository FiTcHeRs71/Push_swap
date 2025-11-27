#include "../include/checker_bonus.h"

bool	exec_push(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "pa", 3) == 0)
	{
		push(&data->b, &data->a);
	}
	else if (ft_strncmp(cmd, "pb", 3) == 0)
	{
		push(&data->a, &data->b);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	exec_reverse_rotate(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "rra", 4) == 0)
	{
		reverse_rotate(&data->a);
	}
	else if (ft_strncmp(cmd, "rrb", 4) == 0)
	{
		reverse_rotate(&data->b);
	}
	else if (ft_strncmp(cmd, "rrr", 4) == 0)
	{
		reverse_rotate(&data->a);
		reverse_rotate(&data->b);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	exec_rotate(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "ra", 3) == 0)
	{
		rotate(&data->a);
	}
	else if (ft_strncmp(cmd, "rb", 3) == 0)
	{
		rotate(&data->b);
	}
	else if (ft_strncmp(cmd, "rr", 3) == 0)
	{
		rotate(&data->a);
		rotate(&data->b);
	}
	else
	{
		return (false);
	}
	return (true);
}

bool	exec_swap(t_build *data, char *cmd)
{
	if (ft_strncmp(cmd, "sa", 3) == 0)
	{
		swap(&data->a);
	}
	else if (ft_strncmp(cmd, "sb", 3) == 0)
	{
		swap(&data->b);
	}
	else if ((ft_strncmp(cmd, "ss", 3)) == 0)
	{
		swap(&data->a);
		swap(&data->b);
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