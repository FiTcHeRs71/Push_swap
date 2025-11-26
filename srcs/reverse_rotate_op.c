/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fducrot <fducrot@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:24:48 by fducrot           #+#    #+#             */
/*   Updated: 2025/11/26 10:24:48 by fducrot          ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack *stk)
{
	int	temp;

	temp = stk->array[stk->bot];
	stk->array[stk->bot] = 0;
	stk->bot = next_top(stk, stk->bot);
	stk->top = next_top(stk, stk->top);
	stk->array[stk->top] = temp;
}

void	reverse_rotate_a(t_build *data)
{
	reverse_rotate(&data->a);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_build *data)
{
	reverse_rotate(&data->b);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_b(t_build *data)
{
	reverse_rotate(&data->a);
	reverse_rotate(&data->b);
	ft_printf("rrr\n");
}
