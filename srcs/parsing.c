/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:13:29 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/27 09:14:36 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_parsing(t_build *data)
{
	if (data->a.size <= 1)
	{
		return ;
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
}

void	quick_three(t_build *data)
{
	int	first;
	int	second;
	int	third;

	first = get_value_at(&data->a, 1);
	second = get_value_at(&data->a, 2);
	third = get_value_at(&data->a, 3);
	if (first > second && third > second && third > first)
		swap_a(data);
	else if (first > second && first > third && second < third)
		rotate_a(data);
	else if (first < second && first > third && second > third)
		reverse_rotate_a(data);
	else if (first < second && first < third && second > third)
	{
		swap_a(data);
		rotate_a(data);
	}
	else if (first > second && first > third && second > third)
	{
		swap_a(data);
		reverse_rotate_a(data);
	}
}

void	quick_five(t_build *data)
{
	while (current_size(&data->a) > 3)
	{
		if (get_value_at(&data->a, 1) == 1 || get_value_at(&data->a, 1) == 2)
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
	if (get_value_at(&data->a, 1) == 2)
	{
		swap_a(data);
	}
}
