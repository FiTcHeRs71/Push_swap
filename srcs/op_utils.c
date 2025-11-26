/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/11/2025 10:10:27 by fducrot           #+#    #+#             */
/*   Updated: 26/11/2025 10:06:42 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_value_at(t_stack *stk, int nb)
{
	int	i;

	i = stk->top;
	while (--nb > 0)
	{
		i = next_bot(stk, i);
	}
	return (stk->array[i]);
}

bool	array_is_full(t_stack *stk)
{
	return (current_size(stk) == stk->size);
}

int	current_size(t_stack *stk)
{
	if (stk->top == stk->bot && stk->array[stk->top] == 0)
	{
		return (0);
	}
	if (stk->top > stk->bot)
	{
		return ((stk->size - stk->top) + (stk->bot + 1));
	}
	else
	{
		return (stk->bot - stk->top + 1);
	}
}

int	next_top(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
	{
		return (index);
	}
	if (index == 0)
	{
		return (stk->size - 1);
	}
	else
	{
		return (index - 1);
	}
}

int	next_bot(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
	{
		return (index);
	}
	if (index == stk->size - 1)
	{
		return (0);
	}
	else
	{
		return (index + 1);
	}
}
