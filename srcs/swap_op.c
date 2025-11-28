/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 13:31:55 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/28 13:32:59 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap(t_stack *stk)
{
	int	temp;

	temp = stk->array[next_bot(stk, stk->top)];
	stk->array[next_bot(stk, stk->top)] = stk->array[stk->top];
	stk->array[stk->top] = temp;
}

void	swap_b(t_build *data)
{
	swap(&data->b);
	ft_printf("sb\n");
}

void	swap_a(t_build *data)
{
	swap(&data->a);
	ft_printf("sa\n");
}

void	swap_a_b(t_build *data)
{
	swap(&data->a);
	swap(&data->b);
	ft_printf("ss\n");
}
