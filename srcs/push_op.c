/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 19/11/2025 13:10:02 by fducrot           #+#    #+#             */
/*   Updated: 26/11/2025 10:08:21 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_idx;

	dest_idx = next_top(dest, dest->top);
	dest->array[dest_idx] = src->array[src->top];
	dest->top = dest_idx;
	src->array[src->top] = 0;
	src->top = next_bot(src, src->top);
}

void	push_a(t_build *data)
{
	push(&data->b, &data->a);
	ft_printf("pa\n");
}

void	push_b(t_build *data)
{
	push(&data->a, &data->b);
	ft_printf("pb\n");
}
